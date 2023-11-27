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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    sort(b.begin(), b.end());
    vector<int> c(n, 0);
    for (int i = 0; i < x; i++) {
        c[v[n - x + i].second] = b[i];
    }
    for (int i = x; i < n; i++) {
        c[v[i - x].second] = b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > c[i]) {
            x--;
        }
    }
    if (x == 0) {
        cout << "YES" << endl;
        for (int &i: c) cout << i << " ";
        cout << endl;
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