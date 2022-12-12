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

const int N = 1e7 + 1; 

vector<int> spf(N, 0); // smallest prime factor

void precompute() {
    for (int i = 2; i < N; i++) {
        if (!spf[i]) {
            spf[i] = i; 
            for (int j = i * i; j <= N; j += i) {
                spf[j] = i; 
            }
        }
    }
}

void solve() {
    int x, y; 
    cin >> x >> y;
    int diff = abs(x - y); 
    
    if (diff == 1) {
        cout << -1 << endl; 
    } else {
        int ans = LLONG_MAX; 
        while (diff > 1) {
            int X = ((x + spf[diff] - 1) / spf[diff]) * spf[diff]; 
            ans = min(ans, X - x); 
            diff /= spf[diff]; 
        }
        cout << ans << endl; 
    }
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   precompute();
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}