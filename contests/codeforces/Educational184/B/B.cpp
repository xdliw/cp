#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


void solve(){

	string s; cin >> s;

	int stars = count(s.begin(),s.end(),'*');
	int lessers = count(s.begin(),s.end(),'<');
	int greaters = count(s.begin(),s.end(),'>');
	if(stars >= 2){
		cout << "-1\n";
		return;
	}

	if(greaters){
		auto right = find(s.begin(),s.end(),'>');

		if(count(right,s.end(),'<') || count(right,s.end(),'*')){
			cout << "-1\n";
			return;
		}
	}

	if(lessers){

		auto left = find(s.rbegin(),s.rend(),'<');

		if(count(left,s.rend(),'*')){
			cout << "-1\n";
			return;
		}
		
	}
	cout << max(greaters,lessers) + stars << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t){
		dbg(t);
		solve();
	}

	return 0;
}