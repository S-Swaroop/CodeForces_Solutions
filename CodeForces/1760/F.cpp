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
    int n , c , d ; 
    cin >> n >> c >> d ;
    vector<int> a(n) ; 
    for (int &i : a)    cin >> i ;
    sort(a.rbegin() , a.rend()) ;
    int low = -1 , high = d + 1 , ans = -1 ; 
    while (low < high) {
        int mid = low + ((high - low + 1) / 2) ;
        int left = c ;
        for (int day = 0 ; day < d ; day++) {
            if (day % (mid + 1) < n) {
                left -= a[day % (mid + 1)] ;
            }
        }
        if (left > 0) {
            high = mid - 1 ;
        } else {
            ans = mid ;
            low = mid ;
        }
    }
    if (ans > d) {
        cout << "Infinity" << endl ;
    } else if (ans == -1) {
        cout << "Impossible" << endl ;
    } else {
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