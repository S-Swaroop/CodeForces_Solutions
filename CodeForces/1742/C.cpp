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

void transpose (vector<string> &a) {
    for (int i = 0 ; i < 8 ; i++) { 
        for (int j = 0 ; j <= i ; j++) {
            swap(a[i][j] , a[j][i]) ;
        }
    }
}

void solve() {
    int n = 8 ; 
    vector<string> a(n) ;
    for (string &i : a) {
        cin >> i ; 
    }
    for (int i = 0 ; i < n ; i++) {
        int count = 0 ; 
        for (int j = 0 ; j < n ; j++) {
            if (a[i][j] == 'R') {
                count++ ;
            }
        }
        if (count == n) {
            cout << 'R' << endl ; 
            return ;
        }
    }
    transpose(a) ;
    for (int i = 0 ; i < n ; i++) {
        int count = 0 ; 
        for (int j = 0 ; j < n ; j++) {
            if (a[i][j] == 'B') {
                count++ ;
            }
        }
        if (count == n) {
            cout << 'B' << endl ; 
            return ;
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