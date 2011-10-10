/***********************************************************
Nick Carneiro
17.1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std ;

class complex{
	private:
		float real;
		float imag;
	public:
		void set(float c, float d){
			real = c;
			imag = d;
		}
		float real_part(){
			return real;
		}
		float imag_part(){
			return imag;
		}
};
int main(){
	complex alpha;
	alpha.set(1.0,5.0);
	cout<< alpha.real_part();
	return 0;
}

/*
Input: 1,1 Output:1
Input: 2,1 Output:2
Input: 3,1 Output:3
*/