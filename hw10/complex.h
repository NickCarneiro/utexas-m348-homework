//complex.h
//17.2
#include <iostream>
class complex{
	private:
		float real;
		float imag;
	public:
		//complex() {}
		complex(float, float);
		void read();
		void print();
		complex add(const complex&);
		complex mult(const complex&);
		complex div(const complex&);
};