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

complex mult(complex &alpha, complex &beta){
	complex delta;
	delta.set_real(alpha.real_part() * beta.real_part() - alpha.imag_part() * beta.imag_part());
	delta.set_imag(alpha.real_part() * beta.imag_part() + alpha.imag_part() * beta.real_part());
	return delta;
}
int main(){
	complex beta, gamma;
	complex alpha(1.0, 1.0);
	beta.read();
	gamma = alpha.add(beta);
	gamma.print();
	gamma = mult(gamma,beta);
	gamma.print();
	return 0;
	
}