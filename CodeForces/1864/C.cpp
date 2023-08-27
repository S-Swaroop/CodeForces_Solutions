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
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    int k = 1000;
    while (k-- && ans.back() * 2 <= n) {
        ans.push_back(ans.back() * 2);
    }
    while (k-- && ans.back() < n && k--) {
        int x = 1;
        for (int i = 0; (1ll << i) < ans.back(); i++) {
            if (ans.back() + (1ll << i) <= n) {
                x = (1ll << i);
            }
        }
        ans.push_back(ans.back() + x);
    }
    cout << (int)ans.size() << endl;
    reverse(ans.begin(), ans.end());
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