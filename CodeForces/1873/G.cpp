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
    string s;
    cin >> s;
    int n = s.length();
    int m = count(s.begin(), s.end(), 'B');
    vector<int> left(m, 0), right(m, 0);
    int a = 0;
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (s[i] == 'A') {
            a++;
        } else {
            left[j] = a;
            a = 0;
            j++;
        }
    }
    a = 0, j = m - 1;
    for (int i = n - 1; i >= 0 && j >= 0; i--) {
        if (s[i] == 'A') {
            a++;
        } else {
            right[j] = a;
            a = 0;
            j--;
        }
    }
    int curr = accumulate(left.begin(), left.end(), 0ll);
    int ans = curr;
    for (int i = m - 1; i >= 0; i--) {
        curr -= left[i];
        curr += right[i];
        ans = max(ans, curr);
    }
    cout << ans << endl;
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