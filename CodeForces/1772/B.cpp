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

void rotate (vector<vector<int>> &a) {
    int t = a[0][0]; 
    a[0][0] = a[1][0]; 
    a[1][0] = a[1][1]; 
    a[1][1] = a[0][1]; 
    a[0][1] = t; 
}

bool check (vector<vector<int>> &a) {
    return (a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1]);
}

void solve() {
    vector<vector<int>> a(2, vector<int> (2)); 
    for (auto &i: a) {
        for (int &j: i) {
            cin >> j; 
        }
    }
    for (int i = 0; i <= 4; i++) {
        if (check(a)) {
            cout << "YES" << endl; 
            return;
        }
        rotate(a); 
    }
    cout << "NO" << endl; 
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