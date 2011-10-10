#include <iostream>
#include <math.h>
using namespace std;
class complex{
	private:
		float real, imag;
	public:
		complex() {}
		complex(float re, float im) {real = re; imag = im;}
		void read();
		void print();
		complex operator+ (const complex &);
		complex operator- (const complex &);
		complex operator* (const complex &);
		float real_part();
		float imag_part();
};
void complex :: read(){
	cout << "enter real and imag parts\n";
	cin >> real >> imag;
}

void complex :: print(){
	cout << "real = " << real << " imag= " << imag << endl;
}

//define overloaded operator +
inline complex complex :: operator+(const complex &beta){
	complex delta;
	delta.real = real + beta.real;
	delta.imag = imag + beta.imag;
	return delta;
}

inline complex complex :: operator-(const complex &beta){
	complex delta;
	delta.real = real - beta.real;
	delta.imag = imag - beta.imag;
	return delta;
}

inline complex complex :: operator*(const complex &beta){
	complex delta;
	delta.real = real*beta.real - imag* beta.imag;
	delta.imag = imag * beta.imag + imag*beta.real;
	return delta;
}

int main(){
	complex beta, gamma;
	complex alpha(1.0,1.0);
	beta.read();
	gamma = alpha + beta;
	gamma.print();
	return 0;
}