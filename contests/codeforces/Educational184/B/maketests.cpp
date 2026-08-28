#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string s = "><*";

	for(int i = 0; i < s.size(); ++i){
		for(int j = 0; j < s.size(); ++j){
			for(int k = 0; k < s.size(); ++k){
				cout << s[i] << s[j] << s[k] << '\n';
			}
		}
	}

	return 0;
}