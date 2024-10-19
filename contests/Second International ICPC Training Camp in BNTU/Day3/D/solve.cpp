#include "bits/stdc++.h"
using namespace std;

#define ll long long

#include "my/debug.h"

//works, but there are leftovers from debugging in the code
//also made tests here and measured time

void assert_tle(bool q){
	static int incme = 0;
	while(!q){
		incme++;
	}
}


void assert_mle(bool q){
	if(q) return;

	const ll big = 1e18;
	vector<ll> inmemoryofmemory(big);
}


const int mod = 998244353;
const int MAXN = 1e5 + 1;
ll a[MAXN], b[MAXN], bprod[4*MAXN], seg[4*MAXN];
int n;
const int debug_depth = 17;

void build_bprod(int depth, int v = 1, int tl = 0, int tr = n - 2){

	assert_mle(depth <= debug_depth);
	
	if(tl == tr){
		bprod[v] = b[tl];
		return;
	}

	int tm = (tl + tr) >> 1;
	build_bprod(depth + 1, 2 * v, tl, tm);
	build_bprod(depth + 1, 2 * v + 1, tm + 1, tr);

	bprod[v] = bprod[2 * v] * bprod[2 * v + 1] % mod;
}


ll get_bprod(int depth, int l, int r, int v = 1, int tl = 0, int tr = n - 2){
	
	assert_mle(depth <= debug_depth);
	
	if(l > r)
		return 1;
	if(tl == l && tr == r)
		return bprod[v];

	int tm = (tl + tr) >> 1;
	
	return 
				get_bprod(depth + 1, l, min(tm, r), 2 * v, tl, tm)
				* get_bprod(depth + 1, max(tm + 1, l), r, 2 * v + 1, tm + 1, tr)
				% mod;

}


void build(int depth, int v = 1, int tl = 0, int tr = n - 1){
	
	assert_mle(depth <= debug_depth);
	
	if (tl == tr){
		seg[v] = a[tl];
		return;
	}

	int tm = (tl + tr) >> 1;
	build(depth + 1, 2 * v, tl, tm);
	build(depth + 1, 2 * v + 1, tm + 1, tr);

	seg[v] = (seg[2 * v] * get_bprod(0, tm, tr - 1) % mod + seg[2 * v + 1]) % mod;
}


ll get(int depth, int l, int r, int v = 1, int tl = 0, int tr = n - 1){
	
	assert_mle(depth <= debug_depth);
	
	if(l > r)
		return 0;
	if(tl == l && tr == r){
		return seg[v];
	}
	int tm = (tl + tr) >> 1;

	return
				(
				get(depth + 1, l, min(tm, r), 2 * v, tl, tm)
				* (tm > r - 1 ? 1 : get_bprod(0, tm, r - 1))
				% mod
				+ get(depth + 1, max(tm + 1, l), r, 2 * v + 1, tm + 1, tr)
				)
				% mod;

}


void solve(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i = 0; i < n;++i){
		cin >> a[i], a[i] %= mod;
	}
	for(int i = 0; i < n - 1;++i){
		cin >> b[i];
	}

	if(n > 1)
		build_bprod(0);
	build(0);


	int q; cin >> q;
	while(q--){
		int l,r; cin >> l >> r; l--, r--;

		cout << get(0, l,r) << '\n';
	}


}

int main(){

	measuretime(solve);

	return 0;
}
