#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define ll long long

void yes(bool yes = 1){ cout << (yes? "YES\n" : "NO\n");}


void solve(){

		int n; cin >> n;
		string s,r; cin >> s >> r;

		int zero = 0, one = 0;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '0') zero++;
			else one++;
		}

		for(int i = 0; i < r.size(); ++i){
			if(zero == 0 || one == 0){
				yes(0);
				return;				
			}

			if(r[i] == '0'){
				one--;
			}
			else zero--;

		}

		yes();
}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}
	

	return 0;
}