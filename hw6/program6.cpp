/***********************************************************
Program 6: For given R, L and I(t) this program uses finite
differences to compute E(t) where

              E(t) = L I'(t) + R I(t).

Inputs:
   n          Number of data points
   t[n]       Array of time values (equally-spaced)
   I[n]       Array of current values
   L,R        Inductance, resistance constants

Outputs:
   E[n]       Array of voltage values

Note 1: This program is incomplete; you'll need to 
complete it as indicated below.

Note 2: For any given problem, you'll need to set 
the values of n, L, R, h and (t_k,I_k), k=0...n-1, 
and then compile and run.
***********************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std ;


int main(){
  /*** Define input and output arrays and data ***/
  const int n = 11 ;
  double L = 0.873, R = 0.142, h = 0.01 ;
  double t[n] = {1.00, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.10} ;
  double I[n] = {3.10, 3.12, 3.15, 3.20, 3.28, 3.26, 3.23, 3.20, 3.16, 3.14, 3.10} ;
  double Iprime[n];
  double E[n] ;

  /*** Compute E-values using 3-point formulas ***/

for (int i = 0; i < n ; i++){
	if(i == 0){
		Iprime[i] = 1/(2*h) * (-3*I[i] + 4*I[i+1] - I[i+2]);
	} else if(i == n-1){
		Iprime[i] = 1/(2*h) * (-3*I[i-2] + 4*I[i-1] - I[i]);
	} else {
		Iprime[i] = 1/(2*h) * (I[i+1] - I[i-1]);
	}
	
	E[i] = L*Iprime[i] + R*I[i];
}
  /*** Print output to file ***/
ofstream myfile;

  myfile.open ("finitediff.txt");
  myfile << "L: " << L << endl;
  myfile << "R: " << R << endl;
  myfile << "tk   "<<"I(tk)  "<<   "E(tk)  "<< endl;
  
  for (int i = 0; i < n; i++){
	cout.precision(16);
  cout.width(6);
	myfile << t[i] <<" " << I[i] << " " << E[i] << endl;
  }
  myfile.close();

  return 0 ; //terminate main program
}
