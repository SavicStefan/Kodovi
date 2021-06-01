int d[maxn];
void bfs(int s) {
	ff(i,1,n)d[i] = inf;
	deque<int> q;
	q.push_front(s);
	d[s] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop_front();
		for(auto c : g[v]) {
			int u = c.fi;
			int w = c.se;
			if(d[u] > d[v] + w) {
				d[u] = d[v] + w;
				if(w == 0)q.push_front(u);
				else q.push_back(u);
			}
		}
	}
}
