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

bool check (int x, int y, vector<string> a) {
    int n = a[0].length(); 
    while (y < n && a[x][y] == 'B') {
        if (a[(x + 1) % 2][y] == 'B') {
            a[x][y] = 'W';
            x = (x + 1) % 2;
        } else {
            a[x][y] = 'W';
            y++; 
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[0][i] == 'B' || a[1][i] == 'B') {
            return false; 
        } 
    }
    return true;  
}

void solve() {
    int n; 
    cin >> n; 
    vector<string> a(2); 
    cin >> a[0] >> a[1]; 
    cout << (check(0, 0, a) || check(1, 0, a) ? "YES" : "NO") << endl; 
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