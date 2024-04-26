namespace lynx{

//theory questions:
//1) why put m into _mod() ? ?incapsulation
//2) why friend operators ?
//3) why cant i add () const {} to a friend function? ?cuz its like static and theres no current object

#define ll long long

template<int m>
class modint{
	//m < MAXINT/2
	//+ * - are implemented

public:
	modint(ll number):
	_v(number % _mod())
	{}

	modint():
	_v(0)
	{}



	explicit operator ll () const {
		return _v;
	}



	modint& operator+=(const modint& other){
		_v += other._v;
		if(_v >= _mod())
			_v -= _mod();
		return *this;
	}

	modint& operator*=(const modint& other){
		_v *= other._v;
		_v %= _mod();
		return *this;
	}
	modint& operator-=(const modint& other){
		_v -= other;
		if(_v < 0)
			_v += _mod();
		return *this;
	}


	
	friend modint operator+(const modint& x, const modint& y){
		return modint(x) += y;
	}

	friend modint operator-(const modint& x, const modint& y){
		return modint(x) -= y;
	}

	friend modint operator*(const modint& x, const modint& y){
		return modint(x) *= y;
	}



private:
	ll _v;
	static int _mod(){ return m;}

};


} //namespace lynx