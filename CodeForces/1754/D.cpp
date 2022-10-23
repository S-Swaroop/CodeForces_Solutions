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
    int n , x ; 
    cin >> n >> x ; 
    vector<int> a(n) ;
    for (int &i : a)    cin >> i ;
    vector<int> f(x + 1 , 0) ; 
    for (int &i : a) {
        f[i]++ ;
    }
    bool possible = true ;
    for (int i = 1 ; i < x ; i++) {
        if (f[i] % (i + 1) == 0) {
            f[i + 1] += (f[i] / (i + 1)) ;
        } else {
            possible = false ; 
            break ;
        }
    }
    cout << (possible ? "YES" : "NO") << endl ;
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   
   int t = 1 ;
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}