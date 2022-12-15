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
    int n; 
    cin >> n;
    vector<int> a(n); 
    for (int &i : a)    cin >> i; 
    int sum = accumulate(a.begin(), a.end(), 0ll); 
    if (sum % 2 == 0) {
        cout << 0 << endl; 
        return; 
    }
    int ans = INT_MAX; 
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            int x = a[i]; 
            int steps = 0; 
            while (x > 0 && x % 2 == 1) {
                steps++; 
                x /= 2; 
            }
            ans = min(ans, steps); 
        } else {
            int x = a[i]; 
            int steps = 0; 
            while (x > 1 && x % 2 == 0) {
                steps++; 
                x /= 2; 
            }
            ans = min(ans, steps); 
        }
    }
    cout << ans << endl; 
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