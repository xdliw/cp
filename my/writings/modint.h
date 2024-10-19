namespace lynx{

//theory questions:
//1) why put m into _umod() ? ?incapsulation
//2) why friend operators ?
//3) why cant i add () const {} to a friend function? ?cuz its like static and theres no current object
//4) why in inv_for_prime i can return just pow() and dont have to do this->pow() ?


template<unsigned int m>
class modint{

public:


	modint(): _v(0) {}

	modint(long long v){
		v %= (long long)(_umod());
		if(v < 0)
			v += _umod();
		_v = (unsigned int)(v);
	}






	modint& operator+=(const modint& other){
		_v += other._v;
		if(_v >= _umod())
			_v -= _umod();
		return *this;
	}

	modint& operator*=(const modint& other){
		unsigned long long v = _v;
		v *= other._v;
		_v = (unsigned int)(v % _umod());
		return *this;
	}

	modint& operator-=(const modint& other){
		_v -= other._v;
		if(_v >= _umod())
			_v += _umod();
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


	// friend std::ostream& operator<<(std::ostream& out, const modint& x){
	// 	return out << x._v;
	// }


	unsigned int val () const {
		return _v;
	}

	modint pow(unsigned long long n) const{
		modint res = 1;
		modint x = *this;
		while(n){
			if(n & 1)
				res *= x;
			n >>= 1;
			x *= x;
		}

		return res;
	}

	
	modint inv_for_prime_mod() const {
		return pow(_umod() - 2);
	}



private:
	unsigned int _v;
	static inline unsigned int _umod(){ return m; }

};


} //namespace lynx