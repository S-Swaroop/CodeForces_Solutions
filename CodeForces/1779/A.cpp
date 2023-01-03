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
    string s; 
    cin >> s; 
    int L = count(s.begin(), s.end(), 'L'), R = n - L; 
    if (R == 0 || L == 0) {
        cout << -1 << endl; 
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'L' && s[i + 1] == 'R') {
                cout << i + 1 << endl; 
                return;
            }
        }
        cout << 0 << endl; 
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