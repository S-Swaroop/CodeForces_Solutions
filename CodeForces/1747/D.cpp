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
    int n , q ; 
    cin >> n >> q ; 
   
    vector<int> a(n) ; 
   
    for (int &i : a) {
        cin >> i ;
    }

    vector<int> pref_sum(n + 1 , 0) , pref_xor(n + 1 , 0) ;
    map<pair<int , int> , vector<int>> xor_till ;

    for (int i = 0 ; i < n ; i++) {
        pref_sum[i + 1] = pref_sum[i] + a[i] ;
        pref_xor[i + 1] = pref_xor[i] ^ a[i] ;
        xor_till[{pref_xor[i + 1] , i % 2}].push_back(i) ;
    }

    while (q--) {
        int l , r ; 
        cin >> l >> r ;
        int x = pref_xor[r] ^ pref_xor[l - 1] ;
        if (x != 0) { // if subarray xor is non-zero then impossible
            cout << -1 << endl ;
        } else if (pref_sum[r] - pref_sum[l - 1] == 0) { // if all zeroes then no moves required
            cout << 0 << endl ;
        } else if ((r - l + 1) % 2) { // if odd length subarray do operation on whole subarray
            cout << 1 << endl ;
        } else if (a[l - 1] == 0 || a[r - 1] == 0) { // if even length but terminal elements can be ignored
            cout << 1 << endl ;
        } else {
            pair<int , int> p = {pref_xor[l - 1] , (l - 1) % 2} ;
            // search for an odd length prefix that has xor zero and do operations on prefix and suffix 
            auto it = lower_bound(xor_till[p].begin() , xor_till[p].end() , l - 1) ;
            if (it != xor_till[p].end() && *it < r) {
                cout << 2 << endl ;
            } else {
                cout << -1 << endl ;
            }
        }
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}