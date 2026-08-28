#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

int dx[] = {0, 0, -1, 1, 0};
int dy[] = {1, -1, 0, 0, 0};

bool valid(int x, int y, int n, int m){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(){

	int n; cin >> n;
	vector<vector<int>> a(n,vector<int>(n));
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j){
			a[i][j] = i*n + j + 1;
		}
	}

	int ans = 0;
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j){
			int sum = 0;
			for(int k = 0; k < 5; ++k){
				int x = i + dx[k];
				int y = j + dy[k];
				if(valid(x,y,n,n))
					sum += a[x][y];
			}
			ans = max(ans,sum);
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