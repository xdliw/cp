#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

void solve(){

	int a,b,c,d; cin >> a >> b >> c >> d;

	if(a == 0){
		if(b == 0)
			cout << "INF\n";
		else
			cout << "NO\n";
	}
	else if(b % a == 0){
		int ans = - b / a;
		if(c != 0 && d % c == 0 && ans == - d / c)
			cout << "NO\n";
		else
			cout << ans << '\n';
	}
	else
		cout << "NO\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T = 1;
	while(T--) solve();
	
	return 0;
}