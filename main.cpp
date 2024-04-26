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











#include "myLibraries/modint.cpp"


const int mod = 1e9 + 7;
const int MAX = 3e5 + 5;


#define ll long long
using mint = lynx::modint<mod>;


mint v[MAX];

void init_v(int n){

	v[0] = 1;
	for(mint i = 2; (ll)(i) <= n;i += 2){
			
	}

}

void solve(){

	int n, k; cin >> n >> k;

	int m = n;
	for(int i = 0; i < k;++i){
		int y,x; cin >> y >> x;
		m -= 1 + (y != x);
	}

	

}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	mint q = 1e9 + 6;
	cout << (ll)(q) << ' ' << (ll)(q + mod) << ' ' << (ll)(q + 1) << '\n';

	q + 1;
	q + 2;


	return 0;


	int T; cin >> T;
	while(T--)
			solve();

	return 0;
}