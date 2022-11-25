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
    vector<int> a ;
    if (n & 1) {
        a.push_back(n) ;
    }
    int l = n - 1 , r = n + 1 ;
    while ((int)a.size() < n) {
        a.push_back(l) ;
        a.push_back(r) ;
        l-- ; 
        r++ ;
    }
    sort(a.begin() , a.end()) ;
    if (n & 1) {
        for (int &i : a)    i += 2 ;  
        a[n - 1]++ ;
        a[0]-- ;
        a[n - 2]++ ;
    }
    for (int &i : a) {
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