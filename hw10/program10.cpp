/***********************************************************
Program 10: For given [a,b], alpha and f(t,y), this program 
uses the Modified Euler and 4th-order Runge-Kutta (RK4) 
methods to compute an approximate solution of the IVP

              y' = f(t,y),   a <= t <= b,
              y(a) = alpha.

Inputs:
   a,b     Interval parameters (b>a)
   N       Number of t subintervals (>=1)

Outputs:
   t[i]    Array of time values, i=0...N
   y[i]    Array of solution values, i=0...N


Note 1: The function f(t,y) must be coded below for 
any given problem.

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
const char myfile[20]="program10.out" ;

const double pi=4*atan(1.0), g=32.1 ;
const double q = 0.6;
const double c = 8.0;
const double r0 = 0.1;
const int Nmax=3000 ;
ofstream prt(myfile) ;

/*** Define function f(t,y) ***/
double f(double t, double y){
  double fval=0 ;

  //code here//
	fval = -1 *q * pow(r0,2)*sqrt(2*g*y) / (pow(r0 + 7.9*y/8,2)) ;
  return fval ;
}

/*** Define Modified Euler routine ***/
void ModEuler(double y[Nmax], double t[Nmax], 
                              double a, double b, int N){
  double h=(b-a)/N, k1, k2 ;
  for(int j=1;j<=N;j++){
    k1 = h*f(t[j-1],y[j-1]) ;
    k2 = h*f(t[j-1]+h,y[j-1]+k1) ;
    y[j] = y[j-1] + 0.5*(k1+k2) ;
    t[j] = t[j-1] + h ;
  }
  cout << "Modified Euler: successfully computed solution" << endl ;
}

/*** Define RK4 routine ***/
void RK4(double y[Nmax], double t[Nmax],
                              double a, double b, int N){

  //code here//
	double h = (b-a)/N;
	double t1 = a;
	double w = y[0];
	
	for (int i = 1; i<=N;i++){
		double k1 = h*f(t1+h/2,w+k1/2);
		double k2 = h*f(t1 + h/2, w + k2/2);
		double k3 = h*f(t1 + h/2, w + k2/2);
		double k4 = h*f(t1 + h, w + k3);
		
		w = w + (k1 + 2*k2 + 2*k3 + k4)/6;
		t1 = a + i*h;
		y[i] = w;
		t[i] = t1;
	}
}

/*** Define printing routine ***/
void printData(const char str[50], double y[Nmax], 
                                      double t[Nmax], int N){
  prt << endl ;
  prt << str << " (N = " << N << ")" << endl ;
  for(int j=0;j<=N;j++){
    prt << setprecision(4) ;
    prt << "t =" << setw(6) << t[j] ;
    prt << "   " ;
    prt << setprecision(8) ;
    prt << "y =" << setw(10) << y[j] ;
    prt << "   " ;
    prt << endl ; 
  }
}

int main(){
  int N ;
  double a, b, alpha ;
  double yModEuler[Nmax], tModEuler[Nmax], yRK4[Nmax], tRK4[Nmax] ;

  /*** Get problem data ***/
  cout << "Input a, b, alpha, N (separated by spaces): " << flush ;
  cin >> a >> b >> alpha >> N ;

  /*** Check data ***/
  if ( b<=a){
    cerr << "Main: bad interval params a,b -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
  if (N<1){
    cerr << "Main: bad step param N -- exiting" << endl;
    exit(EXIT_FAILURE);
  }

  /*** Call Modified Euler and print results ***/
  tModEuler[0] = a ; 
  yModEuler[0] = alpha ;
  ModEuler(yModEuler,tModEuler,a,b,N) ;
 // printData("Modified Euler output",yModEuler,tModEuler,N) ;
 // cout << "Output file: " << myfile << endl ;

  /*** Call RK4 and print results ***/
	tRK4[0] = a ; 
  yRK4[0] = alpha ;
  RK4(yRK4,tRK4,a,b,N) ;
 printData("RK4 output",yRK4,tRK4,N) ;
  cout << "Output file: " << myfile << endl ;
  //code here

  return 0 ; //terminate main program
}
