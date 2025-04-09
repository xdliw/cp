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
	vector<int> a(n);
	for(auto& i : a) cin >> i;

	sort(a.begin(),a.end());

	int pair = 0;
	for(int i = n - 1; i > 0; --i){
		if(a[i] == a[i - 1]){
			pair = a[i];
			a.erase(a.begin() + i - 1);
			a.erase(a.begin() + i - 1);
			break;
		}
	}

	if(pair == 0){
		cout << "-1\n";
		return;
	}

	for(int i = 1; i < a.size();++i){
		if(a[i] - a[i - 1] < 2*pair){
			cout << a[i] << ' ' << a[i - 1] << ' ' << pair << ' ' << pair << '\n';
			return;
		}
	}

	cout << "-1\n";	

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();	
	}

	return 0;
}