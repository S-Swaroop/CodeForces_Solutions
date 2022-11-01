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
    vector<pair<int , int>> a(n) ;
    for (auto &i : a) {
        cin >> i.first >> i.second ;
        if (i.first > i.second) {
            swap(i.first , i.second) ;
        }
    }
    int max_l = 0 , max_b = 0 , total_l = 0 , total_r = 0 ; 
    for (auto &i : a) {
        total_l += i.first ;
        max_l = max(max_l , i.second) ;
    }
    cout << (total_l + max_l) * 2 << endl ;
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