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
    int n , k ; 
    cin >> n >> k ; 
    string s ; 
    cin >> s ; 
    map<char , int> f ; 
    for (char &i : s) {
        f[i]++ ;
    }
    string ans = "" ;
    for (int i = 0 ; i < k ; i++) {
        int need = n / k ; 
        bool found = false ;
        char x = 'z' ;
        char last = 'a' ;
        for (char c = 'a' ; c <= 'z' && need > 0 ; c++) {
            if (f[c] == 0) {
                found = true ;
                x = min(x , c) ;
            } else {
                f[c]-- ;
                need-- ;
                last = c ;
            }
        }
        if (!found) {
            ans += ++last ;
        } else {
            ans += x ; 
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
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}