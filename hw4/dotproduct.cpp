//////////////////////////////////////////////////////////////////////
// Dot product calculator
//
// Reads in two vectors (x, y, z) and computes dot product:
// (x,y) = x1*y1 +x2*y2 + x3*y3
//
// also computes cos(theta)
// cos(theta) = (u,v) / ((u,u)^.5 * (v,v)^.5)
// then calculates theta using arccos
//
// Inputs:
// u vector
// v vector
//
// Outputs:
//    dp           dot product
//    cos          cos(theta)
//		theta
//
// 
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std ;
double dotproduct(double u[], double v[]){
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}
// Main body
int main(){
	double u[3],v[3];
	double dp,cos,theta;

	// Get input data
	cout << endl ;
	cout << "u1,u2,u3 (separated by space): " << flush ;
	cin >> u[0] >> u[1] >> u[2];
	cout << "v1,v2,v3 (separated by space): " << flush ;
	cin >> v[0] >> v[1] >> v[2];
	cout << endl ;
	
	//calculate dot product u dot v
	dp = dotproduct(u,v);
	
	//calculate cos(theta)
	cos = dp/(pow(dotproduct(u,u),.5)*pow(dotproduct(v,v),.5));
	
	//theta
	theta = acos(cos);
	
	cout << "dot product: " << dp << endl;
	cout << "cos(theta): " << cos << endl;
	cout << "theta: " << theta << endl;
	
  return 0 ; // terminate main program
}
