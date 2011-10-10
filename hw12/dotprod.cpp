//omitting existing methods

//dot product member function for 18.2
float vector :: operator* ( const vector &u){
	float dp = 0;
	int n = u.veclength;
	for(int i = 0; i < n; i++){
		dp = dp + vec[i] * u.vec[i];
	}
	return dp;
}

//overloading << and >> for 18.3

istream& operator>> (stream &vecin, vector &v){
		int n = u.veclength;
		cout << "what is the vector?\n";
		for(int i = 0; i < n; i++){
			vecin >> v.vec[i];
		}
		return vecin;
	}
	
ostream& operator<< (ostream &vecout, vector &v){
	int n = u.veclength;
	for(int i = 0; i < n; i++){
		vecout << "element " << i << " of vector is "
				<< v.vec[i] << endl;
	}
	return v;
}