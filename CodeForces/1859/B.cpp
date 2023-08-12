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

bool comp(vector<int> &a, vector<int> &b) {
    return a[1] > b[1];
}

void solve() {
    int n; 
    cin >> n; 
    vector<vector<int>> a(n);
    for (int i = 0, m; i < n; i++) {
        cin >> m; 
        for (int j = 0, x; j < m; j++) {
            cin >> x; 
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }
    sort(a.begin(), a.end(), comp);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i][1];
        a[n - 1].push_back(a[i][0]);
    }
    ans += *min_element(a[n - 1].begin(), a[n - 1].end());
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