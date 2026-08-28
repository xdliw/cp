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
	vector<int> a(n), b(n);
	for(auto& x : a) cin >> x;
	for(auto& x : b) cin >> x;

	bool odda = count(a.begin(),a.end(),1) & 1;
	bool oddb = count(b.begin(),b.end(),1) & 1;

	if(odda == oddb){
		cout << "Tie\n";
		return;
	}

	for(int i = n - 1; i >= 0; --i){
		if(a[i] != b[i]){
			if(i & 1){
				cout << "Mai\n";
				return;
			}
			else{
				cout << "Ajisai\n";
				return;
			}
		}
	}

	if(odda & 1){
		cout << "Ajisai\n";
	}
	else{
		cout << "Mai\n";
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