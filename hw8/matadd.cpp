#include <iostream>
#include <math.h>
using namespace std;

//computes A[] + B[] and stores result in C[]
void matadd(float* A, float* B, float *C, int n){
	for(int i = 0; i < n; i++){
		//cout << "A: " << *(A+i) << " B: "<< *(B+i) << " C: " <<*(C+i) <<endl;
		*(C+i) = *(A+i) + *(B+i);
		
	}
}

//this main outputs
/*
2.2
4.4
6.6
*/
int main(){
	float A[3] = {1.1, 2.2, 3.3};
	float B[3] = {1.1, 2.2, 3.3};
	float C[3] = {0.0};
	matadd(A, B, C, 3);
	for(int i = 0; i < 3; i++){
		cout << C[i] << endl;
	}
}