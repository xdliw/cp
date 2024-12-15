#include <bits/stdc++.h>
using namespace std;


//sum of digits of a number
//number ABCD = D + C*10 + B*100 + A * 1000 (/10) -> C + B*10 + A*100
int r(int x){
	if(x == 0) return 0;

	int here = x % 10;
	int later = x / 10;

	return here + r(later);
}

int32_t main(){

	for(int i = -100; i <= 0; i++){
		cout << i % 10 << ' ' << i << ' ' << r(i) << '\n';
	}

}