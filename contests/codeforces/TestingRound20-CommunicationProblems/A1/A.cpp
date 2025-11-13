#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

void first(){

	int n; cin >> n;
	vector<int> a(n); for(auto& i: a) cin >> i;
	string s = "";

	for(auto i: a){
		s += i + 'a' - 1;
	}

	cout << s << '\n';
}

void second(){

	string s; cin >> s;
	cout << s.size() << '\n';

	for(auto c : s){
		cout << c - 'a' + 1 << ' '; 
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string T; cin >> T;
	if(T == "first")
		first();
	else
		second();
	return 0;

}