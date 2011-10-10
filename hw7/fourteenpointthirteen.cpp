#include <iostream>
using namespace std;

template <class T> T max(T &a, const T &b){
	if(a < b){
		return b;
	} else {
		return a;	
	}
}

int main(){
	cout << max(1,2) << endl;
	cout << max(99.1, 2.2) << endl;
	return 0;
}
