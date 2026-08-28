#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

int pref(const vector<int>& pref, int i){
	if(i < 0) return 0;
	return pref[i];
}

bool matches(int x, int y, const vector<int>& p0, const vector<int>& p1, int c0, int c1){
	if(0){
		if(x == 0){
			dbg(x, y, p0[y] - 0, c0 / 2);
			dbg(x, y, p1[y] - 0, c1 / 2);
		}
		else{
			dbg(x, y, p0[y], p0[x - 1], c0 / 2);
			dbg(x, y, p1[y], p1[x - 1], c1 / 2);
		}
	}
	return (pref(p0, y) - pref(p0, x - 1) == c0 / 2) && (pref(p1, y) - pref(p1, x - 1) == c1 / 2);
}


void solve(){

	int n,q; cin >> n >> q;
	string s; cin >> s;
	vector<int> p0(n), p1(n); //pref
	for(int i = 0; i < n; ++i){
		if(i) p0[i] = p0[i - 1];
		if(i) p1[i] = p1[i - 1];
		if(s[i] == '0') p0[i]++;
		else p1[i]++;
	}

	if(dbg(n)){
		cout << s << " s\n";
		for(int i = 0; i < n; ++i){
			cout << p0[i];
		}
		cout << " p0\n";
		for(int i = 0; i < n; ++i){
			cout << p1[i];
		}
		cout << " p1\n";
	}

	while(q--){
		int l,r; cin >> l >> r;
		--l, --r;
		
		int c0 = pref(p0, r) - pref(p0, l - 1);
		int c1 = pref(p1, r) - pref(p1, l - 1);

		if(((r - l + 1) & 1) || (c1 & 1)){
			dbg(r - l + 1, c0, c1);
			cout << "-1\n";
			continue;
		}

		auto u0 = upper_bound(p0.begin(), p0.end(), c0 / 2 + pref(p0, l - 1));
		auto u1 = upper_bound(p1.begin(), p1.end(), c1 / 2 + pref(p1, l - 1));

		int id0 = u0 - p0.begin();
		int id1 = u1 - p1.begin();

		int aa = min(id0, id1);
		int bb = max(id0, id1);

		int have0 = pref(p0, bb) - pref(p0, aa - 1);
		int have1 = pref(p1, bb) - pref(p1, aa - 1);

		int left0 = c0 / 2 - have0;
		int left1 = c1 / 2 - have1;

		auto u0r = lower_bound(p0.begin(), p0.end(), pref(p0, bb) + left0);
		auto u1r = lower_bound(p1.begin(), p1.end(), pref(p1, bb) + left1);
		auto u0l = lower_bound(p0.begin(), p0.end(), pref(p0, aa) - left0 + 1);
		auto u1l = lower_bound(p1.begin(), p1.end(), pref(p1, aa) - left1 + 1);

		int id0r = u0r - p0.begin();
		int id1r = u1r - p1.begin();
		int id0l = u0l - p0.begin();
		int id1l = u1l - p1.begin();

		if(dbg(l, r, id0, id1, aa, bb, c0, c1, have0, have1, left0, left1, id0r, id1r, id0l, id1l)){
			for(int i = l; i <= r; ++i){
				cout << s[i];
			}
			cout << " s\n";
			
			for(int i = l; i <= r; ++i){
				cout << p0[i];
			}
			cout << " p0\n";
			
			for(int i = l; i <= r; ++i){
				cout << p1[i];
			}
			cout << " p1\n";
		}

		//0-ind to 1-ind
		if(matches(aa, id0r, p0, p1, c0, c1)){
			cout << aa + 1 << ' ' << id0r + 1 << '\n';
			continue;
		}
		if(matches(aa, id1r, p0, p1, c0, c1)){
			cout << aa + 1 << ' ' << id1r + 1 << '\n';
			continue;
		}
		if(matches(id0l, bb, p0, p1, c0, c1)){
			cout << id0l + 1 << ' ' << bb + 1 << '\n';
			continue;
		}
		if(matches(id1l, bb, p0, p1, c0, c1)){
			cout << id1l + 1 << ' ' << bb + 1 << '\n';
			continue;
		}

		assert(false);
	}


}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int32_t t = 1;
	while(t--){
		solve();
	}

	return 0;
}