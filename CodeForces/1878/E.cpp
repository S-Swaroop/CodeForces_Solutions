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

int rangeAND(int l, int r, vector<vector<int>> &pref) { 
    int res = 0;
    for (int i = 0; i < 30; i++) {
        if (pref[r][i] - pref[l - 1][i] == (r - l + 1)) {
            res |= (1ll << i);
        }
    }
    return res;
}

int findLargestR(int l, int k, int n, vector<vector<int>> &pref) {
    int low = l - 1, high = n + 1;
    int res = -1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (rangeAND(l, mid, pref) >= k) {
            low = mid;
            res = mid;
        } else {
            high = mid;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<vector<int>> pref(n + 1, vector<int> (31, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1ll << j)) {
                pref[i + 1][j] += pref[i][j] + 1;
            } else {
                pref[i + 1][j] += pref[i][j];
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> k;
        cout << findLargestR(l, k, n, pref) << " ";
    }
    cout << endl;
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