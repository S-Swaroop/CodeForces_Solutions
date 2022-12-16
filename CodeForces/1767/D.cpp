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
    int ones = 0, zeros = 0; 
    int smaller = 0, bigger = 0; 
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            bigger += (1 << zeros); 
            zeros++; 
        } else {
            smaller += (1 << ones); 
            ones++; 
        }
    }
    for (int i = smaller + 1; i <= (1 << n) - bigger; i++) {
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}