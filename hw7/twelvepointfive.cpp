#include <iostream>
using namespace std;
int f(int i, int &j){
	j = i + i;
	return i * i;
}
int main(){
	int m = 1;
	int k = f(2, m);
	cout << m << endl;
	cout << k << endl;
	return 0;
}

