#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

const int base = 26;
const int digits = 7; //is enough to represent any number up to 1e9. 1e9 / 26^7 < 1

void first(){

	int n; cin >> n;
	vector<int> a(n); for(auto& x : a) cin >> x;

	string s = "";

	//a = 0 b = 1 ...
	for(auto& x : a){
		for(int i = 0; i < digits; ++i){
			s += (x % base) + 'a';
			x /= base;
		}
	}

	cout << s << '\n';

}

void second(){

	string s; cin >> s;

	cout << s.size() / digits << '\n';
	int x = 0;
	
	for(int i = 0; i < s.size(); ++i){
		int j = i % digits;

		x += (s[i] - 'a') * pow(base,j);
		
		if(j == digits - 1){
			cout << x << ' ';
			x = 0;
		}
	}

	cout << '\n';

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