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
    int n , c ;
    cin >> n >> c ; 
    vector<bool> present(c + 1 , false) ; 
    vector<int> a(n) ; 
    for (int &i : a) {
        cin >> i ; 
        present[i] = true ;
    }
    vector<int> b ; 
    for (int i = 1 ; i <= c ; i++) {
        if (!present[i]) {
            b.push_back(i) ;
        }
    }
    set<int> nums(a.begin() , a.end()) ;
    vector<int> pref(c + 1 , 0) ;
    for (int i = 0 ; i < n ; i++) {
        pref[a[i]]++ ;
    }
    for (int i = 0 ; i < c ; i++) {
        pref[i + 1] += pref[i] ;
    }
    bool possible = true ; 
    for (int i : nums) {
        for (int j = 1 ; ; j++) {
            int curr = i * j , nxt = min(c , curr + i - 1) ;
            if (curr > c) {
                break ;
            } else {
                int total = pref[nxt] - pref[curr - 1] ;
                if (total) {
                    if (present[j] == false) {
                        possible = false ; 
                        break ;
                    }
                }
            }
        }
    }
    cout << (possible ? "YES" : "NO") << endl ;
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