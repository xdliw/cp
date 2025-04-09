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

	vector<int> a(4);
	for(auto& i : a) cin >> i;
	vector<int> b;
	b.push_back(a[0] + a[1]);
	b.push_back(a[2] - a[1]);
	b.push_back(a[3] - a[2]);

	cout << max({count(b.begin(),b.end(),b[0]),count(b.begin(),b.end(),b[1]),count(b.begin(),b.end(),b[2])}) << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}