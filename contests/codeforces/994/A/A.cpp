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
		int c = 0;
		vector<int> a(n); for(auto& i : a){
			cin >> i;
			if(!i) c++;
		}

		if(c == n){
			cout << "0\n";
			continue;
		}

		for(int i = 0; i < n && !a[i];++i) c--;
		for(int i = n - 1; ~i && !a[i];--i) c--;

		cout << (c == 0 ? 1 : 2) << '\n';

	}
	return 0;
}