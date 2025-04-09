#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int n;
vector<int> a;
int ans = 0;

void srch(bool liar,int i = 0, int liars = 0, bool lastliar = 0){
	if(i == n){
		ans++;
		return;
	}

	//check for:
	//cant be 2 consecutive liars
	//true guy said true amount of liars

	//assuming this is not a liar:
	if(!liar){
		a[i] == liars; //has to be equal
	}

	//assuming this is a liar:





	//do/set
	//transition or stop
	//undo/unset

}

void solve(){

	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i;

	srch(0);
	srch(1);
	cout << ans << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}