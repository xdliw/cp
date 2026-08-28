#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define int long long
void solve(){

	int n; cin >> n;
	vector<int> b(n); for(auto& x : b) cin >> x;


	int sum = accumulate(b.begin(),b.end(),0LL);
	int pos = count_if(b.begin(),b.end(),[](int x){return x != 0;});
	dbg(pos);

	cout << min(pos,sum - n + 1) << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}