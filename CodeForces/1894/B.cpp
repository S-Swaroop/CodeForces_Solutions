/*
************************************
* Author : SHARAN SWAROOP          *
* https://linktr.ee/sharan_swaroop *
************************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    map<int, vector<int>> f;
    for (int i = 0; i < n; i++) {
        f[a[i]].push_back(i);
    }
    int x = 0;
    for (auto &[_, t]: f) {
        if (t.size() >= 2) {
            x++;
        }
    }
    if (x >= 2) {
        int y = 0;
        vector<int> b(n, 0);
        b = a;
        for (auto &i: f) {
            if (i.second.size() >= 2) {
                x--;
                b[i.second[0]] = 1 + y;
                for (int j = 1; j < i.second.size(); j++) {
                    b[i.second[j]] = 2 + y;
                }
                y ^= 1;
            } else {
                for (int j = 0; j < i.second.size(); j++) {
                    b[i.second[j]] = 3;
                }
            }
        }
        for (int &i: b) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}