#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){



}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<array<int,3>> v = {{3,2,1}, {1,3,2}, {1,2,3}};

	sort(v.begin(),v.end());

	for(auto& [q,w,e] : v) cout << q << ' ' << w << ' ' << e << '\n';
	
	return 0;
}