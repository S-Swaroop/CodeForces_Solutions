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
    int n ;
    cin >> n ;
    vector<string> a(n) ; 
    for (auto &i : a)   cin >> i ;
    vector<int> ans[n] ;
    vector<int> adj[n] ; 
    vector<int> deg(n , 0) ;
    for (int i = 0 ; i < n ; i++) {
        ans[i].push_back(i + 1) ;
        for (int j = 0 ; j < n ; j++) {
            if (a[i][j] == '1') {
                adj[i].push_back(j) ;
                deg[j]++ ;
            }
        }
    }
    queue<int> q ;
    for (int i = 0 ; i < n ; i++) {
        if (deg[i] == 0) {
            q.push(i) ;
        }
    }
    while (!q.empty()) {
        int node = q.front() ;
        q.pop() ;
        for (auto &i : adj[node]) {
            ans[i].push_back(node + 1) ;
            deg[i]-- ;
            if (deg[i] == 0) {
                q.push(i) ;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << (int)ans[i].size() << " " ;
        for (int j : ans[i]) {
            cout << j << " " ;
        }
        cout << endl ;
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