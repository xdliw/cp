#include <bits/stdc++.h>
using namespace std;

/*
1 what are we doing at this state?
2 how do we transition between states (to the base state)?
3 what is base state?

remember: greenboxing the subproblem
*/


/*
Maybe try to prove recursion via mathematical induction.
In mathematical induction theres like: (examples in brackets)
(1) base case (1case)
(2) general case (ncase)
(3) following case (n+1case)

example:
	if 1case is correct AND n+1 is true for n -> 1,2,...n,n+1,... are correct
generalized:
	if (1) is correct AND (3) is true for (2) -> (1),next((1)),...,(2),(3),... are correct

*/

/* 
C(n,r) = C(n-1,r-1) + C(n-1,r)
C(n,r) = n!/((n-r)!*r!)

*/

int C(int n, int r){ return (r == 0 || r == n ? 1 : C(n - 1,r - 1) + C(n - 1,r)); }
int f(int n){ return (n? n*f(n - 1) : 1); }
int c(int n, int r){ return f(n) / f(r) / f(n - r); }


int32_t main(){

	for(int i = 0; i <= 10; ++i){
		for(int j = 0; j <= i;++j){
			int RES = C(i,j);
			int res = c(i,j);
			cout << "C(" << i << "," << j << ") = " << RES << '\n';
			if(RES != res){
				cout << "c(" << i << "," << j << ") = " << res << '\n';
				cout << "-------------------- C != c --------------------\n";
			}
		}
	}
}
