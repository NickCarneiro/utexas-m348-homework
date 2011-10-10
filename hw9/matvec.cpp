//Nick Carneiro
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;
float matvec_add(float **A, int n);

int main(){
	int n, i;
	cin >> n;
	
	float **A; 
	A = new float*[n];
	for(i = 0; i < n; i++){
		A[i] = new float[n];
	}
	for(i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = i + j;
			
		}
	}
	float sum = matvec_add(A,n);
	cout << "sum of all elements in A:  " << sum << endl;
	return 0;
}


float matvec_add(float **A,int n){
	float temp = 0;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < n; j++){
			//cout << A[i][j] << endl;
			temp = temp + A[i][j];
		}
	}
	return temp;
}

/*
output from original program
[burt@chief hw9]$ ./matvec
3 3
b[0] = 5 b[1] = 8
[burt@chief hw9]$ ./matvec
4 4
b[0] = 14 b[1] = 20
[burt@chief hw9]$ ./matvec
5 5
b[0] = 30 b[1] = 40

*/
