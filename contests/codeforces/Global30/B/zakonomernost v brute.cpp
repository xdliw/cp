#include "bits/stdc++.h"
using namespace std;

#define LOCAL

#ifdef LOCAL
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
#endif

#define ll long long

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	vector<int> m = {5000};
	for(int i = m[0]; i < int(1e7); ++i){
		bool add = 1;
		for(auto& j : m){
			if(i % j % 2 == 0){
				add = 0;
				break;
			}
		}
		
		if(add) m.push_back(i);

	}

	for(auto& j : m) cout << j << ' ';

	return 0;
}