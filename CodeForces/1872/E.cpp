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
    vector<int> a(n);
    for (int &i: a) cin >> i;
    string s;
    cin >> s;
    vector<int> pref1(n + 1, 0), pref0(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref1[i + 1] ^= pref1[i];
        pref0[i + 1] ^= pref0[i];
        if (s[i] == '1') {
           pref1[i + 1] ^= a[i];
        } else {
            pref0[i + 1] ^= a[i];
        }
    }
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero ^= a[i];
        } else {
            one ^= a[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int _one = pref1[r] ^ pref1[l - 1];
            int _zero = pref0[r] ^ pref0[l - 1];
            one ^= _one ^ _zero;
            zero ^= _one ^ _zero;
        } else {
            int g;
            cin >> g;
            if (g) {
                cout << one << " ";
            } else {
                cout << zero << " ";
            }
        }
    }
    cout << endl;
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