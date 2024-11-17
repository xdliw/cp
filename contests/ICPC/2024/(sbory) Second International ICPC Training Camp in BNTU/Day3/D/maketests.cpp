#include "bits/stdc++.h"
using namespace std;

#define ll long long

#ifdef LOCAL
#include "my/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

auto rng = mt19937_64(time(0));

void maketest(const string& testname = "test.txt", int n = 1e5, int q = 1e5, int amin = 1, int amax = 1e9, int bmin = 1, int bmax = 1e8, int lmin = 1, int lmax = 1e2, int rmin = 1e5 - 1e2, int rmax = 1e5){

	ofstream f(testname);

	f << n << '\n';
	for(int i = 0; i < n; ++i){
		f << rng() % (amax + 1 - amin) + amin << ' ';
	}
	f << '\n';
	for(int i = 0; i < n - 1; ++i){
		f << rng() % (bmax + 1 - bmin) + bmin << ' ';
	}
	f << '\n';
	f << q << '\n';

	for(int i = 0; i < q; ++i){
		f << rng() % (lmax + 1 - lmin) + lmin << ' ';
		f << rng() % (rmax + 1 - rmin) + rmin << '\n';
	}

}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);

	const string foldername = "tests/";
	for(int i = 1; i <= 100; ++i){
		const string testname = to_string(i);
		maketest(foldername + testname);
	}


	return 0;
}
