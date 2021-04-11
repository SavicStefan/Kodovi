ll bor[4 * maxn];
ll lenj[4 * maxn];
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

void propagate(int v, int tl, int tr) {
	if(lenj[v]) {
		bor[v] += lenj[v];
		if(tl != tr) {
			lenj[2 * v] += lenj[v];
			lenj[2 * v + 1] += lenj[v];
		}
		lenj[v] = 0;
	}
}

void lazyupd(int v, int tl, int tr, int l, int r, ll val) {
	propagate(v, tl, tr);
	if(tl > tr || tl > r || tr < l)return;
	if(tl >= l && tr <= r) {
		bor[v] += val;
		if(tl != tr) {
			lenj[v * 2] += val;
			lenj[v * 2 + 1] += val;
		}
		return;
	}
	int mid = (tl + tr) / 2;
	lazyupd(v * 2, tl, mid, l, r, val);
	lazyupd(v * 2 + 1, mid + 1, tr, l, r, val);
	bor[v] = bor[v * 2] + bor[v * 2 + 1];
}

ll kveri(int v, int tl, int tr, int l, int r) {
	propagate(v, tl, tr);
	if(tl > r || tr < l)return 0;
	if(tl >= l && tr <= r)return bor[v];
	int mid = (tl + tr) / 2;
	return kveri(v * 2, tl, mid, l, r) + kveri(v * 2 + 1, mid + 1, tr, l, r);
}
