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
    cin >> n ; 
    int _id , k ;
    string x ; 
    vector<vector<int>> freq(2 , vector<int> (26 , 0)) ; 
    freq[0][0] = 1 ; 
    freq[1][0] = 1 ;
    int len[2] = {1 , 1} ;
    for (int i = 0 ; i < n ; i++) {
        cin >> _id >> k >> x ; 
        for (int j = 0 ; j < x.length() ; j++) {
            freq[_id - 1][x[j] - 'a'] += k ; 
            len[_id - 1] += k ;
        }
        int a = 25 , b = 25 ; 
        while (freq[0][a] == 0) {
            a-- ;
        }
        while (freq[1][b] == 0) {
            b-- ;
        }
        // either t's last character greater than 'a' or both have same last character but s is smaller
        cout << ((b > 0 || (b == a && len[0] < len[1])) ? "YES" : "NO") << endl ;
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