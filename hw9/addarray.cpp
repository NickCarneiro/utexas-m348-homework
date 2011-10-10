/***********************************************************
Nick Carneiro
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;


int main(){
	int n;
	cout << "Input n, array length:" << flush ;
	cin >> n;
	
	float *a = new float[n];
	float *b = new float[n];
	float *c = new float[n];
	
	//put some values in the arrays to add
	for(int i = 0; i < n; i++){
		a[i] = i;
		b[i] = i;
	}
	//add the arrays, put result in c
	for(int i = 0; i < n; i++){
		c[i] = a[i] + b[i];
		
	}
	
	for(int i = 0; i < n; i++){
		cout << c[i] << endl;
	}
}
/*
output:
[burt@chief hw9]$ ./addarray
Input n, array length:6
0
2
4
6
8
10

*/
