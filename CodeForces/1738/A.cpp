/*
***************************
* Author : SHARAN SWAROOP *
***************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

void solve() {
    int n ;
    cin >> n ; 
    vector<int> a(n) , b(n) ; 
    int s1 = 0 , s0 = 0 ; 
    int _min = INT_MAX ;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i] ; 
        if (a[i])   s1++ ; 
        else    s0++ ;
    }
    for (int &i : b) {
        cin >> i ; 
        _min = min(_min , i) ;
    } 
    if (s1 == s0) {
        cout << (2 * accumulate(b.begin() , b.end() , 0ll)) - _min << endl ;
    } else {
        // always keeping s0 <= s1
        if (s0 > s1) {
            swap(s1 , s0) ;
            for (int &i : a)    i ^= 1 ;
        }
        int ans = 0 ;
        vector<int> v ; 
        for (int i = 0 ; i < n ; i++) {
            ans += b[i] ;
            if (a[i] == 1) {
                v.push_back(b[i]) ;
            } else {
                ans += b[i] ;
            }
        }
        sort(v.rbegin() , v.rend()) ;//choosing the largest s0 to double up
        for (int i = 0 ; i < s0 ; i++) {
            ans += v[i] ;
        }
        cout << ans << endl ;
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