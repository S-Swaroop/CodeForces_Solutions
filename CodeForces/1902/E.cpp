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

struct TrieNode {
    map<int, TrieNode*> children;
    map<int, int> fromCount;
    TrieNode() {}
};

void insert(struct TrieNode* root, string key) {
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (pCrawl->children.find(index) == pCrawl->children.end()) {
            pCrawl->children[index] = new TrieNode();
        }
        pCrawl->fromCount[key[i] - 'a']++;
        pCrawl = pCrawl->children[index];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (string &i: a)  cin >> i;
    
    TrieNode *root = new TrieNode();

    for (int i = 0; i < n; i++) {
        insert(root, a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[i].length();
    }

    ans *= 2 * n;

    for (int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
        int res = 0;
        TrieNode *curr = root;
        for (int j = 0; j < a[i].length(); j++) {
            int index = a[i][j] - 'a';
            if (curr->children.find(index) != curr->children.end()) {
                res += curr->fromCount[index];
                curr = curr->children[index];
            } else {
                break;
            }
        }
        ans -= res * 2;
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
//    cin >> t ;/*comment this line if no test cases*/
   for(int i = 1 ; i <= t ; i++)   solve() ; 
    
   double runtime = clock() * 1.0 /CLOCKS_PER_SEC ;
   debug(runtime) ; 
   
   return 0 ;
}