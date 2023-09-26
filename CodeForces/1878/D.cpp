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

int findRange(int x, int k, vector<int> &l, vector<int> &r) {
    int low = 0, high = k + 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (x <= r[mid - 1]) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high - 1;
}

int findLastOp(int indx, int L, int R, vector<int> &ops) {
    int low = 0, high = (int)ops.size() + 1;
    while (high - low > 1) {
        int mid = low + ((high - low) >> 1);
        int l = min(ops[mid - 1], R + L - ops[mid - 1]);
        int r = max(ops[mid - 1], R + L - ops[mid - 1]);
        int resolvedIndex = min(indx, R + L - indx);
        if (l <= resolvedIndex) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low - 1;
}

void solve() {
    int n, k, q;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (int &i: l) cin >> i;
    for (int &i: r) cin >> i;
    cin >> q;
    vector<int> X(q);
    for (int &i: X) cin >> i;
    vector<int> flips(n + 2, 0);
    for (int &x: X) {
        int index = findRange(x, k, l, r);
        int lx = min(x, l[index] + r[index] - x);
        flips[lx - 1]++;
    }
    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int a = l[i] - 1, b = r[i] - 1; a < b; a++, b--) {
            sum += flips[a];
            if (sum % 2 != 0) {
                swap(s[a], s[b]);
            }
        }
    }
    cout << s << endl;
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