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

string grid[10];

void solve() {
    grid[0] = "1111111111";
    grid[1] = "1222222221";
    grid[2] = "1233333321";
    grid[3] = "1234444321";
    grid[4] = "1234554321";
    grid[5] = "1234554321";
    grid[6] = "1234444321";
    grid[7] = "1233333321";
    grid[8] = "1222222221";
    grid[9] = "1111111111";
    int n = 10;
    vector<string> a(n);
    int ans = 0;
    for (auto &i: a)    cin >> i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'X') {
                ans += grid[i][j] - '0';
            }
        }
    }
    cout << ans << endl;
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