/***********************************************************
Program 12: Given A in R^(nxn) and b in R^(n) this program 
uses Gauss elimination with partial pivoting to find a soln
x in R^(n) of 

                          Ax = b

Inputs:
   n       Dimension of system (>=1)
   A[i][j] Coefficient matrix, i,j=0...n-1
   b[i]    Data vector, i=0...n-1

Outputs:
   x[i]    Solution vector, i=0...n-1

Note: The program is incomplete; you'll need to complete
it as indicated below.
***********************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;

/*** Auxiliary function: find nonzero pivot in kth col of A ***/
int find_pivot(double **A, int k, int n){
  int i=k ; 
  while( (i<n)&&(A[i][k]==0) ){
    i++ ;
  }
  return i ;
}

/*** Auxiliary function: exchange kth and pth rows of A,b ***/
void exchange_rows(double **A, double *b, int k, int p, int n){
  double temp ;
  temp = b[k] ;
  b[k] = b[p] ;
  b[p] = temp ;
  for(int j=0; j<n; j++){
    temp = A[k][j] ;
    A[k][j] = A[p][j] ;
    A[p][j] = temp ;
  }
}

/*** Auxiliary function: eliminate entries below kth diag of A ***/
void eliminate_below(double **A, double *b, int k, int n){
 
     // code elimination steps here //
	for (int i = 1; i <= n-1; i++){ //step 1
		//step 2
		int p = i;
		for (int k; k < n; k++){
			if( i <= p && p <= n && A[p-1][i-1] != 0){
				break;
			} else if(k == n-1){
				cout << "No unique soln exists, p not found." << endl;
				exit();
			}
			p++;
		}
		
		if(p != i){
			//step 3
			//Ep <-> Ei 
			for(k = 0; k < n; k++){
				float temp = A[p][k];
				A[p][k] = A[i][k];
				A[i][k] = temp;
			}
		}
		
		for(int j = i + 1; j <= n; j++){//step 4
			float mij = a[i-1][j-1] / a[i-1][i-1];//step 5
			//step 6. (Ej - mij*Ei) -> (Ej)
			for (k = 0; k < n; k++){
				A[j-1][k-1] = A[j-1][k-1] - mij*A[i-1][k-1];
			}
		}
		
		if(A[n][n] == 0){
		}
	}

}

/*** Auxiliary function: do backward substitution to find x ***/
void bwd_substitution(double **A, double *b, double *x, int n){

	
     // code substitution steps here //
	 //step 7
	if(A[n-1][n01] == 0){
		cout << "No unique solution exists" << endl;
		exit();
	}
	
	//step 8
	x[n] = A[n][n+1] / A[n][n];
	
	//step 9
	for (int i = n - 1; i >= 1; i--){
		float sum = 0;
		for (int j= i +1; j<=n; j++){
			sum += A[i][j]*x[j];
		}
		x[i] = (A[i][n+1] - sum)/A[i][i];
	}
	

}


int main(){
  /*** Define dimension and arrays ***/
  int n = 6 ; 
  double *x = new double[n] ;
  double *b = new double[n] ;
  double **A = new double*[n] ;
  for(int i=0;i<n;i++){
    A[i] = new double[n] ;
  }

  A[0][0] = -4 ; A[0][1] = 1 ; A[0][2] = 0 ; A[0][3] = 1 ; A[0][4] = 0 ; A[0][5] = 0 ;
  A[1][0] = 1 ; A[1][1] = -4 ; A[1][2] = 1 ; A[1][3] = 0 ; A[1][4] = 1 ; A[1][5] = 0 ;
  A[2][0] = 0 ; A[2][1] = 1 ; A[2][2] = -4 ; A[2][3] = 0 ; A[2][4] = 0 ; A[2][5] = 1 ;
  A[3][0] = 1 ; A[3][1] = - ; A[3[2] = 0 ; A[3][3] = -4 ; A[3][4] = 1 ; A[3][5] = 0 ;
  A[4][0] = 0 ; A[4][1] = 1 ; A[4][2] = 0 ; A[4][3] = 1 ; A[4][4] = -4 ; A[4][5] = 1 ;
  A[5][0] = 0 ; A[5][1] = 0 ; A[5][2] = 1 ; A[5][3] = 0 ; A[5][4] = 1 ; A[5][5] = -4 ;

  b[0] = -30 ; 
  b[1] = -20 ;
  b[2] = -60 ;
 b[3] = -30 ;
 b[4] = -20 ;
 b[5] = -60 ;

/*** Print data to screen ***/
  cout << endl;
  cout << "System size: n = " << endl;
  cout << n << endl << endl;
  cout << "Coeff matrix: A = " << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << A[i][j] << " " ;
    }
    cout << endl ;
  }
  cout << endl ;
  cout << "Data vector: b = " << endl;
  for(int i=0; i<n; i++){
    cout << b[i] << " " ;
  }
  cout << endl ;
  cout << endl ;

/*** Perform Gauss elimination (exit if no soln) ***/
  for(int k=0; k<n-1; k++){
    int p = find_pivot(A,k,n) ;
    if( (p>k)&&(p<n) ){
      exchange_rows(A,b,k,p,n) ;
    }
    if( p>=n ){
      cout << "Gauss: no unique solution" << endl ;
      exit(EXIT_FAILURE) ;
    }
    eliminate_below(A,b,k,n) ;
  }

  if( A[n-1][n-1]==0 ){
    cout << "Gauss: no unique solution" << endl ;
    exit(EXIT_FAILURE) ;
  }
  bwd_substitution(A,b,x,n) ;
  cout << "Gauss: unique solution found" << endl;
  cout << endl ;

/*** Print results if successful (unique solution) ***/
  cout << "Soln vector: x = " << endl;
  for(int i=0; i<n; i++){
    cout << x[i] << " " ;
  }
  cout << endl ;
  return 0 ; //terminate main program
}
