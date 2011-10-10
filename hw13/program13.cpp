/***********************************************************
Program 13: Given n, [t0,tf], alpha in R^(n), g in R^(n)
and M in R^(nxn), this program uses the Backward Euler 
method together with LU factorization to compute an 
approximate solution u(t) in R^(n) of the IVP

          u' = M u + g, t0 <= t <= tf
          u(t0) = alpha.

Inputs:
   t0,tf    Interval parameters (tf>t0)
   N        Number of t subintervals (>=1)
   n        Dimension of IVP system (>=1)
   M[q][p]  IVP coefficient matrix, q,p=0...n-1
   g[q]     IVP data vector, q=0...n-1
   alpha[q] IVP initial condition vector, q=0...n-1

Outputs:
   t[i]      Array of time values, i=0...N
   w[i][0]   Array of approx u_1 values, i=0...N
   w[i][1]   Array of approx u_2 values, i=0...N
   ...
   w[i][n-1] Array of approx u_n values, i=0...N

Note: The program is incomplete; you'll need to 
complete it as indicated below.
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;

/*** Aux function: compute LU factorization of A in R^(nxn) ***/
void lu_factor(double **A, double **L, double **U, int n){

     // code here //
	 //1 
	 if (L[0][0] *U[0][0] == 0){
		cout << "factorization is impossible";
		exit();
	 }
	 //2
	 for(int j = 1; j < n; j++){
		U[1,j] = A[0][j] / L[0][0];
		L[j][0] = A[j][0] / U[0][0];
	 }
	 //step 3
	 for (int i = 1; i < n-1; i++){
		if(L[i][i]*U[i][i] == 0){
			cout << "factorization is impossible";
		}
		
		for(j = i+1; i < n; i++){
			double row = 0;
			for(int k = 1; k <= i-1; k++){
				row += L[i][k] * U[k][j];
			}
			
			U[i][j] = 1 / L[i][i] * (A[i][j] - row);
			double row2 = 0;
			for(int k = 1; k <= i-1; k++){
				row += L[j][k] * U[k][i];
			}
			L[j][i] = 1 / U[i][i] * (A[j][i] - row2);
		}
	 }

}

/*** Aux function: solve LUx=b system for x in R^(n) ***/
void lu_solve(double **L, double **U, double *b, double *x, int n){

     // code here //
	 //1 
	 if (L[0][0] *U[0][0] == 0){
		cout << "factorization is impossible";
		exit();
	 }
	 //2
	 for(int j = 1; j < n; j++){
		U[1,j] = A[0][j] / L[0][0];
		L[j][0] = A[j][0] / U[0][0];
	 }
	 //step 3
	 for (int i = 1; i < n-1; i++){
		if(L[i][i]*U[i][i] == 0){
			cout << "factorization is impossible";
		}
		
		for(j = i+1; i < n; i++){
			double row = 0;
			for(int k = 1; k <= i-1; k++){
				row += L[i][k] * U[k][j];
			}
			
			U[i][j] = 1 / L[i][i] * (A[i][j] - row);
			double row2 = 0;
			for(int k = 1; k <= i-1; k++){
				row += L[j][k] * U[k][i];
			}
			L[j][i] = 1 / U[i][i] * (A[j][i] - row2);
		}
	 }

}


int main(){
  /*** Define dimension, data arrays and utility arrays ***/
  int n = 3 ; 
  double *alpha = new double[n] ;
  double *g = new double[n] ;
  double *x = new double[n] ;
  double *b = new double[n] ;
  double **M = new double*[n] ;
  double **A = new double*[n] ;
  double **L = new double*[n] ;
  double **U = new double*[n] ;
  for(int i=0;i<n;i++){
    M[i] = new double[n] ;
    A[i] = new double[n] ;
    L[i] = new double[n] ;
    U[i] = new double[n] ;
  }

  M[0][0] = 1 ; M[0][1] = 3 ; M[0][2] = 0 ;
  M[1][0] = 0 ; M[1][1] = 1 ; M[1][2] =-1 ;
  M[2][0] = 1 ; M[2][1] = 4 ; M[2][2] = 2 ;

  g[0] = 1 ; 
  g[1] = 1 ;
  g[2] =-2 ;

  alpha[0] = 3 ; 
  alpha[1] = 0 ;
  alpha[2] =-1 ;

/*** Print given data to screen ***/
  cout << endl;
  cout << "IVP system size: n = " << endl;
  cout << n << endl << endl;
  cout << "IVP coeff matrix: M = " << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << M[i][j] << " " ;
    }
    cout << endl ;
  }
  cout << endl ;
  cout << "IVP data vector: g = " << endl;
  for(int i=0; i<n; i++){
    cout << g[i] << " " ;
  }
  cout << endl << endl ;
  cout << "IVP initial cond: alpha = " << endl;
  for(int i=0; i<n; i++){
    cout << alpha[i] << " " ;
  }
  cout << endl << endl ;

  /*** Define interval and time step parameter ***/
  int N = 10 ;
  double t0 = 0, tf = 1, dt=(tf-t0)/N ;


  /*** Build Backward Euler matrix A=[I-dt*M] and factorize ***/

     // code here //


  /*** Compute approx solution of IVP at each time level ***/

     // code here //


  return 0 ; //terminate main program
}
