#include <iostream.h>
class vector{
	private:
		int veclength;
		float *vec;
	public:
		vector();
		vector(int);
		~vector();
		vector(const vector &);
		vector operator+ (const vector&);
		float operator* (const vector&); //dot product method
		float& operator[ ](int);
		vector& operator= (const vector&);
		//void read(); replaced with >> and << for 18.3
		//void print();
		friend istream& operator >> (isteam &, vector &);
		friend ostream& operator << (ostream &, vector &);
		
};