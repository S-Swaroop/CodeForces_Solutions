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

bool possible (int x, vector<int> &a) {
    int n = a.size(); 
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - x) < abs(a[i - 1] - x)) {
            return false;
        }
    }
    return true; 
}

int median (vector<int> a) {
    int n = a.size(); 
    sort(a.begin(), a.end()); 
    if (n & 1) {
        return a[n / 2]; 
    } else {
        return (a[n / 2] + a[n / 2 + 1]) / 2;
    }
}

void solve() {
    int n; 
    cin >> n; 
    vector<int> a(n); 
    for (int &i: a) cin >> i; 
    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl; 
    } else if (is_sorted(a.rbegin(), a.rend())) {
        cout << a[0] << endl; 
    } else {
        int mid = INT_MIN; 
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                mid = max(mid, (a[i] + a[i - 1]) >> 1); 
            }
        }
        for (int i = mid - 1; i <= mid + 1; i++) {
            if (possible(i, a)) {
                cout << i << endl; 
                return; 
            }
        }
        cout << -1 << endl; 
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