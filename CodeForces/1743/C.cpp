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
    string s ; 
    cin >> s ; 
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ; 
    int ans = 0 ; 
    for (int i = 0 ; i < n ; i++) {
        ans += a[i] * (s[i] == '1') ;
    }
    for (int i = 0 ; i < n - 1 ; i++) {
        if (s[i + 1] == '1' && s[i] == '0') {
            int j = i + 1 ; 
            int _min = INT_MAX ;
            while (j < n && s[j] == '1') {
                _min = min(_min , a[j]) ;
                j++ ;
            }
            if (a[i] > _min) {
                ans += a[i] ;
                ans -= _min ;
            }
            i = j - 1 ;
        }
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
    
   double runtime = clock() * 1.0 / CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}