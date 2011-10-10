#include <iostream>
#define CONST_M 4
using namespace std;
int c[CONST_M][4];
void matrixAdd (int a[CONST_M][4], int b[CONST_M][4]){
	
	for(int i = 0; i < CONST_M; i++){
		for(int j = 0; j < 4; j++){
			//cout << a[i][j] << " " << b[i][j]<<endl;
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matrixPrint (){
	int x;
	cout << "Result: "<< endl;
	
	for(int i = 0; i < CONST_M; i++){
		for(int j = 0; j < 4; j++){
			//cout << "i: " << i << " j: " << j << endl;
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	//M = 4
	int a[CONST_M][4] = {{2,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	int b[CONST_M][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,5}};
	matrixAdd(a,b);
	matrixPrint();
	return 0;
}

