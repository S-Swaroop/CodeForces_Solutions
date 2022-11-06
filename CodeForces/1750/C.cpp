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
    int n ;
    cin >> n ;
    string s , t ; 
    cin >> s >> t ; 
    vector<int> pref(n + 1 , 0) ;
    vector<pair<int , int>> ans ;
    bool possible = true ;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == '1') {
            int j = i + 1 ;
            while (j < n && s[j] == '1') {
                j++ ;
            }
            ans.push_back({i + 1 , j}) ;
            pref[0]++ ;
            pref[j]++ ;
            pref[i]-- ;
            i = j ;
        }
    }
    // now s is all 0s
    for (int i = 1 ; i <= n ; i++) {
        pref[i] += pref[i - 1] ;
    }
    for (int i = 0 ; i < n ; i++) {
        t[i] = '0' + (((t[i] - '0') + (pref[i] % 2)) % 2) ;
    }
    for (int i = 1 ; i < n ; i++) {
        if (t[i] != t[i - 1]) {
            possible = false ;
        }
    }
    if (possible) { // t is either all 0s or all 1s
        if (t[0] == '1') { // 00|11 -> 10|10 -> 01|10 -> 00|00
            ans.push_back({1 , 1}) ;
            ans.push_back({1 , n}) ;
            ans.push_back({2 , n}) ;
        }
        if ((int)ans.size() > n + 5) {
            cout << "NO" << endl ;
        } else {
            cout << "YES" << endl ;
            cout << ans.size() << endl ;
            for (auto &i : ans) {
                cout << i.first << " " << i.second << endl ;
            }
        }
    } else {
        cout << "NO" << endl ;
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