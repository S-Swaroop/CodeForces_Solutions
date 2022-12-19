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
    int n, k; 
    cin >> k >> n; 
    vector<int> ans; 
    ans.push_back(1); 
    for (int i = 1; i <= n && (int)ans.size() < k; i++) {
        if (ans.back() + i <= n && (int)ans.size() + n - (ans.back() + i) + 1 >= k) {
            ans.push_back(ans.back() + i); 
        } else {
            ans.push_back(ans.back() + 1); 
        }
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