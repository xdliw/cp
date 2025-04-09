#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

void solve(){

	int n,m,L; cin >> n >> m >> L;
	vector<array<int,2>> hurdle(n);
	for(auto& [f,s] : hurdle){
		cin >> f >> s;
	}
	queue<array<int,2>> powerup;
	for(int i = 0; i < m; ++i){
		int x,v; cin >> x >> v;
		powerup.push({x,v});
	}

	int ans = 0, k = 1, x = 1;
	priority_queue<int> cantake;
	for(int i = 0; i < n;++i){
		int l = hurdle[i][0];
		int r = hurdle[i][1];
		x = l - 1;

		//remembering powerups that we can take
		while(!powerup.empty() && powerup.front()[0] <= x){
			cantake.push(powerup.front()[1]);
			powerup.pop();
		}

		while(x + k <= r){
			if(cantake.empty()){
				cout << "-1\n";
				return;
			}

			k += cantake.top();
			cantake.pop();
			ans++;
		}

	}

	cout << ans << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}