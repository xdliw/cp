#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	for(auto& i : a) cin >> i;
	
	const set<int> take = {2,4,8,269,2*269,4*269,8*269,7487};
	map<int,int> m;
	for(auto& i : a){
		if(take.contains(i))
			m[i]++;
	}

	//just try all 7 combos
	vector<int> ans;

	if(m[2] && m[4] && m[269]){
		ans = {2,4,269};
	}
	else{
		m[1] = 1;
		vector<array<int,3>> combos = {{8*269,1,1},{4*269,2,1},{2*269,4,1},{2*269,2,2},{269,8,1},{269,2,3}};

		for(auto& [q,w,e] : combos){
			if(m[q] > 0 && m[w] >= e){
				ans.push_back(q);
				for(int i = 0; i < e;++i){
					ans.push_back(w);
				}
				break;
			}
		}
	}
	
	if(!m[7487]) ans.clear();
	if(ans.size()){
		ans.push_back(7487);

		for(auto i = ans.size()^ans.size(); i < ans.size(); ++i){
			if(ans[i] == 1){
				ans.erase(ans.begin() + i);
				break;
			}
		}

		// auto one = find(ans.begin(),ans.end(),1);
		// if(one != ans.end()) ans.erase(one);

		cout << ans.size() << '\n';
		for(auto i : ans) cout << i << ' ';	
	}
	else cout << 0;
}