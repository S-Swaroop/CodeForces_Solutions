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

struct Node {
    char token;
    Node *left, *right;
    Node() {
        token = '_';
        left = nullptr;
        right = nullptr;
    }
};

int dfs(Node *root, int dist) {
    if (!root) {
        return INT_MAX;
    }
    if (!root->left && !root->right) {
        return dist;
    }
    int res = INT_MAX;
    if (root->left) {
        res = min(res, dfs(root->left, dist + (root->token != 'L')));
    }
    if (root->right) {
        res = min(res, dfs(root->right, dist + (root->token != 'R')));
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<Node*> a(n);
    for (int i = 0; i < n; i++) a[i] = new Node();
    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        if (l > 0)  a[i]->left = a[l - 1];
        if (r > 0)  a[i]->right = a[r - 1];
        a[i]->token = s[i];
    }
    int ans = dfs(a[0], 0);
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