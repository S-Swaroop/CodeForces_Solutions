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
    int n, k; 
    cin >> n >> k; 
    vector<int> a(n); 
    for (int &i: a) cin >> i; 
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl; 
    } else {
        vector<int> index_of(n + 1, -1);
        for (int i = 0; i < n; i++) {
            index_of[a[i]] = i; 
        }
        // if (index_of[1] != 0) {
        //     cout << (n + k - 1) / k << endl; 
        //     return;
        // }
        // for (int &i: index_of) {
        //     cout << i << " "; 
        // }
        // cout << endl; 
        int _max = index_of[1]; 
        int to_change = n - 1; 
        for (int i = 2; i <= n; i++) {
            if (index_of[i] < _max) {
                break;
            } else {
                to_change--;
                _max = index_of[i]; 
            }
        }
        cout << (to_change + k - 1) / k << endl; 
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