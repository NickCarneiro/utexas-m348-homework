/***********************************************************
Program 11: Given m, [a,b], alpha and f(t,u), this program 
uses the standard Euler and 4th-order Runge-Kutta (RK4) 
methods to compute an approximate solution of the following 
IVP for u(t) in R^m

              u' = f(t,u),   a <= t <= b,  
              u(a) = alpha.

Inputs:
   a,b     Interval parameters (b>a)
   N       Number of t subintervals (>=1)
   m       Dimension of system (>=1)

Outputs:
   t[i]      Array of time values, i=0...N
   w[i][0]   Array of approx u_1 values, i=0...N
   w[i][1]   Array of approx u_2 values, i=0...N
   ...
   w[i][m-1] Array of approx u_m values, i=0...N

Note 1: For any given problem, you'll need to code
the function f(t,u).  Notice that both u and f(t,u)
will have m components indexed 0...m-1.

Note 2: A single file can be used for all the output.
Each call to the printing function "printData" will
append data to the end of the file.
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;

/*** Define output file and global constants ***/
const char myfile[20]="program11.out" ;
const double g=32.17 ;
ofstream prt(myfile) ;

/*** Define function to evaluate f(t,u) ***/
void feval(double t, double *u, double *f, int m){

    // compute f_0...f_{m-1} //
    f[0] = u[1] ;
    f[1] = -2.0*u[0] + 3.8*cos(t) ;
}

/*** Define Euler routine ***/
void Euler(double **w, double *t, 
                 double a, double b, int N, int m){
  double h=(b-a)/N, tval ;
  double *f = new double[m] ;
  double *k1 = new double[m] ;
  double *wval = new double[m] ;

  for(int i=0;i<=N-1;i++){
    // compute k1 //
    tval = t[i] ;
    for(int q=0;q<=m-1;q++){
      wval[q] = w[i][q] ;
    }
    feval(tval,wval,f,m) ;
    for(int q=0;q<=m-1;q++){
      k1[q] = h*f[q] ;
    }
    // update t and w //
    t[i+1] = t[i] + h ;
    for(int q=0;q<=m-1;q++){
      w[i+1][q] = w[i][q] + k1[q] ;
    }
  }
  cout << "Euler: successfully computed solution" << endl ;
  delete []f ;
  delete []k1 ;
  delete []wval ;
}

/*** Define RK4 routine ***/
void RK4(double **w, double *t, 
                       double a, double b, int N, int m){
  double h=(b-a)/N, tval ;
  double *f = new double[m] ;
  double *k1 = new double[m] ;
  double *k2 = new double[m] ;
  double *k3 = new double[m] ;
  double *k4 = new double[m] ;
  double *wval = new double[m] ;

  for(int i=0;i<=N-1;i++){
    // compute k1 //a
    tval = t[i] ;
    for(int q=0;q<=m-1;q++){
      wval[q] = w[i][q] ;
    }
    feval(tval,wval,f,m) ;
    for(int q=0;q<=m-1;q++){
      k1[q] = h*f[q] ;
    }
    // compute k2 //
    tval = t[i] + h/2.0 ;
    for(int q=0;q<=m-1;q++){
      wval[q] = w[i][q] + k1[q]/2.0 ;
    }
    feval(tval,wval,f,m) ;
    for(int q=0;q<=m-1;q++){
      k2[q] = h*f[q] ;
    }
    // compute k3 //
    tval = t[i] + h/2.0 ;
    for(int q=0;q<=m-1;q++){
      wval[q] = w[i][q] + k2[q]/2.0 ;
    }
    feval(tval,wval,f,m) ;
    for(int q=0;q<=m-1;q++){
      k3[q] = h*f[q] ;
    }
    // compute k4 //
    tval = t[i] + h ;
    for(int q=0;q<=m-1;q++){
      wval[q] = w[i][q] + k3[q] ;
    }
    feval(tval,wval,f,m) ;
    for(int q=0;q<=m-1;q++){
      k4[q] = h*f[q] ;
    }
    // update t and u //
    t[i+1] = t[i] + h ;
    for(int q=0;q<=m-1;q++){
      w[i+1][q] = w[i][q] + (k1[q]+2*k2[q]+2*k3[q]+k4[q])/6.0 ;
    }
  }
  cout << "RK4: successfully computed solution" << endl ;
  delete []f ;
  delete []k1 ;
  delete []k2 ;
  delete []k3 ;
  delete []k4 ;
  delete []wval ;
}

/*** Define printing routine ***/
void printData(const char str[50], 
                  double **w, double *t, int N, int m){
  prt << endl ;
  prt << str << " (N = " << N << ")" << endl ;
  for(int i=0;i<=N;i++){
    prt << setprecision(4) ;
    prt << "t =" << setw(6) << t[i] ;
    prt << "   " ;
    prt << setprecision(8) ;
    for(int q=0;q<=m-1;q++){
      prt << "u" << q+1 << " =" << setw(10) << w[i][q] ;
      prt << "   " ;
    }
    prt << endl ; 
  }
}

int main(){
  int N ;

  /*** Get grid parameter ***/
  cout << "Input N: " << flush ;
  cin >> N ;
  if (N<1){
    cerr << "Main: bad grid param N -- exiting" << endl;
    exit(EXIT_FAILURE);
  }

  /*** Define dimension, interval and initial conditions ***/
  const int m = 2 ; 
  double a = 0, b = 1 ;
  double alpha[m] = {3, 0} ;

  /*** Create time and solution arrays ***/
  double *tEuler = new double[N+1] ;
  double **wEuler = new double*[N+1] ;
  for(int i=0;i<=N;i++){
    wEuler[i] = new double[m] ;
  }
  double *tRK4 = new double[N+1] ;
  double **wRK4 = new double*[N+1] ;
  for(int i=0;i<=N;i++){
    wRK4[i] = new double[m] ;
  }

  /*** Call Euler and print results ***/
  tEuler[0] = a ; 
  for(int q=0;q<=m-1;q++){ wEuler[0][q] = alpha[q]; }
  Euler(wEuler,tEuler,a,b,N,m) ;
  printData("Euler output",wEuler,tEuler,N,m) ;
  cout << "Output file: " << myfile << endl ;

  /*** Call RK4 and print results ***/
  tRK4[0] = a ; 
  for(int q=0;q<=m-1;q++){ wRK4[0][q] = alpha[q]; }
  RK4(wRK4,tRK4,a,b,N,m) ;
  printData("RK4 output",wRK4,tRK4,N,m) ;
  cout << "Output file: " << myfile << endl ;

  delete []tEuler ;
  delete []wEuler ;
  delete []tRK4 ;
  delete []wRK4 ;
  return 0 ; //terminate main program
}
