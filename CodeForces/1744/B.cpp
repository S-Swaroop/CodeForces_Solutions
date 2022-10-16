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
    int n , q ; 
    cin >> n >> q ; 
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ;
    int odd = 0 , even = 0 , sum = 0 ; 
    for (int &i : a) {
        odd += (i % 2) ; 
        even += (i % 2 == 0) ;
        sum += i ;
    }
    while (q--) {
        int type , x ; 
        cin >> type >> x ;
        if (type == 1) {
            sum += odd * x ; 
            if (x & 1) {
                even += odd ; 
                odd = 0 ;
            }
        } else {
            sum += even * x ;
            if (x & 1) {
                odd += even ; 
                even = 0 ;
            }
        }
        cout << sum << endl ;
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