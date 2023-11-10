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
    for (int &i: a) --i;
    vector<bool> vis(n, false);
    int curr_at = n - 1;
    vis[curr_at] = true;
    for (int i = 0; i < k; i++) {
        if (a[curr_at] >= 0 && a[curr_at] <= n - 1) {
            int was_at = (curr_at + n - a[curr_at] - 1) % n;
            curr_at = was_at;
            if (vis[curr_at]) {
                break;
            }
            vis[curr_at] = true;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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