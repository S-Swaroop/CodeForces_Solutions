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

inline int query (int x, int y) {
    cout << "? " << x << " " << y << endl; 
    cout.flush(); 
    int res; cin >> res; return res; 
}

inline void ans (int x, int y) {
    cout << "! " << x << " " << y << endl;   
    cout.flush(); 
}

void solve() {
    int n; 
    cin >> n; 
    int x = 1, y = 2; 
    int g = query(x, y); 
    int gx = 0, gy = 0; 
    for (int i = 3; i <= n; i++) {
        gx = query(i, x); 
        gy = query(i, y); 
        g = max({gx, gy, g});
        if (gx == g) {
            y = i; 
        } else if (gy == g) {
            x = i; 
        }
    }
    ans(x, y); 
    int res; 
    cin >> res; 
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