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
    int n, k;
    cin >> n >> k;
    string s; 
    cin >> s;
    string odd, even;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            odd.push_back(s[i]);
        } else {
            even.push_back(s[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            s[i] = odd[i / 2];
        } else {
            s[i] = even[i / 2];
        }
    }
    if ((k - 1) % 2 != 0) {
        sort(s.begin(), s.end());
    } 
    cout << s << endl;
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