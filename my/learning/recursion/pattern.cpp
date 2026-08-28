#include <bits/stdc++.h>
using namespace std;

/* 
1 what are we doing at this state?
2 how do we transition between states (to the base state)?
3 what is base state?
*/

//pattern printing:
/*
1
1 2
1 2 3
...
1 2 3 ... n - 1
1 2 3 ... n
 */

//is it possible to make it all in one function only via recursion?
//i don't think it is

void rr(int n){
	if(n == 0) return;

	rr(n - 1);
	cout << n << ' ';

}
void r(int n){
	if(n == 0) return;

	r(n - 1);
	rr(n); cout << '\n';

}



int32_t main(){

	r(20);
	
}