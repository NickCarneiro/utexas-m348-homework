#include <iostream>
using namespace std ;
class complex{
	protected:
		float real;
		float imag;
	public:
		complex(){}
		complex(){float re, float im){real = re; imag = im;}
		void read();
		void print();
		complex operator + (const complex &);
		complex operator * (const complex &);
};

class ComplexPos : public complex{
	public:
		ComplexPos() : complex {}
		ComplexPos(const complex &a) : complex(a){}
		ComplexPos(float,float);
		ComplexPos &operator = (const ComplexPos&);
		
		void read();
	private:
		void error_print(chat [ ]);
};
//adding implementations for 19.1
complex operator + (const complex &a){
	float newreal = real + a.real;
	float newimag = imag + a.imag;
	return ComplexPos(newreal, newimag)
}

complex operator * (const complex &a){
	float newreal = real * a.real;
	float newimag = imag * a.imag;
	return ComplexPos(newreal, newimag)
}
ComplexPos :: ComplexPos(float re, float im){
	real = re;
	imag = im;
	if(re <= 0) error_print("Constructor");
}

ComplexPos& ComplexPos :: operator = (const ComplexPos &beta){
	real = beta.real;
	imag = beta.imag;
	if(beta.real <= 0) error_print("operator =");
}

void ComplexPos :: read(){
	cout << "enter real an imag parts\n"
	cin >> real >> imag;
	if(real <=0) error_print("read function");
}

void ComplexPos :: error_print(char c[ ]){
	cout << "Message from " << c << ":\n";
	cout << "this number does not have positive real part\n";
	cout << "real = " << real << "imag = " << imag << endl;
}

int main(){
	ComplexPos alpha(-1,8), beta, gamma, delta;
	beta.read();
	gamma = alpha + beta;
	gamma.print();
	delta = alpha * beta;
	delta.print();
	return 0;
}