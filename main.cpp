#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int r(int n){
	if (n == 0) return 0;

	return n + r(n - 1);
}


int main(){
//	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for(int i = 0; i < 10; ++i){
		cout << r(i) << '\n';
	}



	return 0;
}