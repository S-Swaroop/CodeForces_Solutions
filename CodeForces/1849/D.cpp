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

struct DSU {
    int N;
    vector<int> par, _size;
    DSU(int n) {
        N = n;
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0ll);
        _size.resize(n, 1);
    }

    int findParent(int u) {
        if (u == par[u])
        return u;
        return par[u] = findParent(par[u]);
    }

    void merge(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a != b) {
            if (_size[a] < _size[b]) {
                swap(a, b);
            }
            par[b] = a;
            _size[a] += _size[b];
        }
    }
};


void solve() {
    int n; 
    cin >> n; 
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<int> compressed; 
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            compressed.push_back(a[i]);
            continue;
        }
        int j = i; 
        int _max = 0;
        while (j < n && a[j] > 0) {
            _max = max(_max, a[j]);
            j++;
        }
        compressed.push_back(_max);
        i = j - 1;
    }
    int m = compressed.size();
    DSU S(m);
    vector<bool> isRed(m + 1, false);
    for (int i = 0; i < m; i++) {
        if (compressed[i] == 1) {
            isRed[i] = true;
            if (i > 0 && !isRed[i - 1]) {
                S.merge(i - 1, i);
                isRed[i - 1] = true;
            } else if (i < m - 1 && !isRed[i + 1]) {
                S.merge(i + 1, i);
                isRed[i + 1] = true;
            }
        } else if (compressed[i] == 2) {
            isRed[i] = true;
            if (i > 0 && !isRed[i - 1]) {
                S.merge(i - 1, i);
                isRed[i - 1] = true;
            } 
            if (i < m - 1 && !isRed[i + 1]) {
                S.merge(i + 1, i);
                isRed[i + 1] = true;
            }
        }
    }
    set<int> st;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!isRed[i]) {
            ans++;
        } else {
            st.insert(S.findParent(i));
        }
    }
    ans += (int)st.size();
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}