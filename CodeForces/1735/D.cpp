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

vector<int> get_mask (vector<int> &a , vector<int> &b) { // returns complement mask
    int k = a.size() ;
    vector<int> mask(k , 0) ; 
    for (int i = 0 ; i < k ; i++) {
        if (a[i] != b[i]) {
            mask[i] = (3 - b[i] - a[i]) ;
        } else {
            mask[i] = a[i] ;
        }
    }
    return mask ;
}

vector<int> get_mask (vector<int> &a) { // returns actual mask
    int k = a.size() ;
    vector<int> mask(k , 0) ; 
    for (int i = 0 ; i < k ; i++) {
        mask[i] = a[i] ;
    }
    return mask ;
}

void solve() {
    int n , k ; 
    cin >> n >> k ;
    vector<int> hash(n , 0) ;
    vector<vector<int>> a(n , vector<int> (k)) ; 
    map<vector<int> , int> f ;
    int ans = 0 ; 
    for (auto &i : a) {
        for (int &j : i) {
            cin >> j ;
        }
    }
    int count = 1 ;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            f[get_mask(a[i] , a[j])]++ ;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        vector<int> mask = get_mask(a[i]) ;
        if (f.find(mask) != f.end()) {
            ans += (f[mask] * (f[mask] - 1)) / 2 ;
        }
    }
    cout << ans << endl ;
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