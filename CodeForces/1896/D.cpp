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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    set<int> ones;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ones.insert(i);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int target;
            cin >> target;
            int m = ones.size();
            int totalSum = (2 * (n - m)) + m;
            if (totalSum >= target && totalSum % 2 == target % 2) {
                cout << "YES" << endl;
            } else {
                if (ones.empty()) {
                    cout << "NO" << endl;
                    continue;
                }
                int m1 = *ones.begin();
                int m2 = *ones.rbegin();
                int sum1 = totalSum - ((2 * m1) + 1);
                int sum2 = totalSum - ((2 * (n - m2 - 1)) + 1);
                if (max(sum1, sum2) >= target) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            int index, value;
            cin >> index >> value;
            if (a[index - 1] == 1) {
                if (value == 2) {
                    ones.erase(ones.find(index - 1));
                }
            } else {
                if (value == 1) {
                    ones.insert(index - 1);
                }
            }
            a[index - 1] = value;
        }
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