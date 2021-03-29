int sp[maxn][20];
void init_sp() {
	ff(i,1,n)sp[i][0] = niz[i];
	ff(j,1,19) {
		for(int i=1; i + (1 << j) - 1 <= n; i++) {
			sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int rmq(int l, int r) {
	int x = 31 - __builtin_clz(r - l + 1);
	return min(sp[l][x], sp[r - (1 << x) + 1][x]);
}
