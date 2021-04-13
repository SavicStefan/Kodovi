void comb(int x, int y) {
	if(sz(dt[x]) < sz(dt[y]))swap(dt[x], dt[y]);
	for(auto c : dt[y]) {

	}
}

void dfs(int v, int p) {

	for(auto u : g[v]) {
		if(u != p) {
			dfs(u, v);
			comb(v, u);
		}
	}

}
