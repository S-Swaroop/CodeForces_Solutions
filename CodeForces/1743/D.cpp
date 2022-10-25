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

string OR (string a , string b) {
    if (a.size() > b.size()) {
        swap(a , b) ;
    }
    reverse(a.begin() , a.end()) ;
    while (a.size() < b.size()) {
        a += '0' ;
    }
    reverse(a.begin() , a.end()) ;
    for (int i = 0 ; i < a.length() ; i++) {
        a[i] = max(a[i] , b[i]) ;
    }
    return a ;
}

void solve() {
    int n ; 
    cin >> n ; 
    string s ; 
    cin >> s ;
    while (!s.empty() && s[0] == '0')   s.erase(0 , 1) ;
    if (s.empty()) {
        cout << 0 << endl ; 
        return ;
    }
    int len = -1 ; 
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '0') {
            len = s.length() - i ;
            break ;
        }
    }
    if (len == -1) {
        cout << s << endl ; 
        return ;
    }
    string ans = s ; 
    for (int i = 0 ; i + len - 1 < s.length() ; i++) {
        ans = max(ans , OR(s , s.substr(i , len))) ;
    }
    cout << ans << endl ;
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