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
//	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	deque<array<int,2>> a;

	a.back();
	a.front();

	cout << a.front()[0];

	for(auto& [i,j] : a) cout << i << ' ' << j << endl;

	return 0;
}