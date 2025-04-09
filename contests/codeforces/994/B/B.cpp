#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

void yes(bool yes = 1){cout << (yes? "YES\n" : "NO\n");}

void solve(){

	int n; cin >> n;
	string s; cin >> s;

	int ss = 0, pp = 0;
	for(int i = 0; i < n;++i){
		if(i != 0 && i != n - 1){
			if(s[i] == 's') ss++;
			if(s[i] == 'p') pp++; 
		}
	}

	if(find(find(s.begin(),s.end(),'p'),s.end(),'s') != s.end()){
		yes(0);
		return;
	}
	//now no p before s

	if(pp == 0 || ss == 0){
		yes();
		return;	
	}

	yes(0);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}