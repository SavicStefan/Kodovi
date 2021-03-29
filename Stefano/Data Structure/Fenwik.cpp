ll dud[maxn];
void upd(int v, ll val){
	while(x <= maxn){
		dud[x] += val;
		x += x&(-x);
	}
}
ll query(int x){
	ll sum = 0;
	while(x > 0){
		sum += dud[x];
		x -= x&(-x);
	}
	return sum;
}
