/*
***************************
* Author : SHARAN SWAROOP *
***************************
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
    int _min = *min_element(a.begin() , a.end()) ; 
    int ans = 0 ; 
    for (int i : a) {
        ans += ((i + (2 * _min) - 2) / ((2 * _min) - 1)) - 1 ;
    }
    cout << ans << endl ;
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