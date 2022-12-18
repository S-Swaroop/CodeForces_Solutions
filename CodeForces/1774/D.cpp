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

int do_ops (int n, int m, int ones_in_each, vector<vector<int>> &a, vector<int> &f1, vector<pair<int, pair<int, int>>> &ans) {
    for (int i = 0; i < m; i++) {
        set<pair<int, int>> s; 
        for (int j = 0; j < n; j++) {
            if (f1[j] > ones_in_each && a[j][i] == 1) {
                s.insert({f1[j], i});
            } 
        }
        for (int j = 0; j < n; j++) {
            if (f1[j] < ones_in_each && a[j][i] == 0) {
                if (!s.empty()) {
                    auto v = *s.rbegin(); 
                    s.erase(s.begin()); 
                    f1[v.second]--; 
                    v.first--; 
                    f1[j]++; 
                    ans.push_back({i, {j, v.second}});
                    swap(a[j][i], a[v.second][i]);
                }
            }
        }
    }
    set<int> x(f1.begin(), f1.end()); 
    return (int)x.size(); 
}

void solve() {
    int n, m; 
    cin >> n >> m; 
    int ones = 0, zeros = 0; 
    vector<vector<int>> a(n, vector<int> (m)); 
    for (auto &i: a) {
        for (int &j: i) { 
            cin >> j; 
            ones += j == 1; 
            zeros += j == 0; 
        }
    }
    if (ones % n != 0) {
        cout << -1 << endl; 
    } else {
        vector<pair<int, pair<int, int>>> ans; 
        set<int> zeros_at[n]; 
        vector<int> f1(n, 0); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    zeros_at[i].insert(j); 
                } else {
                    f1[i]++; 
                }
            }
        }
        int ones_in_each = ones / n; 
        bool possible = do_ops(n, m, ones_in_each, a, f1, ans); 
        if (possible) {
            cout << (int)ans.size() << endl; 
            for (auto &i: ans) {
                cout << i.first + 1 << " " << i.second.first + 1 << " " << i.second.second + 1 << endl; 
            }
        } else {
            cout << -1 << endl; 
        }
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