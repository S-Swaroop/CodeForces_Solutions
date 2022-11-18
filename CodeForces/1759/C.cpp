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
    int l , r , x , a , b ;
    cin >> l >> r >> x >> a >> b ; 
    if (a == b) {
        cout << 0 << endl ;
    } else if (abs(a - b) >= x) {
        cout << 1 << endl ;
    } else {
        if (abs(a - l) >= x && abs(l - b) >= x) {
            cout << 2 << endl ;
        } else if (abs(a - r) >= x && abs(r - b) >= x) {
            cout << 2 << endl ;
        } else {
            if (abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x) {
                cout << 3 << endl ;
            } else if (abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x) {
                cout << 3 << endl ;
            } else {
                cout << -1 << endl ;
            }
        }
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