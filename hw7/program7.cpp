/***********************************************************
Program 7: For given f(x), a and b, this program uses the
composite Simpson rule to compute the integral

                   S = Int_a^b f(x) dx.
Inputs:
   a,b        Interval parameters
   n          Initial number of subintervals (even>=2)
   tol        Tolerance parameter (>=0)
   nMax       Maximum number of subintervals 

Outputs:
   S          Approximate value of integral
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std ;

/*** Define global constants ***/
const double pi=4.0*atan(1.0) ;

/*** Define function f to be integrated ***/
double f(double x){
  double fval ;

	// code function here //
	fval = exp(-1*pow(x-1.0,2)/(2.0*0.04)) / (0.2 * sqrt(2.0*pi));	
	return fval;
}

/*** Define function to evaluate approx integral of f ***/
double Simp(double a, double b, int n){
	double S ;
	double h = (b-a)/n;
	double xi0 = f(a) + f(b);
	double xi1 = 0;
	double xi2 = 0;
	double x = 0;
	for(int i = 1; i < n; i++){
		x = a + i*h;
		if(i % 2  == 0){
			//i is even
			xi2 += f(x);
		} else {
			//i is odd
			xi1 += f(x);
		}
	}
	S = h*(xi0 + 2*xi2 + 4*xi1)/3;
	return S ;
}

int main(){
  /*** Get problem data ***/
  int n, nMax ;
  double a, b, Sold, Snew, tol ;
  cout << "Input a, b (separated by spaces): " << flush ;
  cin >> a >> b ;
  cout << "Input n, tol, nMax (separated by spaces): " << flush ;
  cin >> n >> tol >> nMax ;

  /*** Check data ***/
  if ( n%2 != 0){ 
    cerr << "Simpson: n must be even -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
  if (n<2 || nMax<n+2){ 
    cerr << "Simpson: bad n or nMax values -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
  if (tol<=0){ 
    cerr << "Simpson: bad tolerance value -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
    
  /*** Main loop ***/
  Sold = Simp(a,b,n) ;
  Snew = Simp(a,b,n+2) ;
  cout.setf(ios::fixed) ;
  cout << setprecision(10) ;
  cout << "n =" << setw(4) << n << ",  " ;
  cout << "S =" << setw(14) << Sold << endl ;
  cout << "n =" << setw(4) << n+2 << ",  " ;
  cout << "S =" << setw(14) << Snew << endl ;
  while(fabs(Snew-Sold)>=tol && n+2<nMax){
    n = n+2 ;
    Sold = Snew ;
    Snew = Simp(a,b,n+2) ;
    cout << "n =" << setw(4) << n+2 << ",  " ;
    cout << "S =" << setw(14) << Snew << endl ;
  }

  /*** Info message ***/
  if(fabs(Snew-Sold)<tol){
    cout << "Simpson: solution converged" << endl ;
  }
  else{
    cout << "Simpson: max subintervals exceeded" << endl ;
  }
  return 0 ; //terminate main program
}
