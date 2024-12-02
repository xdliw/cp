#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

bool debug = 0;

#define ll long long
#define ull unsigned long long


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if(dbg("debug is on")) debug = 1;

	int n,m; cin >> n >> m;

	vector<vector<ull>> dp(n,vector<ull>(m));
	dp[0][0] = 1;

	vector<int> dy = {-1,1,2,2};
	vector<int> dx = {2,2,1,-1};
	
	//for every diagonal up to the main one
	for(int i = 0; i < n;++i){
		for(int ii = i, j = 0; ii >= 0 && j < m; ii--, j++){

			//all 4 moves
			const int k = dy.size();
			for(int id = 0; id < k;++id){
				int newy = ii + dy[id];
				int newx = j + dy[k - 1 - id];
				//if we can get there add count
				if(newy >= 0 && newy < n && newx >= 0 && newx < m){
					if(debug){
						auto peril = 1.0L * dp[newy][newx] + dp[ii][j];
						if(peril > ULLONG_MAX){
							dbg(peril, ii, j, newy, newx);
						}
					}
					dp[newy][newx] += dp[ii][j];
				}
			}
		}
	}

	//for all diagonals that are left
	for(int j = 1; j < m;++j){
		for(int ii = n - 1, jj = j; ii >= 0 && jj < m; ii--, jj++){

			//all 4 moves
			const int k = dy.size();
			for(int id = 0; id < k;++id){
				int newy = ii + dy[id];
				int newx = jj + dy[k - 1 - id];
				//if we can get there add count
				if(newy >= 0 && newy < n && newx >= 0 && newx < m){
					if(debug){
						auto peril = 1.0L * dp[newy][newx] + dp[ii][j];
						if(peril > ULLONG_MAX){
							dbg(peril, ii, j, newy, newx);
						}
					}
					dp[newy][newx] += dp[ii][jj];
				}
			}
		}
	}

	cout << dp[n - 1][m - 1] << endl;

	if(dbg(1)){
		for(auto& v : dp){
			for(auto& i : v){
				cout << i << "\t";
			}
			cout << endl;
		}
	}	

	return 0;
}