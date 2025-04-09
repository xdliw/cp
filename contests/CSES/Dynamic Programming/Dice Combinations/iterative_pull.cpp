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


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for(int i = 1; i <= 6; ++i){
		dp[i] = 1;
	}

	int n; cin >> n;

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 6; ++j){
			(dp[i] += (i - j > 0 ? dp[i - j] : 0)) %= MOD;
		}
	}
	
	cout << dp[n] << endl;

	return 0;
}