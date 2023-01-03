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
    vector<int> a(n); 
    for (int &i: a) cin >> i; 
    priority_queue<int> left, right; 
    int moves = 0, net = 0; 
    for (int i = m; i < n; i++) {
        if (a[i] < 0) {
            right.push(-a[i]); 
        }
        net += a[i]; 
        while (net < 0 && !right.empty()) { // while the net change from m to this index is negative(i.e downward slope)
            net += 2 * right.top(); // increase the net chagne
            right.pop(); 
            moves++; 
        }
    }
    if (m == 1) {
        cout << moves << endl; 
    } else {
        if (a[m - 1] > 0) {
            a[m - 1] *= -1; 
            moves++; 
        }
        net = a[m - 1]; 
        for (int i = m - 2; i >= 1; i--) {
            if (a[i] > 0) {
                left.push(a[i]); 
            } 
            net += a[i]; 
            while (net > 0 && !left.empty()) { // while the net change from i to m is positive(i.e upward slope)
                net -= 2 * left.top(); // we decrease the net change
                left.pop(); 
                moves++; 
            }
        }
        cout << moves << endl; 
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