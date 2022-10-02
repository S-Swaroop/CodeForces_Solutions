/*
***************************
* Author : SHARAN SWAROOP *
***************************
*/
#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define debug(x) cerr << #x << " : " << x << endl ;
using namespace std ;

bool isCycle (vector<int> &prev) {
    for (int i = 0 ; i < 26 ; i++) {
        int j = prev[i] ;
        while (j != -1 && j != i) {
            j = prev[j] ;
        }
        if (j == i) {
            return true ;
        }
    }
    return false ;
}

void solve() {
    int n ; 
    cin >> n ; 
    string s ; 
    cin >> s ; 
    vector<int> prev(26 , -1) , next(26 , -1) ;
    for (int i = 0 ; i < n ; i++) {
        if (prev[s[i] - 'a'] == -1) {
            for (int j = 0 ; j < 26 ; j++) {
                if ((s[i] - 'a') != j && next[j] == -1) {
                    next[j] = s[i] - 'a' ; 
                    prev[s[i] - 'a'] = j ;
                    if (isCycle(prev)) {
                        next[j] = -1 ;
                        prev[s[i] - 'a'] = -1 ;
                    } else {
                        break ;
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < 26 ; i++) {
        if (prev[i] == -1) {
            for (int j = 0 ; j < 26 ; j++) {
                if (next[j] == -1) {
                    prev[i] = j ;
                    next[j] = i ;
                    break ;
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        s[i] = 'a' + prev[s[i] - 'a'] ;
    }
    cout << s << endl ;
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