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
    int n , m ;
    cin >> n >> m ; 
    int x = 1 , y = 1 ; 
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            int res = 0 ;
            for (auto k : {make_pair(2 , 1) , make_pair(2 , -1) , make_pair(-2 , 1) , make_pair(-2 , -1)}) {
                int dx = k.first ;
                int dy = k.second ;
                if (((i + dx) <= n) && ((i + dx) >= 1) && ((j + dy) <= m) && ((j + dy) >= 1)) {
                    res++ ;
                }
                swap(dx , dy) ;
                if (((i + dx) <= n) && ((i + dx) >= 1) && ((j + dy) <= m) && ((j + dy) >= 1)) {
                    res++ ;
                }
            }
            if (res == 0) {
                x = i ; 
                y = j ;
            }
        }
    }
    cout << x << " " << y << endl ;
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