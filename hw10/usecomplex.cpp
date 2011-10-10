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
	complex beta, gamma;
	complex alpha(1.0, 1.0);
	beta.read();
	gamma = alpha.add(beta);
	gamma.print();
	gamma = alpha.mult(beta);
	gamma.print();
	return 0;
	
}