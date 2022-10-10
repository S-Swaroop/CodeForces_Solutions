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

int f (int start , int end , int n , vector<int> &a) {
    int l = start , k = 1 ;
    int ans = 0 ; 
    for (int i = start ; i <= end ; i++) {
        while (l <= i && a[i] < k) {
            l++ ; 
            k-- ;
        }
        ans += (i - l + 1) ; 
        k++ ;
    }
    return ans ;
}

void solve() {
    int n ; 
    cin >> n ; 
    vector<int> a(n) ;
    for (int &i : a)    cin >> i ;
    int q ; 
    cin >> q ; 
    int ans = f(0 , n - 1 , n , a) ;
    while (q--) {
        int index , val ;
        cin >> index >> val ;
        if (a[index - 1] != val) {
            int x = f(max(0ll , index - 1 - a[index - 1] + 1) , min(n - 1 , index - 1 + a[index - 1] - 1) , n , a) ;
            swap(a[index - 1] , val) ;
            int y = f(max(0ll , index - 1 - a[index - 1] + 1) , min(n - 1 , index - 1 + a[index - 1] - 1) , n , a) ;
            cout << ans + (y - x) << endl ;
            swap(a[index - 1] , val) ;
        } else {
            cout << ans << endl ;
        }
        swap(a[index - 1] , val) ;
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