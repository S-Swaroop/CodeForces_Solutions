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
    int n, m; 
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; 
    }
    cin >> m; 
    vector<int> r(m); 
    for (int &i: r) cin >> i;
    unordered_map<int, int> f; 
    for (int &i: r) f[i]++; 
    bool possible = true; 
    for (int i = 1; i <= n; i++) {
        if (b[i] > a[i]) {
            possible = false; 
        }
    }
    int _max = 0; 
    for (int i = 1; i <= n && possible; i++) {
        if (a[i] != b[i]) {
            if (b[i] < b[i - 1]) {
                f[b[i]]--; 
                if (f[b[i]] < 0) {
                    possible = false; 
                }
            } else if (b[i] > b[i - 1]) {
                if (b[i] > _max) {
                    f[b[i]]--; 
                    _max = b[i]; 
                    if (f[b[i]] < 0) {
                        possible = false; 
                    }
                }
            }
        }
    }
    if (possible) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl; 
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