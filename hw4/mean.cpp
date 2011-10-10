//////////////////////////////////////////////////////////////////////
// Nick Carneiro 
// 9.10
//mean and std dev calculator
//
// Inputs:
// n number of input values
// x array of inputs
//
// Outputs:
//    dev	standard deviation
//	  mean  the mean
//
// 
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std ;
double deviation(int n, double x[], double mean){
	double sum = 0;
	
	for(int i = 0; i < n; i++){
		sum += pow((mean - x[i]),2);
		
	}
	
	return pow(sum/n,.5);
}

double average(int n, double x[]){
	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += x[i];
	}
	
	return sum / n;
}


int main(){
	
	int n;
	double* x = NULL;
	double dev, mean;
	// Get input data
	cout << endl ;
	cout << "enter n: " << flush ;
	cin >> n;
	
	x = new double[n];
	for(int i = 0; i < n; i++){
		cout << "enter value for x"<< i + 1 <<": " << flush ;
		cin >> x[i];
	}
	
	mean = average(n,x);
	dev = deviation(n,x,mean);
	
	cout << "standard deviation: " << dev << endl;
	cout << "mean: " << mean << endl;

	
  return 0 ; // terminate main program
}
