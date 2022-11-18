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
    vector<bool> have(100 , false) ;
    int n , sum ;
    cin >> n >> sum ; 
    vector<int> a(n) ;
    for (int &i : a)    cin >> i ;
    for (int &i : a) {
        have[i] = true ;
    }
    int last = *max_element(a.begin() , a.end()) ;
    for (int i = 1 ; i <= last && sum > 0 ; i++) {
        if (!have[i]) {
            have[i] = true ;
            sum -= i ;
        }
    }
    bool flag = true ;
    for (int i = 1 ; i <= last ; i++) {
        if (!have[i]) {
            flag = false ;
            break ;
        }
    }
    for (int i = last + 1 ; i <= 100 && sum > 0 ; i++) {
        sum -= i ;
    }
    if (flag && sum == 0) {
        cout << "YES" << endl ;
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