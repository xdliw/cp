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
		int n,x,y; cin >> n >> x >> y;
		x--; //0-ind
		y--; //0-ind
		vector<int> a(n); //0-ind
		for(int i = 0; i < n; ++i){
			a[i] = i & 1;
		}
		if(n & 1){
			a[n - 1] = 2;

			for(int i = 0; i < n; ++i){
				cout << a[(n - 1 - x + i) % n] << ' ';
			}
		}
		else{
			if(a[x] == a[y]) a[x] = 2;

			for(int i = 0; i < n;++i){
				cout << a[i] << ' ';
			}
		}

		cout << '\n';
	 }

	return 0;
}