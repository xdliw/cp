#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define int long long

void solve(){
	//0-ind everywhere

	int n; cin >> n;
	vector<int> a(n); for(auto& x : a) cin >> x;

	int cost = 0;
	vector<array<int,2>> b(n);
	set<int> remaining; //indexes
	for(int i = 0; i < n; ++i){
		b[i] = {a[i], i};
		remaining.insert(i);
	}
	sort(b.begin(),b.end());

	for(int j = 0; j < n - 1; ++j){
		int i = b[j][1];

		//neighbors
		auto left = remaining.find(i);
		if(left == remaining.begin())
			left = --remaining.end();
		else
			--left;

		auto right = remaining.find(i);
		if(right == --remaining.end())
			right = remaining.begin();
		else
			++right;

		cost += min(a[*left],a[*right]);
		remaining.erase(i);
		
	}

	cout << cost << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}