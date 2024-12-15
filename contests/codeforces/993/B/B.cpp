#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		string s; cin >> s;
		reverse(s.begin(),s.end());
		for(auto& c : s){
			if(c == 'q') cout << 'p';
			else if(c == 'p') cout << 'q';
			else cout << 'w';
		}

		cout << '\n';
	}

	return 0;
}