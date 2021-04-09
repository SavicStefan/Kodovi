struct line {
	ll k, b;
	line(ll k = 0, ll b = inf) : k(k), b(b) {};
};

ll f(line p, ll x) {
	return p.k * A[x] + p.b;
}

line lch[4 * maxn];
void add_line(int v, int tl, int tr, line x) {
	ll a = f(lch[v], tl), b = f(x, tl), c = f(lch[v], tr), d = f(x, tr);
	if(tl == tr) {
		lch[v] = (a > b ? x : lch[v]);
		return;
	}
	if(a <= b && c <= d)return;
	if(a >= b && c >= d) {
		lch[v] = x;
		return;
	}
	int mid = (tl + tr) / 2;
	if(f(lch[v], mid) > f(x, mid))swap(lch[v], x);
	if(f(lch[v], tl) >= f(x, tl))add_line(v * 2, tl, mid, x);
	else add_line(v * 2 + 1, mid + 1, tr, x);
}
ll get(int v, int tl, int tr, ll x) {
	if(tl == tr)return f(lch[v], x);
	int mid = (tl + tr) / 2;
	if(x <= mid)return min(f(lch[v], x), get(v * 2, tl, mid, x));
	else return min(f(lch[v], x), get(v * 2 + 1, mid + 1, tr, x));
}
