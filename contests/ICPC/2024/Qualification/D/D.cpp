#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#define dbg(...) (std::cout << "DBG : ", show(std::cout, #__VA_ARGS__, __VA_ARGS__))

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
#define dbg(...) 0
#define show(x) 0
#endif // DEBUG

#define ll long long


void solve(){

	ll n,m,s,t; cin >> n >> m >> s >> t;
	vector<ll> a(n); //0-ind
	for(int i = 1; i < n;++i) cin >> a[i];
	vector<vector<int>> adj(n);

	for(int i = 0; i < m;++i){
		int x,y; cin >> x >> y; --x,--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;
	vector<bool> visited(n);
	vector<ll> distance(n);

	visited[0] = 1;
	distance[0] = 0;
	q.push(0);

	while(!q.empty()){ //найти distance до каждой
		int u = q.front(); q.pop();

		for(auto v : adj[u]){
			if(visited[v]) continue;
			visited[v] = 1;
			distance[v] = distance[u] + 1;
			q.push(v);
		}
	}



	ll time = 0;
	for(int i = 1; i < n; ++i){
		distance[i] *= 2 * s;
		distance[i] += t * a[i];
		if(!a[i]) distance[i] = 0;
		time = max(time, distance[i]);
	}



	//перевести в формат

	ll days = 0,H = 11,M = 0,S = 0;
	S = time;
	M = S / 60; S %= 60;
	H += M / 60; M %= 60;
	days = H / 24; H %= 24;

	//вывод

	if(H < 10) cout << 0;
	cout << H << ':';
	if(M < 10) cout << 0;
	cout << M << ':';
	if(S < 10) cout << 0;
	cout << S;
	if(days > 0){
		cout << "+" << days << "d";
	}
	cout << '\n';

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while(T--){
		solve();
	}

	return 0;
}
