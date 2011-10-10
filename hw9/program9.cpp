/***********************************************************
Nick Carneiro
Program 9: For given [a,b], alpha and f(t,y), this program 
uses the Euler and 4th-order Taylor methods to compute an 
approximate solution of the IVP

              y' = f(t,y),   a <= t <= b,
              y(a) = alpha.

Inputs:
   a,b     Interval parameters (b>a)
   N       Number of t subintervals (>=1)

Outputs:
   t[i]    Array of time values, i=0...N
   y[i]    Array of solution values, i=0...N


Note 1: For any given problem, you'll need to code the 
function f(t,y).

Note 2: To implement the 4th-order Taylor method, you'll 
need to find and code the derivative functions fp(t,y), 
fpp(t,y) and fppp(t,y).

Note 3: A single file can be used for all the output. 
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
const char myfile[20]="program9.out" ;
const double g=10.0, eta=0.1 ;
const int Nmax=1000 ;
ofstream prt(myfile) ;

/*** Define function f(t,y) ***/
//f(t,y) = y'

double f(double t, double y){ 
  double fval=0 ;
  // code f here //
  fval = 10 - 0.1 * y * y;
  return fval ;
}

/*
//f for 4.1 4c 
double f(double t, double y){ 
  double fval=0 ;
  // code f here //
  fval = 1 + y/t;
  return fval ;
}
*/


double fp(double t, double y){

double fval=0 ;
  // code f here //
  //yp = -2*n*g + 2*n^2*v^2
  //fval = -2*eta*g + 2*eta*eta*y*y;
  fval = -2*eta*g + 2*eta*eta*pow(y,2);
  return fval ;
}
double fpp(double t, double y){
double fval=0 ;
  // code f here //
  //ypp = 4*n^2*g - 4*n^3*v^2
  //fval = 4*eta*eta*g - 4*eta*eta*eta*y*y;
  fval = 4*pow(eta,2)*g - 4*pow(eta,3)*pow(y,2);
  return fval ;
}
double fppp(double t, double y){
double fval=0 ;
  // code f here //
  //yppp = -8n^3*g + 8*n^4*v^2
  //fval = -8.0*eta*eta*eta*g + 8.0*eta*eta*eta*eta*y*y;
  fval = -8.0*pow(eta,3)*g + 8.0*pow(eta,4)*pow(y,2);
  return fval ;
}

/*** Define exact solution for comparison ***/

double yxct(double t){
  double yval=0 ;
  // code exact soln here //
  //yval = sqrt(10.0/0.1)*tanh(sqrt(10.0 * 0.1) * t);
  yval = sqrt(100.0)*tanh(t);
  return yval ;
}

/*
//for 5.2 3c
double yxct(double t){
  double yval=0 ;
  // code exact soln here //
  
  yval = t*log(t) + 2*t;
  return yval ;
}
*/
/*** Define Euler routine ***/
void Euler(double y[Nmax], double t[Nmax], 
                                double a, double b, int N){
  double h=(b-a)/N ;
  for(int j=1;j<=N;j++){
    y[j] = y[j-1] + h*f(t[j-1],y[j-1]) ;
    t[j] = t[j-1] + h ;
  }
  cout << "Euler: successfully computed solution" << endl ;
}

void Taylor(double y[Nmax], double t[Nmax], 
                                double a, double b, int N){
	double h=(b-a)/N ;
	
	for(int j=1;j<=N;j++){
		
		
		y[j] = y[j-1] + (f(t[j-1],y[j-1]) + 0.5*h*fp(t[j-1],y[j-1]) + (pow(h,2)/6)*fpp(t[j-1],y[j-1]) + (pow(h,3)/24)*fppp(t[j-1],y[j-1]))*h;
		t[j] = t[j-1] + h ;
		//cout << y[j] <<endl;
	}
	cout << "Taylor: successfully computed solution" << endl ;
}

/*** Define printing routine ***/
void printData(const char str[50], double y[Nmax], 
                                    double t[Nmax], int N){
  prt << endl ;
  prt << str << " (N = " << N << ")" << endl ;
  for(int j=0;j<=N;j++){
    prt << setprecision(6) ;
    prt << "t =" << setw(6) << t[j] ;
    prt << "   " ;
    prt << setprecision(8) ;
    prt << "yaprx =" << setw(10) << y[j] ;
    prt << "   " ;
    prt << "yexct =" << setw(10) << yxct(t[j]) ;
    prt << "   " ;
    prt << "error =" << setw(10) << fabs(y[j]-yxct(t[j])) ;
    prt << endl ; 
  }
}

int main(){
  int N ;
  double a, b, alpha ;
  double yEuler[Nmax], tEuler[Nmax], yTaylor[Nmax], tTaylor[Nmax] ;

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

  /*** Call Euler and print results ***/
  tEuler[0] = a ; 
  yEuler[0] = alpha ;
  Euler(yEuler,tEuler,a,b,N) ;
  //printData("Euler output",yEuler,tEuler,N) ;
  
  tTaylor[0] = a ; 
  yTaylor[0] = alpha ;
  Taylor(yTaylor, tTaylor, a, b, N);
  printData("Taylor output",yTaylor,tTaylor,N) ;
  cout << "Output file: " << myfile << endl ;

  return 0 ; //terminate main program
}
