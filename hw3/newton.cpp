//////////////////////////////////////////////////////////////////////
// Example program : Newton Method
//
// Solves the problem f(x) = 0 using the Newton algorithm.
//
// Inputs:
//   p0           Initial guess of root.
//   tol          Convergence tolerance (must be > 0).
//   Nmax         Maximum number of iterations (must be >= 1).
//
// Outputs:
//    p           Approximate root.
//    fp          Function value at approximate root.
//
// Note: The convergence criterion is |pn1 - pn| < tol.
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std ;

//problem 4a
/*
// Define f(x)
double f(double x) {
  return 1-4*x*cos(x) + 2*x*x + cos(2*x) ;
}

// Define f'(x)
double df(double x) {
  return -4*cos(x)+4*x*sin(x) + 4*x - 2*sin(2*x) ;
}

// Define f''(x)
double ddf(double x) {
  return 4*sin(x) + 4*sin(x) +4*cos(x) + 4 - 4*cos(2*x) ;
}
*/
// Define f(x)

//mini project part a
double f(double x) {
  return ln(cosh(x*sqrt(9.81*.00341)))/.00341-8.37 ;
}

// Define f'(x)
double df(double x) {
  return 53.6361*tanh(0.182899*x) ;
}

// Define function to print values to screen 
void printInfo(int n, double p, double fp) {
  cout << setprecision(10) ;
  cout << "n =" << setw(2) << n ;
  cout << "   " ;
  cout << "p =" << setw(12) << p ;
  cout << "   " ;
  cout << "f(p) = " << setw(15) << fp ;
  cout << endl ;
}

// Main body
int main(){
  double pn, pnp, tol ;
  int n, Nmax ;

  // Get input data
  cout << endl ;
  cout << "Enter p0: " << flush ;
  cin >> pn ;
  cout << "Enter tol and Nmax (separated by space): " << flush ;
  cin >> tol >> Nmax ;
  cout << endl ;

  // Do one step of Newton to initialize pnp
  pnp = pn - f(pn)/df(pn) ;

  // Print current data to screen 
  n = 0 ;
  printInfo(n,pn,f(pn)) ;
  n = 1 ;
  printInfo(n,pnp,f(pnp)) ;

  // Newton loop
  while( fabs(pnp-pn) >= tol && n < Nmax){
    n++ ;
    pn = pnp ;
	//original newton's method
    pnp = pn - f(pn)/df(pn) ;
	
	//modified method
	//pnp = pn - f(pn)*df(pn) / (pow(df(pn),2)-f(pn)*ddf(pn));
    printInfo(n,pnp,f(pnp)) ;
  }

  // Report results
  if( fabs(pnp-pn) < tol ){
    cout << endl ;
    cout << "Newton: solution converged" ;
    cout << endl ;
  }
  else{
    cout << endl ;
    cout << "Newton: max iterations exceeded" ;
    cout << endl ;
  }

  return 0 ; // terminate main program
}
