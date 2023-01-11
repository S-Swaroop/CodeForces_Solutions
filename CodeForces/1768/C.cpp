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
    cin >> n; 
    bool possible = true; 
    vector<int> a(n, 0), b(n, 0), c(n, 0);
    vector<int> fb(n + 1, -1), fc(n + 1, -1); 
    set<int> not_done_b, not_done_c;
    for (int &i: a) {
        cin >> i;  
    }
    for (int i = 0; i < n; i++) {
        if (fb[a[i]] == -1) {
            fb[a[i]] = i; 
            b[i] = a[i]; 
        } else if (fc[a[i]] == -1) {
            fc[a[i]] = i; 
            c[i] = a[i];
        } else {
            possible = false; 
            break;
        }
    }
    if (!possible) {
        cout << "NO" << endl; 
        return; 
    }
    for (int i = 1; i <= n && possible; i++) {
        if (fb[i] == -1)    not_done_b.insert(i); 
        if (fc[i] == -1)    not_done_c.insert(i); 
    }
    for (int i = 0; i < n && possible; i++) {
        if (b[i] == 0) {
            auto it = not_done_b.upper_bound(c[i]); 
            if (it == not_done_b.begin()) {
                possible = false; 
            } else {
                --it; 
                b[i] = *it;
                not_done_b.erase(it); 
            }
        } else if (c[i] == 0) {
            auto it = not_done_c.upper_bound(b[i]); 
            if (it == not_done_c.begin()) {
                possible = false; 
            } else {
                --it; 
                c[i] = *it;
                not_done_c.erase(it); 
            }
        }
    }
    if (possible) {
        cout << "YES" << endl; 
        for (int &i: b) cout << i << " ";
        cout << endl; 
        for (int &i: c) cout << i << " ";
        cout << endl; 
    } else {
        cout << "NO" << endl;
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