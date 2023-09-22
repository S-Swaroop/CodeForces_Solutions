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

void getDistanceMapped(int src, int n, vector<int> adj[], vector<int> &dist) {
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                dist[v] = min(dist[v], dist[u] + 1);
            }
        }
    }
}

bool isCyclic(int u, int p, vector<bool> &vis, vector<int> adj[], int &cycleEntrance) {
    vis[u] = true;
    for (int v: adj[u]) {
        if (v != p && vis[v]) {
            cycleEntrance = v;
            return true;
        } else if (v != p && !vis[v]) {
            if (isCyclic(v, u, vis, adj, cycleEntrance)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> adj[n + 1];
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> distanceFromA(n + 1, INT_MAX), distanceFromB(n + 1, INT_MAX);
    if (a == b) {
        cout << "NO" << endl;
        return;
    }
    int cycleEntrance = -1;
    vector<bool> vis(n + 1, false);
    bool possible = isCyclic(b, -1, vis, adj, cycleEntrance);
    getDistanceMapped(a, n, adj, distanceFromA);
    getDistanceMapped(b, n, adj, distanceFromB);
    if (distanceFromB[cycleEntrance] < distanceFromA[cycleEntrance]) {
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