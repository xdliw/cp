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

		int m,a,b,c; cin >> m >> a >> b >> c;
		cout << min(2*m, min(a,m) + min(b,m) + c) << '\n';
	}

	return 0;
}