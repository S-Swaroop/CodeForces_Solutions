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
    char c ; 
    cin >> n >> c ; 
    string s ; 
    cin >> s ; 
    if (c == 'g') {
        cout << 0 << endl ; 
        return ;
    }
    vector<int> f(n , -1) ;
    int g = n - 1 ; 
    while (g >= 0 && s[g] != 'g')   g-- ;
    for (int i = g - 1 ; i >= 0 ; i--) {
        if (s[i] == 'g') {
            g = i ;
        }
        if (s[i] == c) {
            f[i] = g - i ;
        }
    }
    for (int i = n - 1 ; i >= 0 ; i--) {
        if (s[i] == c) { 
            if (f[i] == -1) {
                f[i] = n - i + g ;
            } else {
                break ;
            }
        }
    }
    cout << *max_element(f.begin() , f.end()) << endl ;
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