/***********************************************************
Nick Carneiro
usecomplex.cpp
17.2,3
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "complex.cpp"
using namespace std ;
int main(){
	complex beta[10], gamma[10], alpha[10];
	for(int i = 0; i < 10; i++){
		alpha[i].set(1.0,1.0);
	}
	for(int i = 0; i < 10; i++){
		beta[i].read();
	}
	for(int i = 0; i < 10; i++){
		gamma[i] = alpha[i].add(beta[i]);
		gamma[i].print();
	}
	for(int i = 0; i < 10; i++){
		gamma[i] = alpha[i].mult(beta[i]);
		gamma[i].print();
	}
	
	
	return 0;
	
}