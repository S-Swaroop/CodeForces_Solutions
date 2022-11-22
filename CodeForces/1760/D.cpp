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
    int n ;
    cin >> n ; 
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ;
    int count = 0 ; 
    for (int i = 0 ; i < n ; i++) {
        if (i == 0 || a[i - 1] > a[i]) {
            int j = i ;
            while (j < n - 1 && a[j] == a[j + 1]) {
                j++ ;
            }
            count += (j >= n - 1 || a[j] < a[j + 1]) ;
            i = j ;
        }
    }
    cout << (count == 1 ? "Yes" : "No") << endl ;
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