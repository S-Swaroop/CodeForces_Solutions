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

int sumOfSquares(int n) {
    return max(0ll, (n * (n + 1) * (2 * n + 1)) / 6);
}

int f(int k, int n) {
    if (k < 1) {
        return INT_MIN;
    } 
    if (k > n) {
        return INT_MAX;
    }
    int sum = sumOfSquares(k - 1);
    int i = k, j = n;
    int _max = 0;
    while (i <= j) {
        sum += 2 * i * j;
        if (i == j) {
            sum -= i * j;
        }
        _max = max(_max, i * j);
        i++; 
        j--;
    }
    return sum - _max;
}

int findBitonicPoint(int low, int high, int n) {
    if (low == high) {
        return high;
    }
    int mid = low + ((high - low) >> 1);
    if (f(mid, n) > f(mid - 1, n) && f(mid, n) > f(mid + 1, n)) {
        return mid;
    } else if (f(mid, n) < f(mid + 1, n)) {
        return findBitonicPoint(mid + 1, high, n);
    } else {
        return findBitonicPoint(low, mid, n);
    }
}

void solve() {
    int n; 
    cin >> n; 
    int ans = findBitonicPoint(0, n + 1, n);
    cout << f(ans, n) << endl;
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