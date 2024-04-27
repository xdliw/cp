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


const int mod = 1e9 + 7;
const int MAX = 3e5;


#define ll long long
using mint = lynx::modint<mod>;


mint v[MAX + 1];
mint fact[MAX + 1];
// mint inv[MAX + 1];
// mint invfact[MAX + 1];

void init_v(){

	v[0] = 1;
	for(int i = 2; i <= MAX;i += 2){
			v[i] = v[i - 2]*2*(i - 1);
	}

}

void init_fact(){

	fact[0] = 1;
	for(int i = 1; i <= MAX;++i)
		fact[i] = fact[i - 1]*i;
}

// void init_inv(){

// 	inv[1] = 1;
//  	for(int i = 2; i <= MAX; ++i){
// 		inv[i] = -(mod/i)*inv[mod % i];
// 	}

// }
// void init_invfact(){

// 	invfact[0] = 1;

// 	for(int i = 1; i <= MAX;++i){
// 		invfact[i] = invfact[i - 1]*inv[i];
// 	}

// }

mint inline C(int n, int k){
	return fact[n]*((fact[n - k]*fact[k]).inv_for_prime_mod());
}

void solve(){

	int n, k; cin >> n >> k;

	int m = n;
	for(int i = 0; i < k;++i){
		int y,x; cin >> y >> x;
		m -= 1 + (y != x);
	}

	mint ans = 0;

	for(int i = m; i >= 0; i-= 2){
		ans += C(m,i)*v[m - i];
	}

	cout << ans << '\n';

}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	init_v();
	init_fact();

	int T; cin >> T;
	while(T--)
			solve();

	return 0;
}