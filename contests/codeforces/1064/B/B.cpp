#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	int a,b,n; cin >> a >> b >> n;

	if(abs(min(1.0*b, 1.0*a / n) - b) < 1e-9){
		cout << "1\n";
	}
	else if(a == b){
		cout << "1\n";
	}
	else{
		cout << "2\n";
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