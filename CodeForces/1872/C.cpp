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
    int l, r;
    cin >> l >> r;
    int a = -1, b = -1;
    bool found = false;
    for (int i = l; i <= r && !found; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                a = i / j;
                b = i - a;
                found = true;
                break;
            }
        }
    }
    if (found) {
        cout << a << " " << b << endl;
    } else {
        cout << -1 << endl;
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
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}