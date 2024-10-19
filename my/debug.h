#include "bits/stdc++.h"
using namespace std;

#define ll long long

//debug messages
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
//debug messages


//time measurement
void measuretime(void (*f)()){
	
	auto start = chrono::high_resolution_clock::now();
	
	f();
	
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "\n\nDBG : time = " << duration.count() << " ms\n";

}
//time measurement


//for testing by the testing system, cause that's what it's for!
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
//for testing by the testing system, cause that's what it's for!



//todo:
//how to measure memory consumed by a program (actually maybe compiling with limited amount. I saw it with -stacksize or sth)
//configuring a debugger or trying to use gdb it in terminal maybe?
