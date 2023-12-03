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
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int low = 0, high = n;
    int daysWorked = n;
    int tasksUnlocked = ((n - 1) / 7) + 1;

    auto possible = [&](int x) {
        int pointsEarned = (x * l) + (min(x * 2, tasksUnlocked) * t);
        return pointsEarned >= p;
    };

    while (high - low > 1) {
        int mid = low + ((high - low) >> 1);
        if (possible(mid)) {
            high = mid;
            daysWorked = min(daysWorked, mid);
        } else {
            low = mid;
        }
    }

    cout << max(0ll, n - daysWorked) << endl;
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