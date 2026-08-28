#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

const int mod = 1e9 + 7;

void solve(){

	int M, N; cin >> M >> N;
	map<int,int> count;
	count[0] = 0;
	vector<int> a(N); for(auto& x : a) cin >> x, ++count[x];
	vector<array<int,2>> w;
	for(auto& [x,c] : count)
		w.push_back({x,c});

	int ans = 0;
	for(int i = w.size() - 1; i > 0; --i){ //0-ind but we've added a 0
		int x = w[i][0];
		int y = w[i - 1][0];
		int c = w[i][1];
		int d = x - y;
		dbg(i,x,y,c,d,M);
		if(d * c <= M){ //what is max Wi?
			w[i - 1][1] += c;
			M -= d * c;
		}
		else{
			int sub = M / c;
			int m = M % c;
			ans +=
			(
			(x - sub - 1) * (x - sub - 1) % mod
			* m % mod
			+ (x - sub) * (x - sub) % mod
			* (c - m) % mod
			)
			% mod;

			dbg(M,c,x);

			for(int j = 1; j < i; ++j)
				ans += w[j][0] * w[j][0] % mod * w[j][1] % mod;

			break;
		}
	}

	cout << ans % mod << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}