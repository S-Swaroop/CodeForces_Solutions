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
    int n;
    string s;
    cin >> n >> s;
    int zero = count(s.begin(), s.end(), '0');
    int one = count(s.begin(), s.end(), '1');
    if (zero > one) {
        cout << "YES" << endl;
    } else {
        bool possible = false;
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] == '0' && s[i + 1] == '0') || (s[i] != s[i + 1])) {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
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