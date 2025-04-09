#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif

//subtract one
void subone(deque<array<int,2>>& d){
	for(auto& [f,s] : d){
		f--;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n,m; cin >> n >> m;
	vector<string> field(n);
	for(auto& s : field){
		cin >> s;
	}

	//number of stars, index
	deque<array<int,2>> rows(n), cols(m);
	for(int i = 1; i <= n; ++i){
		rows[i - 1][1] = i;
	}
	for(int i = 1; i <= m; ++i){
		cols[i - 1][1] = i;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			bool x = field[i][j] == '*';
			rows[i][0] += x;
			cols[j][0] += x;
		}
	}

	sort(rows.begin(),rows.end());
	sort(cols.begin(),cols.end());

	vector<array<string,3>> ans;
	while(!rows.empty() || !cols.empty()){
		
		//can delete row of all dots
		if(!rows.empty() && rows.front()[0] <= 0){
			array<string,3> a = {"r",to_string(rows.front()[1]),"."};
			ans.push_back(a);
			rows.pop_front();
		}
		//can delete row of all stars
		else if(!rows.empty() && rows.back()[0] >= cols.size()){
			array<string,3> a = {"r",to_string(rows.back()[1]),"*"};
			ans.push_back(a);
			rows.pop_back();
			subone(cols);				
		}
		//can delete column of all dots
		else if(!cols.empty() && cols.front()[0] <= 0){
			array<string,3> a = {"c",to_string(cols.front()[1]),"."};
			ans.push_back(a);
			cols.pop_front();
		}
		//can delete column of all stars
		else if(!cols.empty() && cols.back()[0] >= rows.size()){
			array<string,3> a = {"c",to_string(cols.back()[1]),"*"};
			ans.push_back(a);
			cols.pop_back();
			subone(rows);				
		}
		else{
			cout << "-1\n";
			return 0;
		}
	}

	reverse(ans.begin(),ans.end());
	cout << ans.size() << '\n';
	for(auto& s : ans){
		cout << s[0] << ' ' << s[1] << ' ' << s[2] << '\n';
	}

	return 0;
}