#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int n; cin >> n;
	vector<int> a(n); for(auto& x : a) cin >> x;
	string x; cin >> x;

	int pos1 = find(a.begin(),a.end(),1) - a.begin();
	int posn = find(a.begin(),a.end(),n) - a.begin();

	dbg(pos1);
	dbg(posn);
	show(a);

	if(x[0] == '1' | x[n - 1] == '1' | x[pos1] == '1' | x[posn] == '1'){
		cout << "-1\n";
		return;
	}

	cout << "5\n";

	cout << "1 " << n << "\n";
	cout << "1 " << pos1 + 1 << '\n';
	cout << "1 " << posn + 1 << '\n';
	cout << pos1 + 1 << ' ' << n << '\n';
	cout << posn + 1 << ' ' << n << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}