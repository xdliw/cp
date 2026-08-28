#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

#define ll long long

void solve(){

	ll s,q; cin >> s >> q;

	vector<ll> divs;
	for(ll div = 1; div * div <= s; ++div){
		if(s % div == 0){
			divs.push_back(div);
			if(div * div != s)
				divs.push_back(s / div);
		}
	}

	assert(divs.size() == divs.end() - divs.begin());

	sort(divs.begin(),divs.end());

	vector<ll> pref(divs.size());
	for(ll i = 0; i < divs.size(); ++i){
		if(i == 0){
			pref[i] = divs[i] * (s / divs[i]);
			continue;
		}

		pref[i] += pref[i - 1] + (divs[i] - divs[i - 1]) * (s / divs[i]);
	}

	while(q--){
		ll x,y; cin >> x >> y;
		ll ans = 0;

		ll iddiv = lower_bound(divs.begin(),divs.end(),x) - divs.begin();
		if(divs[iddiv] >= x && s / divs[iddiv] >= y){
			cout << x * y << '\n';
			continue;
		}
		
		if(x != s){
			ll iddivx = lower_bound(divs.begin(),divs.end(), x + 1) - 1 - divs.begin();
			ans += pref[iddivx];

			ll hx = s / divs[iddivx + 1];
			ll dx = x - divs[iddivx];
			ans += hx * dx;
		}
		else ans += pref.back();

		if(y != s){
			ll iddivy = lower_bound(divs.begin(),divs.end(), y + 1) - 1 - divs.begin();
			ll cut = pref.back() - pref[iddivy];
			ans -= cut;

			ll hy = s / divs[iddivy + 1];
			ll dy = y - divs[iddivy];
			ans += hy * dy;
		}

		cout << ans << '\n';

	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int32_t T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}