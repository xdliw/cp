#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

int odd(vector<int>& a, int mask){
	int x = 0;
	for(auto& y : a) x ^= y & mask;
	return x;
}

void solve(){

	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto& x : a) cin >> x;
	for(auto& x : b) cin >> x;

	for(int k = 19; k >= 0; --k){
		int mask = 1 << k;

		bool odda = odd(a, mask);
		bool oddb = odd(b, mask);

		//Tie
		if(odda == oddb){
			if(k > 0){
				continue;
			}
			else{
				cout << "Tie\n";
				return;
			}
		}

		for(int i = n - 1; i >= 0; --i){
			if((a[i] & mask) != (b[i] & mask)){
				if(i & 1){
					cout << "Mai\n";
					return;
				}
				else{
					cout << "Ajisai\n";
					return;
				}
			}
		}

		if(odda & 1){
			cout << "Ajisai\n";
		}
		else{
			cout << "Mai\n";
		}

	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}