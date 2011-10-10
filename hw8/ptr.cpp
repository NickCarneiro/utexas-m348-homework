#include <iostream>
#include <math.h>
using namespace std;


int main(){
	float a[3] = {1.1, 2.2, 3.3};
	a[2] = *a + *(a+1) + *(a+2);
	cout << a[2] << endl;
}