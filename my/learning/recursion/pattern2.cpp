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

//pattern printing:
/*
1 2 3 ... n
1 2 3 ... n-1
...
1 2 3
1 2
1
1 2
1 2 3
...
1 2 3 ... n-1
1 2 3 ... n
*/


void print_row(int n){
	if(n == 0) return;

	print_row(n - 1);
	cout << n << ' ';
}

void r(int n){
	if(n == 1){
		cout << "1\n";
		return;
	}

	print_row(n); cout << '\n';
	r(n - 1);
	print_row(n); cout << '\n';

}


int32_t main(){
	r(20);	
}