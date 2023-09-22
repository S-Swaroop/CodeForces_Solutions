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
    vector<int> a(n), h(n);
    for (int &i: a) cin >> i;
    for (int &i: h) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && h[j - 1] % h[j] == 0) {
            j++;
        }
        int sum = 0;
        int l = i, r = i;
        while (r < j) {
            sum += a[r];
            while (sum > k) {
                sum -= a[l];
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        i = j - 1;
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