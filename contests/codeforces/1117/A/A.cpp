#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int n,m; cin >> n >> m;
	map<char,bool> s;
	for(int i = 0; i < n;++i){
		string ss; cin >> ss;
		s[ss[0]] = 1;
	}

	vector<string> abbrs(m);
	for(auto& x : abbrs) cin >> x;

	for(auto& abbr : abbrs){
		for(auto& c : abbr){
			if(!s.contains(tolower(c))){
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}