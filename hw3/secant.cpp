//////////////////////////////////////////////////////////////////////
// Nicholas Carneiro: Secant Method
//
// Solves the problem f(x) = 0 using the Secant algorithm.
//
// Inputs:
//   p0           Initial guess of root.
//	 p1
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

double f(double x) {
  return log(cosh(x*sqrt(9.81*.00341)))/.00341-8.37 ;
}



// Define function to print values to screen 
void printInfo(int n, double p, double fp) {
  cout << setprecision(10) ;
  cout << "n =" << setw(2) << n ;
  cout << "   " ;
  cout << "x =" << setw(12) << p ;
  cout << "   " ;
  cout << "f(x) = " << setw(15) << fp ;
  cout << endl ;
}

// Main body
int main(){
  double x0,x1,tol,fx ;
  int n, Nmax ;

  // Get input data
  cout << endl ;
  cout << "Enter x0: " << flush ;
  cin >> x0 ;
   cout << "Enter x1: " << flush ;
  cin >> x1 ;
  cout << "Enter tol and Nmax (separated by space): " << flush ;
  cin >> tol >> Nmax ;
  cout << endl ;

  

  // Print current data to screen 
  n = 0 ;
  printInfo(n,x0,f(x0)) ;
  n = 1 ;
  printInfo(n,x1,f(x1)) ;

  // Newton loop
  while( fabs(x1-x0) >= tol && n < Nmax){
    n++ ;
    
	//secant method
    fx = x1 - f(x1)*(x1-x0)/(f(x1)*f(x0)) ;
	x0 = x1;
	x1 = fx;
	
    printInfo(n,x1,fx) ;
  }

  // Report results
  if( fabs(x1-x0) < tol ){
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
