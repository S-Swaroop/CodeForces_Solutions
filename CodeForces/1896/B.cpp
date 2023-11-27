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
    int lastB = 0, firstA = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'B') {
            lastB = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            firstA = i;
            break;
        }
    }
    cout << max(lastB - firstA, 0ll) << endl;
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