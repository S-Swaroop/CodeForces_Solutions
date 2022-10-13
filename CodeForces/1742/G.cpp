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
    int n ;
    cin >> n ; 
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ; 
    vector<int> ans ;
    vector<pair<int , int>> f ; 
    for (int &i : a)    f.push_back({i , i}) ;
    sort(f.begin() , f.end()) ;
    int mask = 0 ; // denotes all the bits already present in prefix
    while (!f.empty() && f.back().first > 0) {
        ans.push_back(f.back().second) ;
        mask |= f.back().first ;
        for (int i = 0 ; i < (int)f.size() - 1 ; i++) {
            f[i].first = (mask & f[i].first) ^ f[i].first ; 
        }
        f.pop_back() ;
        sort(f.begin() , f.end()) ;
    }    
    for (auto &i : f) {
        ans.push_back(i.second) ;
    }
    for (int &i : ans) {
        cout << i << " " ;
    }
    cout << endl ;
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