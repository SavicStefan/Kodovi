/*
If you want answer queries on subtrees using mo, just do normal in and out, 
but if you want queries on paths you need to increse out, too.

Then if you want to make path look like a segment, you have two cases:

if p = LCA(u, v) ( (u,v) is path you are currently working with) and in[u] <= in[v]

1. p == u -> [in[u], in[v]]
2. p != u -> [out[u], in[v]] + [in[p], in[p]]

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
