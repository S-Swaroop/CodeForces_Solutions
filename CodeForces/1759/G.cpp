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
    vector<int> a(n , -1) ;
    for (int i = 0 ; i < n ; i += 2) {
        cin >> a[i] ;
    }
    bool possible = true ;
    set<pair<int , int>> st ; 
    for (int i = 0 ; i < n ; i += 2) {
        st.insert({n - i , -1 * a[i]}) ;
    }
    set<int> not_there ;
    for (int i = 1 ; i <= n ; i++) {
        not_there.insert(i) ;
    }
    for (int i = 0 ; i < n ; i += 2) {
        not_there.erase(a[i]) ;
    }
    for (auto &[index , val] : st) {
        auto it = not_there.upper_bound(-1 * val) ;
        if (it == not_there.end()) {
            --it ;
        }
        while (it != not_there.begin() && *it > -1 * val) {
            --it ;
        }
        if (*it > -1 * val) {
            possible = false ;
            break ;
        } else {
            a[(-1 * (index - n)) + 1] = *it ;
            not_there.erase(it) ;
        }
    }
    vector<int> done(n + 1 , false) ;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] != -1 && done[a[i]]) {
            possible = false ;
        } else  if (a[i] != -1) {
            done[a[i]] = true ;
        }
    }
    if (possible) {
        for (int i = 0 ; i < n ; i += 2) {
            if (a[i] > a[i + 1]) {
                swap(a[i] , a[i + 1]) ;
            }
        }
        for (auto &i : a) {
            cout << i << " " ;
        }
        cout << endl ;
    } else {
        cout << -1 << endl ;
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