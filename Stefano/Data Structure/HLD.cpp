// treba je jos proveriti da li radi i malo je promenti na moj stil
template<int SZ, bool VALS_IN_EDGES> struct HLD{ 
	int N; 
	vector<int> adj[SZ];
	int par[SZ], root[SZ], depth[SZ], sz[SZ], timer;
	int pos[SZ]; 
//	vi rpos; // rpos not used, but could be useful
	// INIT
	void add_edge(int u, int v){ 
		adj[u].pb(v);
		adj[v].pb(u);
	}
	void dfsSz(int v){ 
		sz[v] = 1; 
		for(auto u : adj[v]){
			par[u] = v; 
			depth[u] = depth[v]+1;
			adj[u].erase(find(all(adj[u]),v)); // remove parent from adj list
			dfsSz(u); 
			sz[v] += sz[u];
			if(sz[u] > sz[adj[v][0]])swap(u,adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = ++timer; 
		// lazyupd(1,1,N,pos[v],pos[v],niz[v])
//		rpos.pb(x);
		for(auto u : adj[v]) {
			root[u] = (u == adj[v][0] ? root[v] : u);
			dfsHld(u); 
		}
	}
	void init(int _N, int R = 1){ 
		N = _N; 
		par[R] = depth[R] = timer = 0; 
		dfsSz(R); 
		root[R] = R;
		dfsHld(R); 
	}
	int lca(int x, int y) {
		for (; root[x] != root[y]; y = par[root[y]])
			if (depth[root[x]] > depth[root[y]]) swap(x,y);
		return depth[x] < depth[y] ? x : y;
	}
	
	// LENJ BOR
	ll bor[4*SZ];
	ll lenj[4*SZ];
	void propagate(int v, int tl, int tr){
	    if(lenj[v]){
	        bor[v] += (tr - tl + 1) * lenj[v];
	        if (tl != tr) {
	            lenj[v * 2] += lenj[v];
	            lenj[v * 2 + 1] += lenj[v];
	        }
	        lenj[v] = 0;
	    }
	}
	void lazyupd(int v, int tl, int tr, int l, int r, ll vre){
	    propagate(v, tl, tr);
	    if(tl > tr || tl > r || tr < l)return;
	    if(tl >= l && tr <= r) {
	        bor[v] += (tr - tl + 1) * vre;
	        if (tl != tr) {
	            lenj[v * 2] += vre;
	            lenj[v * 2 + 1] += vre;
	        }
	        return;
	    }
	    int mid = (tl + tr) / 2;
	    lazyupd(v*2,tl,mid,l,r,vre);
	    lazyupd(v*2+1,mid+1,tr,l,r,vre);
	    bor[v] = bor[v * 2] + bor[v * 2 + 1];
	}
	ll kveri(int v, int tl, int tr, int l, int r){
	    propagate(v, tl, tr);
	    if(tl > r || l > tr)return 0;
	    if(l <= tl && r >= tr)return bor[v];
	    int mid = (tl + tr) / 2;
	    return kveri(v*2,tl,mid,l,r) + kveri(v*2+1,mid+1,tr,l,r);
	}
	
	// Query 
	template <class BinaryOp>
	void processPath(int x, int y, BinaryOp op) {
		for(;root[x] != root[y]; y = par[root[y]]) {
			if(depth[root[x]] > depth[root[y]])swap(x,y);
			op(pos[root[y]], pos[y]); 
		}
		if(depth[x] > depth[y])swap(x,y);
		op(pos[x] + VALS_IN_EDGES,pos[y]); 
	}
	void modifyPath(int x, int y, int val) { 
		processPath(x, y, [this,&val](int l, int r) { lazyupd(1,1,n,l,r,val); }); 
	}
	ll queryPath(int x, int y) { 
		ll ans = 0; processPath(x, y, [this,&ans](int l, int r) { ans += kveri(1,1,n,l,r); });
		return ans; 
	}
	void modifySubtree(int x, int v) { 
		lazyupd(pos[x]+VALS_IN_EDGES,pos[x]+sz[x]-1,v); 
	}
};
