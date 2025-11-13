#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif



void first(){

	int n; cin >> n;
	vector<int> a(n); for(auto& x : a) cin >> x;

	string s = "";

	//a = 0 b = 1 ...
	for(auto& x : a){
		for(int i = 0; i < 10; ++i){
			s += (x % 10) + 'a';
			x /= 10;
		}
	}

	cout << s << '\n';

}

void second(){

	string s; cin >> s;

	cout << s.size() / 10 << '\n';
	int x = 0;
	
	for(int i = 0; i < s.size(); ++i){
		int j = i % 10;

		x += (s[i] - 'a') * pow(10,j);
		
		if(j == 9){
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