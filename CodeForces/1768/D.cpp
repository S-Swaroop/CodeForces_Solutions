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

int minSwapsToSort(vector<int> &arr, int n){
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        ans += (cycle_size - 1);
    }
    return ans;
}

int minSwapToMakeArraySame(vector<int> a, vector<int> b, int n) {
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[b[i]] = i;
    for (int i = 0; i < n; i++)
        b[i] = mp[a[i]];
    return minSwapsToSort(b, n);
}

void solve() {
    int n; 
    cin >> n; 
    vector<int> a(n); 
    for (int &i: a) cin >> i; 
    vector<int> a1(n, 0), a2(n, 0); 
    int ans = n;
    iota(a1.begin(), a1.end(), 1ll); 
    for (int i = 1; i < n; i++) {
        swap(a1[i - 1], a1[i]); 
        if (a1[i] == a[i] && a1[i - 1] == a[i - 1]) {
            ans = min(ans, minSwapToMakeArraySame(a1, a, n));
        }
        swap(a1[i - 1], a1[i]); 
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