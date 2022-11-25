struct PST {
#define lc t[cur].l
#define rc t[cur].r
  struct node {
    int l = 0, r = 0, lazy = 0, p = 0;
    mint val = 0;
  } t[300 * N];
  int T = 0;
  int build(int b, int e) {
    int cur = ++T;
    if(b == e) return cur;
    int mid = b + e >> 1;
    lc = build(b, mid);
    rc = build(mid + 1, e);
    return cur;
  }
  int push(int pre, int b, int e, int x = 0) {
    int cur = ++T;
    t[cur] = t[pre];
    t[cur].lazy ^= x;
    if(t[cur].lazy) {
      t[cur].val = s[e] - s[b - 1] - t[cur].val;
      t[cur].p ^= 1;
      if(b != e) {
        lc = ++T;
        rc = ++T;
        t[lc] = t[t[pre].l];
        t[rc] = t[t[pre].r];
        t[lc].lazy ^= 1, t[rc].lazy ^= 1;
      }
    }
    t[cur].lazy = 0;
    return cur;
  }
  int upd(int pre, int b, int e, int i, int j) {
    int cur = push(pre, b, e);
    if(b > j || e < i) return cur;
    if(i <= b && e <= j) {
      cur = push(cur, b, e, 1);
      return cur;
    }
    int mid = b + e >> 1;
    lc = upd(lc, b, mid, i, j);
    rc = upd(rc, mid + 1, e, i, j);
    t[cur].val = t[lc].val + t[rc].val;
    return cur;
  }
  int cmp(int cur, int oth, int b, int e) {
    cur = push(cur, b, e);
    oth = push(oth, b, e);
    if(t[cur].val == t[oth].val) return 0;
    if(b == e) {
      int x = t[cur].p, y = t[oth].p;
      if(x == y) return 0;
      else if(x > y) return 1;
      else return 2;
    }
    int mid = b + e >> 1;
    int p = cmp(lc, t[oth].l, b, mid);
    if(p) return p;
    return cmp(rc, t[oth].r, mid + 1, e);
  }
  void print(int cur, int b, int e) {
    cur = push(cur, b, e);
    if(b == e) {
      cout << t[cur].p;
      return;
    }
    int mid = b + e >> 1;
    print(lc, b, mid);
    print(rc, mid + 1, e);
  }
} t;

int root[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i < N; i++) s[i] = s[i - 1] + P.pow(i);
  int n, q;
  cin >> n >> q;
  root[0] = t.build(1, n);
  int ans = 0;
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    root[i] = t.upd(root[i - 1], 1, n, l, r);
    if(t.cmp(root[ans], root[i], 1, n) == 2) ans = i;
  }
  t.print(root[ans], 1, n);
  return 0;
}
