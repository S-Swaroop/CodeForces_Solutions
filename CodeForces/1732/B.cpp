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

int f (string &s , int c) {
    int steps = c , n = s.length() ; 
    for (int i = 1 ; i < n ; i++) {
        if (((s[i] - '0') + steps % 2) % 2 < ((s[i - 1] - '0') + steps % 2) % 2) {
            steps++ ;
        }
    }
    return steps ;
}

void solve() {
    int n ;
    cin >> n ;
    string s ;
    cin >> s ; 
    cout << min(f(s , 0) , 1 + f(s , 1)) << endl ;
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