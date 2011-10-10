#include <iostream>
#define CONST_M 4
using namespace std;
int c[CONST_M][5]; //result matrix is m x r

void matrixMult (int a[CONST_M][4], int b[4][5]){
	
	for(int i = 0; i < CONST_M; i++){
		for(int j = 0; j < 5; j++){
			//cout << a[i][j] << " " << b[i][j]<<endl;
			c[i][j] = 0;
			for (int k = 0; k < 4; k++){
					c[i][j] += a[i][k] * b[k][j];
			}
			
		}
	}
}

void matrixPrint (){

	cout << "Result: "<< endl;
	for(int i = 0; i < CONST_M; i++){
		for(int j = 0; j < 5; j++){
			//cout << "i: " << i << " j: " << j << endl;
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	//M = 4
	int a[CONST_M][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	int b[4][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	matrixMult(a,b);
	matrixPrint();
	return 0;
}

