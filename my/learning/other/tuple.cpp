#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "libraries/algo(tourist's)/misc/dbg.h"
#else
#define debug(...) 0
#endif


void solve(){

	tuple<int, string, map<int, int>, vector<int>, int, int> tup = {1, "2", {}, {3,4,5}, {}, {}};
	auto q = get<0>(tup);
	auto w = get<1>(tup);
	auto e = get<2>(tup);
	auto r = get<3>(tup);
	auto t = get<4>(tup);
	int y = 8;

	e[6] = 7;

	auto tup2 = tie(q, w, e, r, t, y) = tup; //tie both unpacks tup into variables and returns a tuple of references to these variables. Thus tup2 is the tuple of references. Thus y is assigned 0, because 6th element (index = 5) in tup is 0.
	e[67];

	debug(tup == tup2); //false, since e was modified and tup2 has a reference on e. Despite that, tup is equal to tup2.
	debug(q);
	debug(w);
	debug(e);
	debug(r);
	debug(t);
	debug(y);
	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int32_t tt = 1;
	while(tt--){
		solve();
	}

	return 0;
}