#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

bool search(const vector<string>& s, int n, const vector<int>& perm){
	
	for(int i = 0; i < n; ++i){
		if(s[perm[i]].find('A' + i) == string::npos) return false;
	}
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector<int> perm(n);
	vector<string> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
		perm[i] = i;
	}

	do{
		if(search(s,n,perm)){
			cout << "Yes\n";
			for(int i = 0; i < n;++i){
				cout << char('A' + i) << '.' << s[perm[i]] << '\n';
			}
			return 0;
		}
	}while(next_permutation(perm.begin(),perm.end()));

	cout << "No\n";

	return 0;
}