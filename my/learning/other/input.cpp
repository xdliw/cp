#include "bits/stdc++.h"
using namespace std;

void solve(){

	//ввод чисел до конца входного файла (когда например, неизвестно сколько всего будет подано на вход)
	int x;
	while(cin >> x){
		//
	}

	return;

	//ввод символов до конца входного файла
	char c;
	while(cin.get(c)){
		cout << c << '\n';
	}

	return;

	//ввод строк до конца входного файла
	string line;	
	while(getline(cin, line)){
		int spaces = 0;
		for(auto& c: line) if(c == ' ') ++spaces;
		cout << "Number of spaces: " << spaces << ". Line:\n";
		cout << line << '\n';
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int32_t tt = 1;
	while(tt--){
		solve();
	}

	return 0;
}