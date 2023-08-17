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
    vector<int> ans;
    ans.push_back(1);
    vector<bool> done(n + 1, false);
    done[1] = true;
    int curr = 2;
    for (int i = 1; i < n; i++) {
        if (2 * ans.back() <= n && !done[2 * ans.back()]) {
            int t = 2 * ans.back();
            ans.push_back(t);
            done[t] = true;
        } else {
            while (done[curr]) {
                curr++;
            }
            ans.push_back(curr);
            done[curr] = true;
        } 
    }
    for (int &i: ans)   cout << i << " ";
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