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
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> a(k) ; 
    for (int &i : a)    cin >> i ; 
    vector<bool> on_board(k + 1 , false) ;
    int occupied = 2 ;
    int curr = k ;
    for (int i = 0 ; i < k && curr > 0 ; i++) {
        occupied++ ;
        on_board[a[i]] = true ;
        while (curr > 0 && on_board[curr] && ((n * m) - occupied) >= 1) {
            curr-- ;
            occupied-- ;
        }
    }
    if (curr == 0) {
        cout << "YA" << endl ; 
    } else {
        cout << "TIDAK" << endl ;
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