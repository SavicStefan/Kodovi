ll bor[4 * maxn];
void build(int v, int tl, int tr) {
	if(tl == tr) {
		bor[v] = niz[tl];
		return;
	}
	int mid = (tl + tr) / 2;
	build(v * 2, tl, mid);
	build(v * 2 + 1, mid + 1, tr);
	bor[v] = bor[v * 2] + bor[v * 2 + 1];
}

void update(int v, int tl, int tr, int pos, ll val) {
	if(tl == tr) {
		bor[v] += val;
		return;
	}
	int mid = (tl + tr) / 2;
	if(pos <= mid)update(v * 2, tl, mid, pos, vre);
	else update(v * 2 + 1, mid + 1, tr, pos, vre);
	bor[v] = bor[v * 2] + bor[v * 2 + 1];
}

ll kveri(int v, int tl, int tr, int l, int r) {
	if(tl > r || tr < l)return 0;
	if(tl >= l && tr <= r)return bor[v];
	int mid = (tl + tr) / 2;
	return kveri(v * 2, tl, mid, l, r) + kveri(v * 2 + 1, mid + 1, tr, l, r);
}
