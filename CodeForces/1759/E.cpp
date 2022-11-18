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

const int N = 2e5 + 1 ;

int memo[N][3][2] ;

map<int , pair<int , int>> moves ;

void init () {
    moves[1] = {0 , 0} ;
    moves[2] = {1 , 0} ;
    moves[3] = {0 , 1} ;
    moves[4] = {2 , 0} ;
    moves[6] = {1 , 1} ;
    moves[12] = {2 , 1} ;
}

int dp (int index , int health , int blue , int green , vector<int> &a) {
    if (index >= (int)a.size()) {
        return 0 ;
    } else if (memo[index][blue][green] != -1) {
        return memo[index][blue][green] ;
    } else {
        int &res = memo[index][blue][green] ;
        res = 0 ;
        for (auto &i : moves) {
            if (i.second.first + blue <= 2 && i.second.second + green <= 1 && (health * i.first) > a[index]) {
                res = max(res , dp(index + 1 , (health * i.first) + (a[index] / 2) , blue + i.second.first , green + i.second.second , a) + 1) ;
            }
        }
        return res ;
    }
}

void solve() {
    int blue = 2 , green = 1 ;
    int n , h ;
    cin >> n >> h ;
    vector<int> a(n) ;
    for (int &i : a)    cin >> i ; 
    sort(a.begin() , a.end()) ;
    
    int dp[n + 1][3][2] ;
    memset(dp , 0 , sizeof(dp)) ;

    for (int i = 0 ; i < 3 ; i++) { 
        for (int j = 0 ; j < 2 ; j++) {
            dp[0][i][j] = h ;
        }
    }

    int ans = 0 ; 

    for (int i = 1 ; i <= n ; i++) {
        for (int j1 = 0 ; j1 < 3 ; j1++) {
            for (int k1 = 0 ; k1 < 2 ; k1++) {
                for (int j2 = 0 ; j2 < 3 ; j2++) {
                    for (int k2 = 0 ; k2 < 2 ; k2++) {
                        if (j1 + j2 <= 2 && k1 + k2 <= 1) {
                            dp[i][j1 + j2][k1 + k2] = max(dp[i][j1 + j2][k1 + k2] , (dp[i - 1][j2][k2] * (1 << j1) * (k1 ? 3 : 1)) + ((dp[i - 1][j2][k2] * (1 << j1) * (k1 ? 3 : 1)) > a[i - 1] ? (a[i - 1] / 2) : 0)) ;
                            if (dp[i][j1 + j2][k1 + k2] > a[i - 1]) {
                                ans = i ;
                            }
                        }
                    }
                }
            }
        }
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
   init() ;
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}