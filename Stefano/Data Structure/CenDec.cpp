int cnt[maxn];
bool bio[maxn];
void dfs_sz(int v, int p) {
	cnt[v] = 1;
	for(auto u : g[v]) {
		if(u == p || bio[u])continue;
		dfs_sz(u, v);
		cnt[v] += cnt[u];
	}
}

int centroid(int v, int p, int vel) {
	for(auto u : g[v]) {
		if(u == p || bio[u])continue;
		if(cnt[u] > vel / 2)return centroid(u, v, vel);
	}
	return v;
}

void decompose(int v, int p) {
	dfs_sz(v, p);
	int cen = centroid(v, p, cnt[v]);
	bio[cen] = 1;

	for(auto u : g[cen]) {
		if(u == p || bio[u])continue;
		decompose(u, cen);
	}

}
