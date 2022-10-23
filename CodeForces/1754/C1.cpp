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
    vector<int> a(n) ; 
    int pos = count(a.begin() , a.end() , 1) ; 
    int neg = count(a.begin() , a.end() , 1) ; 
    for (int &i : a)    cin >> i ; 
    int greater = pos > neg ? 1 : -1 ;
    int need = abs(pos - neg) ;
    int sum = 0 ;
    vector<pair<int , int>> segs ;
    for (int i = 0 ; i < n ; i++) {
        if (i < n - 1 && a[i] == a[i + 1] && a[i] == greater && need > 1) {
            segs.push_back({i , i + 1}) ;
            i++ ;
            need -= 2 ;
        } else if (i < n - 1 && need > 0 && a[i] == 0 && a[i + 1] == greater) {
            segs.push_back({i , i + 1}) ; 
            i++ ;
            need-- ;
            sum += greater * -1 ;
        } else {
            segs.push_back({i , i}) ;
            sum += a[i] ;
        }
    }
    if (sum != 0) {
        cout << -1 << endl ; 
        return ;
    }
    cout << (int)segs.size() << endl ;
    for (auto &i : segs) {
        cout << i.first + 1 << " " << i.second + 1 << endl ;
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