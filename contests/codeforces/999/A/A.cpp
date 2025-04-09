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
		int even = 0, odd = 0;
		for(int i = 0; i < n;++i){
			int x; cin >> x;
			if(x & 1) odd++;
		}
		even = n - odd;

		if(even) cout << odd + 1 << endl;
		else cout << odd - 1 << endl;
		

	}

	return 0;
}