#include <iostream>
#include <math.h>
using namespace std;
class complex{
	private:
		float real, imag;
	public:
		complex() {}
		complex(float re, float im) {real = re; imag = im;}
		friend complex mult_friend(complex &alpha, complex &beta); //friend prototype
		float real_part();
		float imag_part();
};
float complex :: real_part(){
	return real;
}

float complex :: imag_part(){
	return imag;
}

complex mult_friend(complex &alpha, complex &beta){
	complex delta;
	delta.real = alpha.real * beta.real - alpha.imag * beta.imag;
	delta.imag= alpha.real * beta.imag + alpha.imag * beta.real;
	return delta;
}
int main(){
	complex alpha(1.0, 1.0);
	complex beta(2.0, 2.0);
	complex delta = mult_friend(alpha,beta);
	cout << delta.real_part() << " " <<delta.imag_part();
	
}