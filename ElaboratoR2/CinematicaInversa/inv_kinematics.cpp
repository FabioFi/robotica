#define _USE_MATH_DEFINES
//#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#include <limits>

//gcc kinematics.cpp -lm
//g++ kinematics.cpp

#define PI 3.14

int main(){

  double px = 0.2;
  double py = 0.2;
  double pz = 0.2;
  double ny = 0.0;

  double li = 0.3;
  double lo = 0.3;
  double l4 = 0.5;
  double a1 = 0.3;
  double a2 = 0.3;
  double d1 = 0.4;
  double d4 = 0.5;

  double theta1 = 0;
  double theta2 = 0;
  double theta2bis = 0;
  double q3 = 0;
  double theta4 = 0;

  //-----------------------------------------------------------------------------
  double temp = (px*px + py*py - a1*a1 - a2*a2)/(2*a1*a2);
  theta2 = 1/cos(temp/*(px*px + py*py - a1*a1 - a2*a2)/(2*a1*a2)*/);
  //theta2 = 0;
  //theta2bis = -acos((px*px + py*py - a1*a1 - a2*a2)/(2*a1*a2));

  double s2 = sin(theta2);
  double c2 = cos(theta2);
  theta1 = atan2(a2*s2*px + (a1 + a2*c2)*py, (a1 + a2*c2)*px - a2*s2*py);

  q3 = d1-d4-pz;

  theta4 = -atan2(ny, 0) + theta1 - theta2;

  //cout << fixed << "temp: " << temp << endl;
  cout << fixed << "theta1: " << theta1 << endl;
  cout << fixed << "theta2: " << theta2 << endl;
  //cout << fixed << "theta2bis: " << theta2bis << endl;
  cout << fixed << "q3: " << q3 << endl;
  cout << fixed << "theta4: " << theta4 << endl;

  //printf("Theta2: %f\n", theta2);

  return 0;

}
