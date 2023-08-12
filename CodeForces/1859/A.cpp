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
    vector<int> a(n);
    for (int &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        bool found = true;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j || a[i] == a[j]) continue;
            found &= a[j] % a[i] != 0;
            if (found)  count++;
        }
        if (found && count > 0) {
            vector<int> b, c;
            for (int j = 0; j < n; j++) {
                if (i == j || a[i] == a[j]) {
                    c.push_back(a[j]);
                } else {
                    b.push_back(a[j]);
                }
            }
            cout << (int)b.size() << " " << (int)c.size() << endl;
            for (int &k: b) cout << k << " ";
            cout << endl;
            for (int &k: c) cout << k << " ";
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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