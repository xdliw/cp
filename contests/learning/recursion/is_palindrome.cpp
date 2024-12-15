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

/* check if string is a palindrome 

1234321
123321
*/

bool is(const string& s){

	if(s.size() == 0 || s.size() == 1)
		return true;

	if(s.front() != s.back())
		return false;

	string next = string(s, 1, s.size() - 2); //shrink by 1 on each end

	return is(next);
}

int32_t main(){
	int T; cin >> T;
	while(T--){
		string s; cin >> s;
		cout << s << " " << is(s) << '\n';
	}
}