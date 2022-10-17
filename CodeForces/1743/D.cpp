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
    struct TrieNode* children[2] ;
    bool isEndOfWord ;
    TrieNode() {
        this->isEndOfWord = false ;
        this->children[0] = this->children[1] = nullptr ;
    }
};

void insert(struct TrieNode *root , string key) {
    struct TrieNode *pCrawl = root ;
    for (int i = 0 ; i < key.length() ; i++) {
        int index = (key[i] - '0') ;
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = new TrieNode() ;
        }
        pCrawl = pCrawl->children[index] ;
    }
    pCrawl->isEndOfWord = true;
}

int dfs (int curr , string &ans , struct TrieNode *root) {
    if (curr == ans.length() || !root) {
        return 0 ;
    } else if (ans[curr] == '0') {
        if (root->children[1]) {
            struct TrieNode *c = root->children[1] ;
            return 1 + dfs (curr + 1 , ans , c) ;
        } 
        return 0 ;
    } else {
        int res = 0 ;
        if (root->children[1]) {
            struct TrieNode *c = root->children[1] ;
            res = max(res , 1 + dfs (curr + 1 , ans , c)) ;
        } 
        if (root->children[0]) {
            struct TrieNode *c = root->children[0] ;
            res = max(res , 1 + dfs (curr + 1 , ans , c)) ;
        } 
        return res ;
    }
}

void solve() {
    struct TrieNode *root = new TrieNode() ;
    int n ; 
    string s ; 
    cin >> n >> s ;
    string s1 , s1complement ;
    bool found1 = false ;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == '1') {
            found1 = true ;
        } else {
            if (found1) {
                s1 = s.substr(i) ;
                break ;
            }
        }
    }
    if (!found1) {
        cout << 0 << endl ; 
        return ;
    }
    if (s1.empty()) {
        cout << string(n , '1') << endl ;
        return ;
    }
    int len = s1.length() ;
    for (int i = 0 ; i + len < n ; i++) {
        if (s[i] == '1') {
            insert(root , s.substr(i , len)) ;
        }
    }
    string ans = s ; 
    while (!ans.empty() && ans[0] == '0') {
        ans.erase(0 , 1) ;
    }
    int curr = 0 ; 
    while (curr < ans.length() && ans[curr] == '1')     curr++ ;
    int x = dfs (curr , ans , root) ;
    for (int i = curr ; i < ans.length() && x > 0 ; i++) {
        x-- ;
        ans[i] = '1' ;
    }
    cout << ans << endl ;
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