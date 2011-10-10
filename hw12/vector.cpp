#include <iostream>
using namespace std;
class vector{
	private: 
		float vec[3];
	public: 
		vector operator+ (const vector &);
		float dot(const vector &);
		friend istream& operator >> (isteam &, vector &);
		friend ostream& operator << (ostream &, vector &);
	}; 
	istream& operator>> (stream &vecin, vector &v){
		cout << "what is the vector?\n";
		for(int i = 0; i < 3; i++){
			vecin >> v.vec[i];
		}
		return vecin;
	}
	
	ostream& operator<< (ostream &vecout, vector &v){
		for(int i = 0; i < 3; i++){
			vecout << "element " << i << " of vector is "
					<< v.vec[i] << endl;
		}
		return v;
	}
	
	vector vector :: operator+ (const vector &u){
		vector v;
		for(int i=0; i < 3; i++){
			v.vec[i] = vec[i] + u.vec[i];
		}
		return v;
	}
	
	float vector :: operator* (const vector &u){
		float value;
		for (int i = 0; i < 3; i++){
			value = value +  vec[i] * u.vec[i];
		}
		return value;
	}
	


int main(){
	vector a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << c;
	float dp = a * b;
	cout << "dot = " << dp << endl;
	return 0;
}