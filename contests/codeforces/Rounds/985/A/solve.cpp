#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define ll long long

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){

		ll l,r,k; cin >> l >> r >> k;

		if(l*k > r){
			cout << "0\n";
			continue;
		}

		ll L = l, R = r;
		while(L < R){
			ll m = (R - L + 1) / 2 + L;
			if(m * k > r) R = m - 1;
			else L = m;
		}

		cout << L - l + 1 << '\n';

	}
	

	return 0;
}