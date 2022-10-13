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
    int n , k ; 
    cin >> n >> k ; 
    vector<int> a(n) ;
    vector<pair<int , int>> q(k) ;
    for (int &i : a)    cin >> i ;
    for (int i = 0 ; i < k ; i++) {
        cin >> q[i].first ;
        q[i].second = i ;
    }
    sort(q.begin() , q.end()) ;
    vector<int> ans(k , 0) ;
    int sum = 0 ; 
    int j = 0 ;
    for (int i = 0 ; i < n && j < k ; i++) {
        while (j < k && a[i] > q[j].first) {
            ans[q[j++].second] = sum ;
        }
        sum += a[i] ;
    }
    while (j < k) {
        ans[q[j++].second] = sum ;
    }
    for (int &i : ans) {
        cout << i << " " ;
    }
    cout << endl ;
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