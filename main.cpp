#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int r(int n){
	if (n == 0) return 0;

	return n + r(n - 1);
}

int main(){
//	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	map<int,int> m = {{},{1,1}};
	for(auto [k,v] : m){
		cout << k << v;
	}

	auto l = m.begin();
	auto r = m.end();
	
	auto L = --l;
	assert(++l == --r);

	for(int i = 0; i < 10;++i){
		cout << (--l)->first;
	}

	return 0;
}