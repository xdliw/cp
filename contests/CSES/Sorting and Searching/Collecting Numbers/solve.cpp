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

	int n; cin >> n;
	vector<array<int,2>> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i][0];
		a[i][1] = i;
	}

	sort(a.begin(), a.end());

	int pos = a[0][1];
	int ans = 1;
	for(int i = 1; i < n;++i){
		
		if(a[i][1] < pos)
			++ans;
		pos = a[i][1];
	}

	cout << ans << '\n';

	return 0;
}