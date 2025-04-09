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

	//1-ind
	int n, m; cin >> n >> m;
	vector<array<int,2>> arrsorted(n + 1);
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> arrsorted[i][0];
		arr[i] = arrsorted[i][0];
		arrsorted[i][1] = i;
	}

	sort(arrsorted.begin(), arrsorted.end());
	//now its {{0,0},{1,pos1},...}
	
	for(int i = 0; i <= n; ++i){
		dbg(arrsorted[i][0],arrsorted[i][1]);
	}
	
	int pos = arrsorted[1][1];
	int ans = 1;
	for(int i = 2; i <= n;++i){
		
		if(arrsorted[i][1] < pos)
			++ans;
		pos = arrsorted[i][1];
	}

	dbg("b4loop", ans);

	while(m--){
		int a,b; cin >> a >> b;
		if(a > b) swap(a, b);

		dbg(m,a,b);

		//a to b
		int x = arr[a];
		int posxm1;
		if(x != 1) posxm1 = arrsorted[x - 1][1];
		int posxp1;
		if(x != n) posxp1 = arrsorted[x + 1][1];

		dbg(x,posxm1,posxp1);

		if(x != 1 && a < posxm1 && posxm1 <= b)
			ans--;
		if(x != n && a < posxp1 && posxp1 <= b)
			ans++;
		
		dbg(ans);

		//b to a
		int y = arr[b];
		int posym1;
		if(y != 1) posym1 = arrsorted[y - 1][1];
		int posyp1;
		if(y != n) posyp1 = arrsorted[y + 1][1];

		dbg(y,posym1,posyp1);

		if(y != 1 && a < posym1 && posym1 < b)
			ans++;
		if(y != n && a < posyp1 && posyp1 < b)
			ans--;

		dbg(ans);

		dbg("b4chg",arrsorted[x][1],arrsorted[y][1]);
		for(int i = 0; i <= n; ++i){
			dbg(arr[i]);
		}
		//changing
		swap(arr[a], arr[b]);
		arrsorted[x][1] = b;
		arrsorted[y][1] = a;

		dbg("afchg",arrsorted[x][1],arrsorted[y][1]);
		for(int i = 0; i <= n; ++i){
			dbg(arr[i]);
		}

		cout << ans << endl;
	}


	return 0;
}