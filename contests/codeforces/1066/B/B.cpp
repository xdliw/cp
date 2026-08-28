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

	int n, x, y; cin >> n >> x >> y;
	string s; cin >> s;

	x = abs(x); y = abs(y);
	int fours = count(s.begin(),s.end(),'4');
	int eights = s.size() - fours;

	x -= eights; y -= eights;

	for(int i = 0; i <= fours; ++i){
		if(x - (fours - i) <= 0 && y - i <= 0){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}