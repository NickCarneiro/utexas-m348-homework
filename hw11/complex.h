//complex.h
//17.2
#include <iostream>
class complex{
	private:
		float real;
		float imag;
	public:
		complex() {}
		complex(float, float);
		void read();
		void print();
		void set_real(float c);
		void set_imag(float d);
		float imag_part();
		float real_part();
		complex add(const complex&);
		//complex mult(const complex&);
		complex div(const complex&);
};