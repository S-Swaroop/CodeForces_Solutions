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
    int n , q ; 
    cin >> n >> q ; 
    vector<int> row(n) , col(n) ; 
    for (int &i : row)  cin >> i ; 
    for (int &i : col)  cin >> i ;
    vector<int> pref_row(n + 1 , 0) , pref_col(n + 1 , 0) ;
    for (int i = 0 ; i < n ; i++) {
        row[i] %= 2 ;
        col[i] %= 2 ;
        pref_row[i + 1] += pref_row[i] + row[i] ;
        pref_col[i + 1] += pref_col[i] + col[i] ;
    }
    while (q--) {
        int r1 , c1 , r2 , c2 ; 
        cin >> r1 >> c1 >> r2 >> c2 ;
        if (r1 > r2)    swap(r1 , r2) ;
        if (c1 > c2)    swap(c1 , c2) ;
        bool possible = true ;
        possible &= (pref_row[r2] - pref_row[r1 - 1] == (row[r1 - 1] * (r2 - r1 + 1))) ;
        possible &= (pref_col[c2] - pref_col[c1 - 1] == (col[c1 - 1] * (c2 - c1 + 1))) ;
        cout << (possible  ? "YES" : "NO") << endl ;
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}