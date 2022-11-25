#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
#define Tsetso ios_base::sync_with_stdio(0); cin.tie(0);
const ll  N = 1e5+15, mod = 1e9 + 7;
#define MAXN 100015
 
struct node
{
    int val;
 
    node* left, *right;
 
    node() {}
    node(node* l, node* r, int v)
    {
        left = l;
        right = r;
        val = v;
    }
};
 
int arr[MAXN];
 
node* version[MAXN];
 
void build(node* n,int low,int high)
{
    if (low==high)
    {
        n->val = arr[low];
        return;
    }
    int mid = (low+high) / 2;
    n->left = new node(NULL, NULL, 0);
    n->right = new node(NULL, NULL, 0);
    build(n->left, low, mid);
    build(n->right, mid+1, high);
    n->val = n->left->val + n->right->val;
}
 
void upgrade(node* prev, node* cur, int low, int high, int idx, int value)
{
    if (idx > high or idx < low or low > high)
        return;
    if (low == high)
    {
        cur->val = prev->val + value;
        return;
    }
    int mid = (low+high) / 2;
    if (idx <= mid)
    {
        cur->right = prev->right;
        cur->left = new node(NULL, NULL, 0);
        upgrade(prev->left,cur->left, low, mid, idx, value);
    }
    else
    {
        cur->left = prev->left;
        cur->right = new node(NULL, NULL, 0);
 
        upgrade(prev->right, cur->right, mid+1, high, idx, value);
    }
    cur->val = cur->left->val + cur->right->val;
}
 
int query(node* n, int low, int high, int l, int r)
{
    if (l > high or r < low or low > high)
        return 0;
    if (l <= low and high <= r)
        return n->val;
    int mid = (low+high) / 2;
    int p1 = query(n->left,low,mid,l,r);
    int p2 = query(n->right,mid+1,high,l,r);
    return p1+p2;
}
 
int32_t main() {
    Tsetso
    int n;
    cin >> n;
    node* root = new node(NULL, NULL, 0);
    build(root, 0, n-1);
    version[0] = root;
  /*
    version[1] = new node(NULL, NULL, 0);
    upgrade(version[0], version[1], 0, n-1, 4, 1);
    */
    cin.ignore();
    vector < int > last(n+1,0);
    int lst = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
        string temp ;
        getline(cin,temp);
        stringstream st(temp);
        while(st >> temp)
        {
            int add = temp[0] == '+';
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            reverse(temp.begin(),temp.end());
            int idx = atoi(temp.c_str());
            version[++lst] = new node(NULL, NULL, 0);
            upgrade(version[lst-1], version[lst], 0, n-1, idx, (add ? 1 : -1));
        }
        last[i] = lst;
    }
    vector < int > d(n);
    for ( int i = 0;  i < n ; i++)
        cin >> d[i];
    int val = 0 ;
    for ( int i = 1 ; i <= n ; i++)
        val = val +  query(version[last[d[i-1]]], 0, n-1, val, n-1),val %= n;
    cout << val;
}
