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
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(b.rbegin(), b.rend());
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (b[j] > a[i]) {
            ans.push_back(b[j]);
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
        }
    }
    while (i < n) {
        ans.push_back(a[i]);
        i++;
    }
    while (j < m) {
        ans.push_back(b[j]);
        j++;
    }
    for (int &i: ans) {
        cout << i << " ";
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