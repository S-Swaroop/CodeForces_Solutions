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
    string s;
    cin >> n >> m >> s;
    
    vector<int> left(n), right(n);
    left[0] = -1;
    for (int i = 0; i < n; ++i) {
        if (i > 0) left[i] = left[i - 1];
        if (s[i] == '0') left[i] = i;
    }
    right[n - 1] = n;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) right[i] = right[i + 1];
        if (s[i] == '1') right[i] = i;
    }
    
    set<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int ll = right[l - 1], rr = left[r - 1];
        if (ll > rr) {
            st.insert({-1, -1});
        } else {
            st.insert({ll, rr});
        }
    }
    
    cout << st.size() << endl;
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