#include <iostream>
#include <math.h>
using namespace std;

float length(float x, float y){
	return sqrt(x * x + y * y);
}

float length(float x, float y, float z){
	return sqrt(x*x + y*y + z*z);
}
float cosine(float x1, float x2, float y1, float y2){
	float num = x1*y1 + x2*y2;
	float den = length(x1,x2) * length(y1,y2);
	return num / den;
}

float cosine(float x1, float x2, float x3, float y1, float y2, float y3){
	float num = x1*y1 + x2*y2 + x3*y3;
	float den = length(x1,x2,x3) * length(y1,y2,y3);
	return num / den;
}

int main(){
	cout << "2-space: " << cosine(1,2,3,4) << endl;
	cout << "3-space: " << cosine(2,2,2,4,5,6) << endl;
}
