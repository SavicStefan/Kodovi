ll dud[maxn];
void upd(int v, ll val) {
	while(x <= maxn) {
		dud[x] += val;
		x += x&(-x);
	}
}
ll query(int x) {
	ll sum = 0;
	while(x > 0) {
		sum += dud[x];
		x -= x&(-x);
	}
	return sum;
}

// lower bound fenwik
int lwb(int x) {
	int sum = 0, ans = 0;
	fb(i,20,0) {
		if(ans + (1 << i) <= N && sum + dud[ans + (1 << i)] <= x) {
			sum += dud[ans + (1 << i)];
			ans += (1 << i);
		}
	}
	return ans;
}
