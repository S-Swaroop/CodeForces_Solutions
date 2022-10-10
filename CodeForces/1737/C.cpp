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

const int N = 1e4 + 10 ;
int grid[N][N] ;
int dx[4] = {-1 , 0 , 1 , 0} ; 
int dy[4] = {0 , -1 , 0 , 1} ;
int dax[2] = {-1 , 1} ;
int day[2] = {-1 , 1} ;

bool isValid (int x , int y , int n , int test_no) {
    return (x >= 1 && y >= 1 && x <= n && y <= n && grid[x][y] != test_no) ;
}

bool dfs (vector<pair<int , int>> &points , int n , pair<int , int> &target , int test_no) {
    for (auto &i : points) {
        if (i == target) {
            return true ;
        }
        grid[i.first][i.second] = test_no ;
    }

    for (auto &p : points) {
        for (int i = 0 ; i < 4 ; i++) {
            if (isValid(p.first + dx[i] , p.second + dy[i] , n , test_no)) {
                p.first += dx[i] ; 
                p.second += dy[i] ;
                for (auto &_p : points) {
                    if (_p == p) {
                        p.first += dx[i] ; 
                        p.second += dy[i] ;
                        if (isValid(p.first , p.second , n , test_no)) {
                            if (dfs (points , n , target , test_no)) {
                                return true ;
                            }
                        }
                        p.first -= dx[i] ; 
                        p.second -= dy[i] ;
                    }
                }
                p.first -= dx[i] ; 
                p.second -= dy[i] ;
            }
        }
        for (int i : dax) {
            for (int j : day) {
                p.first += i ; 
                p.second += j ;
                if (isValid(p.first , p.second , n , test_no)) {
                    for (auto &_p : points) {
                        if (_p == p) {
                            p.first += i ; 
                            p.second += j ;
                            if (isValid(p.first , p.second , n , test_no)) {
                                if (dfs (points , n , target , test_no)) {
                                    return true ;
                                }
                            }
                            p.first -= i ; 
                            p.second -= j ; 
                        }
                    }
                }
                p.first -= i ; 
                p.second -= j ;
            }
        }
    }
    return false ;
}

void solve(int test_no) {
    int n ;
    cin >> n ;
    vector<pair<int , int>> a(3) ; 
    for (auto &i : a) {
        cin >> i.first >> i.second ;
    } 
    pair<int , int> target ;
    cin >> target.first >> target.second ;
    bool found = dfs (a , n , target , test_no) ;
    if (found) {
        cout << "YES" << endl ;
    } else {
        cout << "NO" << endl ;
    }
}

int32_t main() {
   cin.tie(NULL) ;
   std::ios::sync_with_stdio(false) ;
   
   #ifndef ONLINE_JUDGE
   freopen("INPUT.txt","r",stdin) ;
   freopen("OUTPUT.txt","w",stdout) ;
   #endif
   memset(grid , 0 , sizeof(grid)) ;
   int t = 1 ;
   cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve(i) ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}