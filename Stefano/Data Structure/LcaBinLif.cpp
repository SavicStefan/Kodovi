int d[maxn];
int deda[maxn][20];
void dfs(int v, int p) {
	deda[v][0] = p;
	ff(i,1,19)deda[v][i] = deda[deda[v][i - 1]][i - 1];
	for(auto u : g[v]) {
		if(u != p) {
			d[u] = d[v] + 1;
			dfs(u, v);
		}
	}
}

int lca(int x, int y) {
	if(d[x] < d[y])swap(x, y);
	fb(i,19,0) {
		if((d[x] - d[y]) & (1 << i))x = deda[x][i];
	}
	fb(i,19,0) {
		if(deda[x][i] != deda[y][i]) {
			x = deda[x][i];
			y = deda[y][i];
		}
	}
	return (x == y ? x : deda[x][0]);
}
