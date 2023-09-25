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
    cin >> n;
    vector<int> a[n];
    set<int> allOfThem;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            a[i].push_back(x);
            allOfThem.insert(x);
        }
    }
    int ans = 0; 
    for (auto target: allOfThem) {
        set<int> remaingSet;
        for (int i = 0; i < n; i++) {
            bool canConsiderSet = true;
            for (int j = 0; j < a[i].size() && canConsiderSet; j++) {
                if (a[i][j] == target) {
                    canConsiderSet = false;
                    break;
                }
            }
            if (canConsiderSet) {
                for (int &j: a[i]) {
                    remaingSet.insert(j);
                }
            }
        }
        ans = max(ans, (int)remaingSet.size());
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