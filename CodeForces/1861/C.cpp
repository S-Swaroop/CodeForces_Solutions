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
    bool possible = true;
    int current_size = 0;
    int min_size_in_range = 0;
    int index_last_result = -1;
    for (int i = 0; i < n && possible; i++) {
        if (s[i] == '+') {
            current_size++;
        } else if (s[i] == '-') {
            current_size--;
        } else {
            if (s[i] == '0') {
                if (current_size <= 1) {
                    possible = false;
                }
            }
            if (index_last_result != -1)  {
                if (s[i] == '0' && s[index_last_result] == '1') {
                    if (min_size_in_range <= 1 && current_size > 1) {
                        
                    } else {
                        possible = false;
                    }
                } else if (s[i] == '1' && s[index_last_result] == '0') {
                    if (min_size_in_range > 1) {
                        possible = false;
                    }
                } 
            }
            index_last_result = i;
            min_size_in_range = current_size;
        }
        min_size_in_range = min(min_size_in_range, current_size);
    }
    cout << (possible ? "YES" : "NO") << endl;
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