#include <iostream>
using namespace std;

class Base{ //abstract
	public:
		virtual void read(int) = 0;
		virtual void area(int) = 0;
};

class Rectangle : public Base { //derived
	private :
		float h,w;
	public:
		void read(){
			cout << "enter h and w\n";
		}
		void area(){
			cout << "area of rectangle = " << h * w << endl;
		}	
};

class Square : public Rectangle{
} //behaves exactly the same as Rectangle

class Circle : public Base {
	private :
		float radius;
	public :
		void read(){
			cout << "radius = ?" << endl;
			cin >> radius;
		}
		void area(){
			cout << "area of circle = " << 3.14 * radius * radius << endl;
		}
};

class Ellipse : public Circle {
	private :
		float a;
		float b;
	public : 
		void read(){
			cout << "enter a and b \n";
			cin >> a,b;
		}
		void area(){
			cout << "area of ellipse =  " << 3.14 * a * b;
		}
};

int main(){
	Ellipse a = new Ellipse();
	a.read();
	a.area();
	Circle b = new Circle();
	b.read();
	b.area();
	Rectangle c = new Rectangle();
	c.read();
	c.area();
	Square d = new Square();
	d.read();
	d.area();
}