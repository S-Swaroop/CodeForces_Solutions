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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m);
    for (int &i: a) cin >> i;
    map<int, int> f;
    auto get = [d] (int l, int r) {
        return l < r ? (r - l + d - 1) / d : 0;
    };
    int ate = get(1, a[0]);
    for (int i = 0; i < m; i++) {
        int l = i > 0 ? a[i - 1] + d : 1;
        int r = i < m - 1 ? a[i + 1] : n + 1;
        int diff = get(l, r) - (get(l, a[i]) + 1 + get(a[i] + d, r));
        f[diff]++;
        ate += 1 + get(a[i] + d, r);
    }
    cout << ate + f.begin()->first << " " << f.begin()->second << endl;
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