/***********************************************************
Program 8: For given f(x,y) and [a,b]x[c,d], this program 
uses the composite Simpson rule to compute the double
integral

             S = Int_c^d Int_a^b f(x,y) dx dy.
Inputs:
   a,b,c,d    Interval parameters
   n,m        Initial number of x,y subintervals (even>=2)
   tol        Tolerance parameter (>=0)
   nMax,mMax  Maximum number of subintervals 

Outputs:
   S          Approximate value of integral
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;


/*** Define function f to be integrated ***/
double f(double x, double y){
  double fval ;

  // code function here //
	fval = exp(-1.0 * x*y*y);
  return fval ;
}


/*** Define function to evaluate approx double integral of f ***/
double SimpDouble(double a, double b, 
                               double c, double d, int n, int m){
  double S ;

  // code composite simpson here //
	float h = (b-a)/n;
	
	double j1 = 0; //end terms
	double j2 = 0; //even terms
	double j3 = 0; //odd terms
	
	for(int i = 0; i <= n; i++){
		double x = a + i*h;
		double hx = (d - c)/m;
		double k1 = f(x,c+f(x,d));
		double k2 = 0;
		double k3 = 0;
		
		for (int j = 1; j < m; j++){
			double y = c + j*hx;
			double q = f(x,y);
			if(j % 2 == 0){
				//j is even
				k2 = k2 + q;
			} else {
				k3 = k3 + q;
			}
		}
		double l = (k1 + 2*k2 + 4*k3)*hx/3;
		
		if(i == 0 || i ==n){
			j1 = j1 + l;
		} else if(i % 2 ==0){
			//i is even
			j2 = j2 + l;
		} else {
			j3 = j3 + l;
		}
	}
	//cout << "h: " << h << " j1: "<<j1 <<" j2: "<<j2 <<" j3: "<<j3;
	S = h*(j1 + 2*j2 + 4*j3)/3;
  return S ;
}

int main(){
  /*** Get problem data ***/
  int n, nMax, m, mMax ;
  double a, b, c, d, tol, Sold, Snew ;
  cout << "Input a, b, c, d (separated by spaces): " << flush ;
  cin >> a >> b >> c >> d ;
  cout << "Input n, m, nMax, mMax (separated by spaces): " << flush ;
  cin >> n >> m >> nMax >> mMax ;
  cout << "Input tol: " << flush ;
  cin >> tol ;

  /*** Check data ***/
  if (n%2 != 0 || m%2 != 0){
    cerr << "Simpson: n and m must be even -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
  if (n<2 || nMax<n+2 || m<2 || mMax<m+2){
    cerr << "Simpson: bad n, m, nMax or mMax values -- exiting" << endl;
    exit(EXIT_FAILURE);
  }
  if (tol<=0){
    cerr << "Simpson: bad tolerance value -- exiting" << endl;
    exit(EXIT_FAILURE);
  }

  /*** Main loop ***/
  Sold = SimpDouble(a,b,c,d,n,m) ;
  Snew = SimpDouble(a,b,c,d,n+2,m+2) ;
  cout.setf(ios::fixed) ;
  cout << setprecision(10) ;
  cout << "n =" << setw(4) << n << ",  " ;
  cout << "m =" << setw(4) << m << ",  " ;
  cout << "S =" << setw(14) << Sold << endl ;
  cout << "n =" << setw(4) << n+2 << ",  " ;
  cout << "m =" << setw(4) << m+2 << ",  " ;
  cout << "S =" << setw(14) << Snew << endl ;
  while(fabs(Snew-Sold)>=tol && n+2<nMax && m+2<mMax){
    n = n+2 ;
    m = m+2 ;
    Sold = Snew ;
    Snew = SimpDouble(a,b,c,d,n+2,m+2) ;
    cout << "n =" << setw(4) << n+2 << ",  " ;
    cout << "m =" << setw(4) << m+2 << ",  " ;
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
