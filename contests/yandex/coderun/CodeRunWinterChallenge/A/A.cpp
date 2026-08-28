#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int r,b; cin >> r >> b;
	cout << (int)(((r / 2 + 2) + sqrtl((r / 2 + 2)*(r / 2 + 2) - 4*(r + b))) / 2) << ' ';
	cout << (int)((r / 2 + 2) - sqrtl((r / 2 + 2)*(r / 2 + 2) - 4*(r + b))) / 2;

	return 0;
}