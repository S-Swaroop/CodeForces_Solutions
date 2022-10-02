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
    int n ;
    cin >> n ; 
    vector<int> b(n) ; 
    for (int &i : b)    cin >> i ; 
    vector<int> a(n , 0) ; 
    a[0] = b[0] ;
    int _max = a[0] , _min = a[0] ;
    for (int i = 1 ; i < n ; i++) {
        if (a[i - 1] - b[i] < 0 || b[i] == 0) {
            a[i] = a[i - 1] + b[i] ;
        } else {
            cout << -1 << endl ; 
            return ;
        }
    }
    for (int &i : a) {
        cout << i << " " ;
    }
    cout << endl ;
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