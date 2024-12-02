#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "my/writings/debug.h"
#else
#define dbg(...) 0
#define show(x) 0
#endif


#define ll long long

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--){
        int n,twos; cin >> n >> twos;

        if(twos < n - 2){
            cout << "NO\n";
        }
        else if(twos == n - 2){
            vector<array<int,2>> up, down;
            up.push_back({0,0});
            down.push_back({0,1});
            array<int,2> cur = {0,0};
            int dx[] = {1,0}, dy[] = {1,-1};
            for(int i = 0; i < n - 2; ++i){
                cur[0] += dx[i % 2];
                cur[1] += dy[i % 4 / 2];
                if((i + 1) % 4 / 2)//down
                    down.push_back(cur);
                else
                    up.push_back(cur);
            }


            cout << "YES\n";
            for(auto& [x,y] : up){
                cout << x << " " << y << '\n';
            }
            reverse(down.begin(),down.end());
            for(auto& [x,y] : down){
                cout << x << " " << y << '\n';
            }
        }
        else{
            twos -= n - 3;
            array<int,2> shot = {0,0};
            vector<array<int,2>> up, down;
            up.push_back({twos,0});
            down.push_back({twos,1});
            array<int,2> cur = {twos,0};
            int dx[] = {1,0}, dy[] = {1,-1};
            for(int i = 0; i < n - 3; ++i){
                cur[0] += dx[i % 2];
                cur[1] += dy[i % 4 / 2];
                if((i + 1) % 4 / 2)//down
                    down.push_back(cur);
                else
                    up.push_back(cur);
            }
            

            cout << "YES\n";
            cout << shot[0] << " " << shot[1] << '\n';

            for(auto& [x,y] : up){
                cout << x << " " << y << '\n';
            }
            reverse(down.begin(),down.end());
            for(auto& [x,y] : down){
                cout << x << " " << y << '\n';
            }
            
        }

    }

}