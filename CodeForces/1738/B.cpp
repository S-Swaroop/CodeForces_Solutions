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
    int n , k ; 
    cin >> n >> k ; 
    vector<int> a(k) ; 
    for (int &i : a)    cin >> i ;
    if (k == 1) {
        cout << "YES" << endl ;
    } else {
        int diff = a[1] - a[0] ;
        for (int i = 1 ; i < k ; i++) {
            if (a[i] - a[i - 1] >= diff) {
                diff = a[i] - a[i - 1] ;
            } else {
                cout << "NO" << endl ; 
                return ;
            }
        }
        if ((a[1] - a[0]) * (n - k + 1) >= a[0]) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
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