ll dist[maxn];
void dij(int s) {
	ff(i,1,n)dist[i] = inf;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({dist[s] = 0, s});
	while(!pq.empty()) {
		pii v = pq.top();
		pq.pop();
		if(dist[v.se] < v.fi)continue;
		for(auto c : g[v.se]) {
			int u = c.fi;
			int w = c.se;
			if(dist[u] > w + v.fi) {
				dist[u] = w + v.fi;
				pq.push({dist[u], u});
			}
		}
	}
}
