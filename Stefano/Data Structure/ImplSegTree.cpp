int idx = 0;
int ls[4 * maxn], rs[4 * maxn], root, bor[4 * maxn];
void update(int &v, ll tl, ll tr, ll pos, ll val) {
    if(!v)v = ++idx;
    if(tl == tr) {
        bor[v] += val;
        return;
    }
    ll mid = (tl + tr) / 2;
    if(pos <= mid)update(ls[v], tl, mid, pos, val);
    else update(rs[v], mid + 1, tr, pos, val);
    bor[v] = bor[ls[v]] + bor[rs[v]];
}

ll kveri(int v, ll tl, ll tr, ll l, ll r) {
    if(!v || tl > r || l > tr)return 0;
    if(tl >= l && tr <= r)return bor[v];
    int mid = (tl + tr) / 2;
    return kveri(ls[v], tl, mid, l, r) + kveri(rs[v], mid + 1, tr, l, r);
}
