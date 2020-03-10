/*! \example tutorial-ibvs-4pts-display.cpp
Il seguente esempio disponibile in tutorial-ibvs-4pts.cpp mostra come usare ViSP
per implementare una simulazione IBVS usando 4 punti come funzionalità visive.
*/

#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpProjectionDisplay.h>
#include <visp3/robot/vpSimulatorCamera.h>
#include <visp3/visual_features/vpFeatureBuilder.h>
#include <visp3/vs/vpServo.h>
#include <visp3/vs/vpServoDisplay.h>

/* In secondo luogo, introduciamo la funzione display_trajectory () che consente di visualizzare la
traiettoria delle caratteristiche correnti nell'immagine. Dalle coordinate 3D dei punti indicati nella
cornice dell'oggetto, calcoliamo la rispettiva posizione nella cornice della videocamera, quindi applichiamo
la proiezione prospettica prima di recuperare le loro posizioni in sotto-pixel nell'immagine grazie ai
parametri della videocamera. Le successive posizioni dei sub-pixel sono memorizzate in un vettore chiamato
traj e visualizzate come una traiettoria verde. */

void display_trajectory(const vpImage<unsigned char> &I, std::vector<vpPoint> &point, const vpHomogeneousMatrix &cMo,
                        const vpCameraParameters &cam);

void display_trajectory(const vpImage<unsigned char> &I, std::vector<vpPoint> &point, const vpHomogeneousMatrix &cMo,
                        const vpCameraParameters &cam)
{
  static std::vector<vpImagePoint> traj[4];
  vpImagePoint cog;
  for (unsigned int i = 0; i < 4; i++) {
    // Project the point at the given camera position
    point[i].project(cMo);
    vpMeterPixelConversion::convertPoint(cam, point[i].get_x(), point[i].get_y(), cog);
    traj[i].push_back(cog);
  }
  for (unsigned int i = 0; i < 4; i++) {
    for (unsigned int j = 1; j < traj[i].size(); j++) {
      vpDisplay::displayLine(I, traj[i][j - 1], traj[i][j], vpColor::green);
    }
  }
}



int main()
{
  try {
    /* Quindi nella funzione main (), definiamo la posizione desiderata e iniziale della telecamera come due matrici omogenee;
    cdMo si riferisce a $ {^ c} ^ * {\ bf M} _o $ e cMo a $ {^ c} {\ bf M} _o $. */
    vpHomogeneousMatrix cdMo(0, 0, 0.75, 0, 0, 0);
    vpHomogeneousMatrix cMo(0.15, -0.1, 1., vpMath::rad(10), vpMath::rad(-10), vpMath::rad(50));

    // Quindi definiamo quattro punti 3D che rappresentano gli angoli di un quadrato di 20 cm per 20 cm.
    std::vector<vpPoint> point;
    point.push_back(vpPoint(-0.1, -0.1, 0));
    point.push_back(vpPoint(0.1, -0.1, 0));
    point.push_back(vpPoint(0.1, 0.1, 0));
    point.push_back(vpPoint(-0.1, 0.1, 0));

    /* L'istanza del task servo visivo viene eseguita con le righe successive.
    Inizializziamo l'attività come un servocomando visivo a portata di mano.
    Le velocità risultanti calcolate dal controller sono quelle che dovrebbero essere applicate
    nel frame della telecamera: $ {\ bf v} _c $. La matrice di interazione verrà calcolata
    dalle attuali caratteristiche visive. Pertanto, devono essere aggiornati ad ogni iterazione
    del ciclo di controllo. Infine, il guadagno costante $ \ lambda $ è impostato su 0,5. */
    vpServo task;
    task.setServo(vpServo::EYEINHAND_CAMERA);
    task.setInteractionMatrixType(vpServo::CURRENT);
    task.setLambda(0.5);

    /* Ora è il momento di definire quattro caratteristiche visive come punti nel piano dell'immagine.
    A tal fine istanziamo la classe vpFeaturePoint. La funzione punto corrente $ {\ bf s} $ è implementata
    in p [i]. La funzione di punto desiderata $ {\ bf s} ^ * $ è implementata in pd [i].*/
    vpFeaturePoint p[4], pd[4];
    /* Ogni funzione viene ottenuta calcolando la posizione dei punti 3D nella cornice della telecamera corrispondente,
    quindi applicando la proiezione prospettica. Una volta create le funzionalità correnti e desiderate,
    vengono aggiunte all'attività servo visivo. */
    for (unsigned int i = 0; i < 4; i++) {
      point[i].track(cdMo);
      vpFeatureBuilder::create(pd[i], point[i]);
      point[i].track(cMo);
      vpFeatureBuilder::create(p[i], point[i]);
      task.addFeature(p[i], pd[i]);
    }
    // Per la simulazione dobbiamo prima creare due trasformazioni omogenee wMc e wMo,
    // rispettivamente per definire la posizione della telecamera e la posizione dell'oggetto nella cornice del mondo.
    vpHomogeneousMatrix wMc, wMo;
    /* In secondo luogo. creiamo un'istanza della nostra macchina fotografica volante libera.
    Qui specifichiamo anche il tempo di campionamento a 0,040 secondi. Quando viene applicata
    una velocità alla telecamera, questa volta verrà utilizzata dalla mappa esponenziale per
    determinare la posizione successiva della telecamera. */
    vpSimulatorCamera robot;
    robot.setSamplingTime(0.040);
    /* Infine, dalla posizione iniziale wMc della telecamera e dalla posizione dell'oggetto
    precedentemente fissata nel frame della telecamera cMo, calcoliamo la posizione dell'oggetto
    nel frame mondiale wMo. Poiché nella nostra simulazione l'oggetto è statico, wMo rimarrà invariato. */
    robot.getPosition(wMc);
    wMo = wMc * cMo;

    /* Entriamo quindi nel main () dove creiamo due immagini che verranno visualizzate in una finestra.
    Le prime immagini di Iint sono dedicate alla vista della telecamera interna. Mostra il contenuto
    delle immagini viste dalla telecamera simulata. La seconda immagine Iext corrisponde alle immagini
    viste da una telecamera esterna che osserva la telecamera simulata. */
    vpImage<unsigned char> Iint(480, 640, 255);
    vpImage<unsigned char> Iext(480, 640, 255);
#if defined(VISP_HAVE_X11)
    vpDisplayX displayInt(Iint, 0, 0, "Internal view");
    vpDisplayX displayExt(Iext, 670, 0, "External view");
#elif defined(VISP_HAVE_GDI)
    vpDisplayGDI displayInt(Iint, 0, 0, "Internal view");
    vpDisplayGDI displayExt(Iext, 670, 0, "External view");
#elif defined(VISP_HAVE_OPENCV)
    vpDisplayOpenCV displayInt(Iint, 0, 0, "Internal view");
    vpDisplayOpenCV displayExt(Iext, 670, 0, "External view");
#else
    std::cout << "No image viewer is available..." << std::endl;
#endif

  /* Creiamo un'istanza della classe vpProjectionDisplay.
  Questa classe è disponibile solo se è installato almeno uno dei display (X11, GDI, OpenCV, GTK, D3D9).
  Ecco perché utilizziamo la macro VISP_HAVE_DISPLAY. Inseriamo quindi i punti utilizzati per definire
  il target. Successivamente, le coordinate 3D di questi punti definiti nella cornice dell'oggetto
  verranno utilizzate e proiettate in Iext. */
#if defined(VISP_HAVE_DISPLAY)
    vpProjectionDisplay externalview;
    for (unsigned int i = 0; i < 4; i++)
      externalview.insert(point[i]);
#endif
  /* Inizializziamo i parametri intrinseci della telecamera utilizzati in display_trajectory ()
  per determinare le posizioni in pixel nell'immagine delle caratteristiche visive. */
    vpCameraParameters cam(840, 840, Iint.getWidth() / 2, Iint.getHeight() / 2);
  /* Impostiamo anche la posizione della telecamera esterna che osserverà l'evoluzione della telecamera simulata durante il servo. */
    vpHomogeneousMatrix cextMo(0, 0, 3, 0, 0, 0);

    while (1) {
      robot.getPosition(wMc);
      cMo = wMc.inverse() * wMo;
      for (unsigned int i = 0; i < 4; i++) {
        point[i].track(cMo);
        vpFeatureBuilder::create(p[i], point[i]);
      }
      vpColVector v = task.computeControlLaw();
      robot.setVelocity(vpRobot::CAMERA_FRAME, v);

      /* Infine, ad ogni iterazione del servo loop aggiorniamo i visualizzatori: */
      vpDisplay::display(Iint);
      vpDisplay::display(Iext);
      display_trajectory(Iint, point, cMo, cam);

      vpServoDisplay::display(task, cam, Iint, vpColor::green, vpColor::red);
#if defined(VISP_HAVE_DISPLAY)
      externalview.display(Iext, cextMo, cMo, cam, vpColor::red, true);
#endif
      vpDisplay::flush(Iint);
      vpDisplay::flush(Iext);

      // A click to exit
      if (vpDisplay::getClick(Iint, false) || vpDisplay::getClick(Iext, false))
        break;

      vpTime::wait(robot.getSamplingTime() * 1000);
    }
    task.kill();
  } catch (const vpException &e) {
    std::cout << "Catch an exception: " << e << std::endl;
  }
}
