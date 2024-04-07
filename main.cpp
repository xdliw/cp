#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define DEBUG

#ifdef DEBUG
#define debug(...) (std::cout << "DBG : ", show(std::cout, #__VA_ARGS__, __VA_ARGS__))

template<typename H1>
std::ostream& show(std::ostream& out, const char* label, H1&& value) {
	return out << label << "=" << std::forward<H1>(value) << '\n';
}

template<typename H1, typename ...T>
std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
	const char* pcomma = strchr(label, ',');
	return show(out.write(label, pcomma - label) << "="
							<< std::forward<H1>(value)
							<< ',',
		pcomma + 1,
		std::forward<T>(rest)...);
}
template <class T> void show(const T& v) { for (auto& item : v) { cout << item << ' '; } cout << endl; }
#else
#define debug(...) 0
#define show(x) 0
#endif // DEBUG





void solve(){

    ll n,m,k; cin >> n >> m >> k;
    vector<array<ll,2>> a(n);
    for(int i = 0; i < n;++i){
        int x; cin >> x;
        a[i] = {x,i};
    }

    sort(a.begin(),a.end(), [](array<ll,2> q,array<ll,2> w){

        if(q[0] != q[1]) return q[0] < w[0];
        return q[1] > w[1];

    });

    
    if(debug("sort1")){

        for(auto [v,j] : a){
            debug(v,j);
        }

    }


    ll d = ceil(1.0*k / m);
    debug(d);


    sort(a.begin(),a.begin() + d,[](array<ll,2> q,array<ll,2> w){

        if(q[1] != w[1]) return q[1] > w[1];
        return q[0] < w[0];

    });

    if(debug("sort2")){

        for(int i = 0; i < d;++i){
            int v = a[i][0], j = a[i][1];
            debug(v,i);
        }

    }

    vector<ll> c2(d);
    for(ll i = 0; i < d;++i){
        c2[i] = a[i][0] + i*m;
        debug(a[i][0],i*m,c2[i]);
    }

    sort(c2.begin(),c2.end());

    ll y = (k % m ? k % m : m);
    debug(y);
    ll ans = c2.back()*y;
    debug(c2.back(),ans);


    for(int i = 0; i < c2.size() - 1;++i){
        ans += c2[i]*m;
        debug(i,c2[i]*m,ans);    
    }

    cout << ans << '\n';



}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    while(T--){
        solve();

    }

    return 0;
}