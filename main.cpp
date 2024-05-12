#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#define debug(...) (std::cout << "DBG : ", show(std::cout, #__VA_ARGS__, __VA_ARGS__))

template<typename H1>
std::ostream& show(std::ostream& out, const char* label, H1&& value) {
	return out << label << "=" << std::forward<H1>(value) << '\n';
}

template<typename H1, typename ...T>
std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
	const char* pcomma = strchr(label, ',');
	return show(out.write(label, pcomma - label) << "="
							<< std::forward<H1>(value)
							<< ',',
		pcomma + 1,
		std::forward<T>(rest)...);
}
template <class T> void show(const T& v) { for (auto& item : v) { cout << item << ' '; } cout << endl; }
#else
#define debug(...) 0
#define show(x) 0
#endif // DEBUG



#include "myLibraries/modint.h"

#define ll long long


void parse_str(const string& s, vector<int>& v){
	int cur = 0;

	for(int i = 0; i < s.size();++i){
		if(s[i] >= '0' && s[i] <= '9'){
			cur *= 10;
			cur += s[i] - '0';
		}
		else{
			v.push_back(cur);
			cur = 0;
		}

	}

}


int main(){
	// ios_base::sync_with_stdio(0);cin.tie(0);


	const int m = 41;

	using mint = lynx::modint<m>;


	string s;
	getline(cin, s);

	vector<int> v;
	parse_str(s,v);


	s = "";
	for(auto& i : v){
		i %= m;

		mint q = i;
		i = q.inv_for_prime_mod().val();

		if(i <= 26){
			s += 'A' + i - 1;
		}
		else if(i <= 36){
			s += '0' + i - 27;
		}
		else
			s += '_';
	}

	string ss = "1NV3R53LY_H4RD_8A05D939";

	cout << (s == ss) << '\n';



	return 0;
}