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
    int x_max = 0 , y_max = 0 , x = 0 , y = 0 ; 
    for (int i = 0 , curr = 0 ; i < n ; i++) {
        int j = i + 1 ; 
        curr = 1 ;
        while (j < n && s[i] == s[j]) {
            j++ ;
            curr++ ;
        }
        if (s[i] == '0') {
            x += curr ;
            x_max = max(x_max , curr) ;
        } else {
            y += curr ;
            y_max = max(y_max , curr) ;
        }
        curr = 0 ;
        i = j - 1 ;
    }
    cout << max({x_max * x_max , y_max * y_max , x * y}) << endl ;
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