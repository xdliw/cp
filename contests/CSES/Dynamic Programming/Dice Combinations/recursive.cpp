#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define ll long long

const ll MOD = 1e9 + 7;
const int MX = 1e6 + 1;
ll dp[MX]{};
bool ready[MX]{};

ll r(int n){

	if(ready[n]){
		return dp[n];
	}

	for(int i = 1; i <= 6; ++i){
		if(n - i <= 0) continue;
		dp[n] = (dp[n] + r(n - i)) % MOD;
	}

	ready[n] = 1;

	return dp[n];
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for(int i = 1; i <= 6; ++i){
		dp[i] = 1;
	}
	ready[1] = 1;

	int n; cin >> n;
	cout << r(n) << endl;

	return 0;
}