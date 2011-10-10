/***********************************************************
Nick Carneiro
complex.cpp
19.1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;

complex :: complex(float re, float im){
	real = re;
	imag = im;
}

void complex :: set_real(float c){
	real = c;
}

void complex :: set_imag(float d){
	imag = d;
}

float complex :: real_part(){
	return real;
}

float complex :: imag_part(){
	return imag;
}
void complex :: read(){
	cout << "enter real and imag parts\n";
	cin >> real >> imag;
}

void complex :: print(){
	cout << "real = " << real << " imag= " << imag << endl;
}

complex complex :: add(const complex &beta){
	complex delta;
	delta.real = real + beta.real;
	delta.imag = imag + beta.imag;
	return delta;
}



complex complex :: div(const complex &beta){
	float denom = beta.real * beta.real + beta.imag * beta.imag; //c^2 + d^2
	float num_real = real*beta.real + imag*beta.imag; //ac+bd
	float num_imag = imag*beta.real - real*beta.imag; // i(bc-ad)
	complex delta;
	delta.real = num_real / denom;
	delta.imag = num_imag / denom;
}

//17.3
/*
[burt@chief hw10]$ ./usecomplex
enter real and imag parts
1.2 1.2
real = 2.2 imag= 2.2
real = 0 imag= 2.4

[burt@chief hw10]$ ./usecomplex
enter real and imag parts
2.0 3.0
real = 3 imag= 4
real = -1 imag= 5
*/