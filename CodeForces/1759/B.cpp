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
    string s ; 
    cin >> s ;
    int n = s.length() ;
    bool flag = s[0] == 'Y' || s[0] == 'e' || s[0] == 's' ; 
    for (int i = 1 ; i < n ; i++) {
        if (s[i] == 'Y') {
            flag &= s[i - 1] == 's' ;
        } else if (s[i] == 'e') {
            flag &= s[i - 1] == 'Y' ; 
        } else if (s[i] == 's') {
            flag &= s[i - 1] == 'e' ;
        } else {
            flag = false ;
        }
    }
    cout << (flag ? "YES" : "NO") << endl ;
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