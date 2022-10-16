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

pair<int , int> possible (int x , int y , int &a , int &b , int &c , int &d) {
    if (x > c || y > d) {
        return {-1 , -1} ;
    }
    int oldx = x , oldy = y ;
    if (x < a) {
        x = ((a + x - 1) / x) * x ;
    }
    if (x == a) {
        x += oldx ;
    }
    if (y < b) {
        y = ((b + y - 1) / y) * y ;
    }
    if (y == b) {
        y += oldy ;
    }
    if (x > c || y > d) {
        return {-1 , -1} ;
    }
    return {x , y} ;
}

void solve() {
    int a , b , c , d ; 
    cin >> a >> b >> c >> d ;
    int num = a * b ; 
    for (int i = 1 ; i * i <= num ; i++) {
        if (num % i == 0) {
            int x = i , y = num / i ;
            pair<int , int> res1 = possible(x , y , a , b , c , d) ;
            if (res1.first != -1) {
                cout << res1.first << " " << res1.second << endl ; 
                return ;
            }
            swap(x , y) ; 
            pair<int , int> res2 = possible(x , y , a , b , c , d) ;
            if (res2.first != -1) {
                cout << res2.first << " " << res2.second << endl ; 
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