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

const int N = 1e5 + 1 ;

vector<pair<int , int>> adj[N] ; 
multiset<int> path_to_b_exists ;
vector<int> path_to_a ;
int n , a , b ;

void b_to_all (int node , int parent , int x) {
    if (node != b) {
        // cout << node << " " << x << endl ;
        path_to_b_exists.insert(x) ;
    } 
    for (auto &[v , w] : adj[node]) { 
        if (v != parent) {
            b_to_all(v , node , x ^ w) ;
        }
    }
}

bool dfs (int node , int parent , int x) {
    if (node == b) {
        return (x == 0) ;
    } else if (path_to_b_exists.find(x) != path_to_b_exists.end()) {
        return true ;
    } else {
        for (auto &[v , w] : adj[node]) {
            if (v != parent) {
                if (dfs(v , node , x ^ w)) {
                    return true ;
                }
            }
        }
        return false ;
    }
}

void clean_up () {
    for (int i = 0 ; i <= n ; i++) {
        adj[i].clear() ;
    }
    path_to_b_exists.clear() ;
    n = a = b = 0 ;
}

void solve() {
    cin >> n >> a >> b ;
    for (int i = 0 , u , v , w ; i < n - 1 ; i++) {
        cin >> u >> v >> w ;
        adj[u].push_back({v , w}) ;
        adj[v].push_back({u , w}) ;
    }
    b_to_all(b , -1 , 0) ;
    if (dfs (a , -1 , 0)) {
        cout << "YES" << endl ;
    } else {
        cout << "NO" << endl ;
    }
    clean_up() ;
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