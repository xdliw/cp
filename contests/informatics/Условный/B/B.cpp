#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int r; cin >> r;
	cout << "0 " << r << '\n';
	cout << r << " 0\n";
	cout << -r << " 0\n";
	cout << "0 " << -r << '\n';
	cout << r << ' ' << 2 * r << '\n';
	cout << 2 * r << ' ' << r << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int32_t t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}