Nije zavrseno mrzelo me je

/*

If you want to 

Then if you want to make path look like a segment, you have two cases:

if p = LCA(u, v) ( (u,v) is path you are currently working with) and in[u] <= in[v]
1. p == u -> sum[in[u] ... in[v]]
2. p != u -> sum[out[u] ... in[v]] + val[p]

In both cases you need to considered only nodes that appears 1 time



*/


int timer = 0;
int in[maxn];
int out[maxn];
void dfs(int v, int p) {
	in[v] = ++timer;
	for(auto u : g[v]) {
		if(u != p) {
			dfs(u, v);
		}
	}
	out[v] = ++timer;
}
