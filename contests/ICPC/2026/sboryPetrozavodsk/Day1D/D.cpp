#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define ll long long

const ll MOD = 998244353;

bool has_one_black_line(const string& s, int start){
	auto first = s.find('#', start);
	if(first == string::npos) return false;
	
	auto last = s.rfind('#');
	auto dot = s.find('.',first);
	if(dot < last) return false;

	return true;
}

ll calculate(int h, int w, const vector<string>& grid, const vector<string>& gridT, vector<vector<ll>>& dp, vector<vector<ll>>& suf, int i, int j){
	if(i == h || j == w || !suf[i][j]) return 1;
	if(dp[i][j] != -1) return dp[i][j];

	//h-transition
	ll res1 = 0;
	if(has_one_black_line(grid[i], j)) res1 = calculate(h, w, grid, gridT, dp, suf, i + 1, j);

	//w-transition
	ll res2 = 0;
	if(has_one_black_line(gridT[j], i)) res2 = calculate(h, w, grid, gridT, dp, suf, i, j + 1);

	return dp[i][j] = (res1 + res2) % MOD;

}


bool valid(int h, int w, int i, int j){
	return 0 <= i && i < h && 0 <= j && j < w;
}

void solve(){

	int h, w; cin >> h >> w;
	vector<string> grid(h);
	for(auto& s: grid) cin >> s;

	//transpose grid to comfortably check for transitions
	vector<string> gridT(w);
	for(auto& s: gridT) s.resize(h);
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			gridT[j][i] = grid[i][j];
		}
	}

	vector<vector<ll>> dp(h);
	for(auto& v: dp) v.resize(w);
	for(auto& v: dp)
		for(auto& el: v)
			el = -1;

	//suffix matrix for count of hashes
	vector<vector<ll>> suf(h, vector<ll>(w));
	for(int i = h - 1; i >= 0; --i){
		for(int j = w - 1; j >= 0; --j){
			 suf[i][j] = (grid[i][j] == '#')
			 + (valid(h, w, i + 1, j) ? suf[i + 1][j] : 0)
			 + (valid(h, w, i, j + 1) ? suf[i][j + 1] : 0)
			 - (valid(h, w, i + 1, j + 1) ? suf[i + 1][j + 1] : 0);
		}
	}

	if(dbg("suf")){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cout << suf[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	cout << calculate(h, w, grid, gridT, dp, suf, 0, 0) << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int32_t t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}