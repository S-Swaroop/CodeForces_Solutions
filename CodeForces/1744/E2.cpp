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

inline pair<int , int> possible (int x , int y , int &a , int &b , int &c , int &d) {
    int X = ((a / x) + 1) * x , Y = ((b / y) + 1) * y ;
    if (X <= c && Y <= d) {
        return {X , Y} ;
    } else {
        return {-1 , -1} ;
    }
}

void solve() {
    int a , b , c , d ; 
    cin >> a >> b >> c >> d ;
    vector<int> diva , divb ; 
    for (int i = 1 ; i * i <= a ; i++) {
        if (a % i == 0) {
            diva.push_back(i) ;
            if (i != a / i) {
                diva.push_back(a / i) ;
            }
        }
    }
    for (int i = 1 ; i * i <= b ; i++) {
        if (b % i == 0) {
            divb.push_back(i) ;
            if (i != b / i) {
                divb.push_back(b / i) ;
            }
        }
    }
    sort(diva.begin() , diva.end()) ;
    sort(divb.begin() , divb.end()) ;
    for (int i : diva) {
        for (int j : divb) {
            int x = i * j , y = (a * b) / x ;
            pair<int , int> res = possible(x , y , a , b , c , d) ;
            if (res.first != -1) {
                cout << res.first << " " << res.second << endl ; 
                return ;
            }
        }
    }
    cout << -1 << " " << -1 << endl ;
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