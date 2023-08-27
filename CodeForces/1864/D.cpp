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
    vector<string> a(n);
    for (auto &i: a)    cin >> i;
    vector<vector<int>> left(n + 2, vector<int> (n + 2, 0)), right(n + 2, vector<int> (n + 2, 0)), top(n + 2, vector<int> (n + 2, 0));
    int steps = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            left[i][j] ^= left[i - 1][j - 1];
            right[i][j] ^= right[i - 1][j + 1];
            top[i][j] ^= left[i][j] ^ right[i][j] ^ top[i - 1][j];
            if (((a[i - 1][j - 1] - '0') + top[i][j]) & 1) {
                steps++; 
                right[i + 1][j - 1] ^= 1;
                left[i + 1][j + 1] ^= 1;
                top[i + 1][j] ^= 1;
            }
        }
    }
    cout << steps << endl;
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