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

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return b.second < a.second;
    } else {
        return a.first > b.first;
    }
}

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        a[i] = a[i] % k;
        if (a[i] == 0) {
            a[i] = k;
        }
    }
    vector<int> indexes(n);
    iota(indexes.begin(), indexes.end(), 0ll);
    stable_sort(indexes.begin(), indexes.end(), [&](int i, int j) {
      return a[i] > a[j];
    });
    for (int &i: indexes) {
        cout << i + 1 << " ";
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