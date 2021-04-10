int idx = 0;
int root[20 * maxn], ls[20 * maxn], rs[20 * maxn], bor[20 * maxn];
void update(int &v, int rv, int tl, int tr, int pos, int x) {
    v= ++idx, ls[v] = ls[rv], rs[v] = rs[rv], bor[v] = bor[rv];
    if(tl == tr) {
        bor[v] += x;
        return;
    }
    int mid = (tl + tr) / 2;
    if(pos <= mid)update(ls[v], ls[rv], tl, mid, pos, x);
    else update(rs[v], rs[rv], mid + 1, tr, pos, x);
    bor[v] = bor[ls[v]] + bor[rs[v]];
}
int kveri(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr || !v)return 0;
    if(tl >= l && tr <= r)return bor[v];
    int mid = (tl + tr) / 2;
    return kveri(ls[v], tl, mid, l, r) + kveri(rs[v], mid + 1, tr, l, r);
}
