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

  double d1 = 0;
  double d4 = 0;

  double t1 = 0.0; //0.0 1.57 -2.5 2.5
  double t2 = 0.0; //0.0 -1.57 -2.0 2.0
  double t3 = 0.0; //0.0 0.157 0.0 0.45
  double t4 = 0.0; //0.0 -1.57 -3.0 3.0

  double dh[4][4]={
    0.3, 0, d1, t1,
    0.3, 0, 0, t2,
    0, 0, t3, 0,
    0, PI, d4, t4,
  };

  double a1[4][4]={
    cos(dh[0][3]), -sin(dh[0][3])*cos(dh[0][1]), sin(dh[0][3])*cos(dh[0][1]), dh[0][0]*cos(dh[0][3]),
    sin(dh[0][3]), cos(dh[0][3]*cos(dh[0][1])), -cos(dh[0][3])*sin(dh[0][1]), dh[0][0]*sin(dh[0][3]),
    0, sin(dh[0][1]), cos(dh[0][1]), dh[0][2],
    0, 0, 0, 1
  };

  double a2[4][4]={
    cos(dh[1][3]), -sin(dh[1][3])*cos(dh[1][1]), sin(dh[1][3])*cos(dh[1][1]), dh[1][0]*cos(dh[1][3]),
    sin(dh[1][3]), cos(dh[1][3]*cos(dh[1][1])), -cos(dh[1][3])*sin(dh[1][1]), dh[1][0]*sin(dh[1][3]),
    0, sin(dh[1][1]), cos(dh[1][1]), dh[1][2],
    0, 0, 0, 1
  };

  double a3[4][4]={
    cos(dh[2][3]), -sin(dh[2][3])*cos(dh[2][1]), sin(dh[2][3])*cos(dh[2][1]), dh[2][0]*cos(dh[2][3]),
    sin(dh[2][3]), cos(dh[2][3]*cos(dh[2][1])), -cos(dh[2][3])*sin(dh[2][1]), dh[2][0]*sin(dh[2][3]),
    0, sin(dh[2][1]), cos(dh[2][1]), dh[2][2],
    0, 0, 0, 1
  };

  double a4[4][4]={
    cos(dh[3][3]), -sin(dh[3][3])*cos(dh[3][1]), sin(dh[3][3])*cos(dh[3][1]), dh[3][0]*cos(dh[3][3]),
    sin(dh[3][3]), cos(dh[3][3]*cos(dh[3][1])), -cos(dh[3][3])*sin(dh[3][1]), dh[3][0]*sin(dh[3][3]),
    0, sin(dh[3][1]), cos(dh[3][1]), dh[3][2],
    0, 0, 0, 1
  };

  //-----------------------------------------------------------------------------

  double r1a1a2[4][4];
  double r2r1a3[4][4];
  double r3r2a4[4][4];

  // Multiplying matrix a1 and a2 and storing in array r1a1a2.
  for(int i = 0; i < 4; ++i){
    for(int j = 0; j < 4; ++j){
      for(int k = 0; k < 4; ++k){
        r1a1a2[i][j] += a1[i][k] * a2[k][j];
      }
    }
  }

  // Multiplying matrix r1 and a3 and storing in array r2r1a3.
  for(int i = 0; i < 4; ++i){
    for(int j = 0; j < 4; ++j){
      for(int k = 0; k < 4; ++k){
        r2r1a3[i][j] += r1a1a2[i][k] * a3[k][j];
      }
    }
  }

  // Multiplying matrix r2 and a4 and storing in array r3r2a4.
  for(int i = 0; i < 4; ++i){
    for(int j = 0; j < 4; ++j){
      for(int k = 0; k < 4; ++k){
        r3r2a4[i][j] += r2r1a3[i][k] * a4[k][j];
      }
    }
  }

  //----------------------------------------------------------------------------

  // showing the matrix on the screen
  cout << "a1:" << endl;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
        cout << fixed << a1[x][y] << " ";  // display the current element out of the array
    }
  cout<<endl;  // when the inner loop is done, go to a new line
  }

  // showing the matrix on the screen
  cout << "a2:" << endl;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
        cout << fixed << a2[x][y] << " ";  // display the current element out of the array
    }
  cout<<endl;  // when the inner loop is done, go to a new line
  }

  // showing the matrix on the screen
  cout << "a3:" << endl;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
        cout << fixed << a3[x][y] << " ";  // display the current element out of the array
    }
  cout<<endl;  // when the inner loop is done, go to a new line
  }

  cout << "a4:" << endl;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
        cout << fixed << a4[x][y] << " ";  // display the current element out of the array
    }
  cout<<endl;  // when the inner loop is done, go to a new line
  }

  // showing the matrix on the screen
  cout << "t:" << endl;
  for(int x=0;x<4;x++){
    for(int y=0;y<4;y++){
        cout << fixed << r3r2a4[x][y] << " ";  // display the current element out of the array
    }
  cout<<endl;  // when the inner loop is done, go to a new line
  }

  return 0;

}
