#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		vector<int> a(n); for(auto& i : a) cin >> i;
		set<int> was;
		vector<int> b;

		for(auto& i : a){
			if(was.contains(i)) continue;

			was.insert(i);
			b.push_back(i);
		}

		for(int i = 1; i <= n;++i){
			if(was.contains(i)) continue;

			b.push_back(i);
		}

		for(auto& i : b) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}