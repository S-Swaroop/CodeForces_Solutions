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

bool check(int h, int x, vector<int> &a) {
    for (int &i: a) {
        x -= max(0ll, h - i);
        if (x < 0) {
            break;
        }
    }
    return (x >= 0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int low = 0, high = 2e18 + 1;
    int ans = 1;
    while (high - low > 1) {
        int mid = low + ((high - low) >> 1);
        if (check(mid, k, a)) {
            low = mid;
            ans = max(ans, mid);
        } else {
            high = mid;
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