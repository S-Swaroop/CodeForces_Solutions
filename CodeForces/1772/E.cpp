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
    vector<int> b = a, c = a; 
    sort(b.begin(), b.end()); 
    sort(c.rbegin(), c.rend()); 
    int out_of_place_1 = 0, out_of_place_2 = 0, common_out_of_place = 0; 
    int in_place_1 = 0, in_place_2 = 0, common = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            out_of_place_1++; 
        } 
        if (a[i] != c[i]) {
            out_of_place_2++; 
        }
        if (a[i] != c[i] && a[i] != b[i]) {
            common_out_of_place++; 
            out_of_place_1--; 
            out_of_place_2--; 
        }
    }
    
    if (out_of_place_1 + common_out_of_place <= out_of_place_2) {
        cout << "First" << endl; 
    } else if (out_of_place_2 + common_out_of_place < out_of_place_1) {
        cout << "Second" << endl; 
    } else {
        cout << "Tie" << endl; 
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