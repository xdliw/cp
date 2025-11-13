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

	int n; cin >> n;
	deque<int> d;
	for(int i = 0; i < n;++i){
		int x; cin >> x;
		d.push_back(x);
	}
	d.push_back(d.back());
	d.push_front(d.front());

	for(int i = 0; i < n;++i){
		d
	}
	

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}