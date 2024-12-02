#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long
#define ul unsigned long

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n,m; cin >> n >> m;
	vector<vector<ul>> v(n, vector<ul>(m));

	v[0][0] = 1;
	for(int i = 0; i < n;++i){
		for(int j = 0; j < m;++j){
			if(i + 1 < n && j + 2 < m){
				v[i + 1][j + 2] += v[i][j];
			}
			if(i + 2 < n && j + 1 < m){
				v[i + 2][j + 1] += v[i][j];
			}
		}
	}
	
	cout << v[n - 1][m - 1] << endl;

	if(dbg(1)){
		while(true){
			int y,x; cin >> y >> x;
			cout << v[y - 1][x - 1] << endl;
		}
	}

	return 0;
}