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

int sum(int n) {
    return (n * (n + 1)) / 2;
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    int divByX = n / x;
    int divByY = n / y;
    int divByXY = n / lcm(x, y);
    int Y = sum(divByY - divByXY); // give first few numbers to Y
    int X = sum(n) - sum(max(0ll, n - (divByX - divByXY)));
    cout << X - Y << endl;

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