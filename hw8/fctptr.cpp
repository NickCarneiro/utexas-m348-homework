#include <iostream>
#include <math.h>
using namespace std;
int f1(int);
int f2(int);

int sum(int(*f)(int), int);

/*
example 
inputs: 1 2
outputs: 2 8
*/
int main(){
	int n1, n2;
	cout << "enter n1 and n2" << endl;
	cin >> n1 >> n2;
	cout << sum(f1, n1) << endl;
	cout << sum(f2, n2) << endl;
	return 0;
	
}
int sum(int(*f)(int j), int n){
	int value = 0;
	for(int i = 1; i <= n; i++){
		value += f(i);
	}
	return value;
}

int f1(int i){
	return i;
}

int f2(int i){
	return i * i;
}