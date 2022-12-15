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
    cin >>n; 
    vector<pair<int, int>> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; 
        a[i].second = i;
    }
    sort(a.begin(), a.end()); 
    vector<pair<int, int>> ans; 
    for (int i = 1; i < n; i++) {
        int y = ((a[i].first + a[i - 1].first - 1) / a[i - 1].first) * a[i - 1].first; 
        int x = y - a[i].first; 
        while (x > 0) {
            int t = min(a[i].first, x); 
            x -= t; 
            a[i].first += t; 
            ans.push_back({a[i].second + 1, t});
        } 
    }
    cout << (int)ans.size() << endl; 
    for (auto &i : ans) {
        cout << i.first << " " << i.second << endl; 
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