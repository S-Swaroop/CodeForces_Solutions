/*
***************************
* Author : SHARAN SWAROOP *
***************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

const int N = 2e5 + 1 ; 
int n , k ;    
vector<int> adj[N] ; 
int operations ;

int dfs (int node , int parent , int mid) {
    int depth = 0 ; 
    for (int i : adj[node]) {
        if (i != parent) {
            depth = max(depth , dfs (i , node , mid)) ;
        }
    }
    if (depth == mid - 1) {
        if (parent == 1 || node == 1) {

        } else {
            operations++ ;
            return 0 ;
        }
    }
    return depth + 1 ;
}

void cleanup (int n) {
    for (int i = 1 ; i <= n ; i++) {
        adj[i].clear() ;
    }
}

void solve() {
    cin >> n >> k ; 
    for (int i = 2 , v ; i <= n ; i++) {
        cin >> v ; 
        adj[v].push_back(i) ; 
        adj[i].push_back(v) ;
    }
    int low = 0 , high = 2 * n , ans = -1 ; 
    while (high - low > 1) {
        int mid = low + ((high - low) >> 1) ;
        operations = 0 ; 
        dfs (1 , -1 , mid) ; 
        if (operations <= k) {
            high = mid ; 
            ans = mid ;
        } else {
            low = mid ;
        }
    }
    cout << ans << endl ;
    cleanup(n) ;
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