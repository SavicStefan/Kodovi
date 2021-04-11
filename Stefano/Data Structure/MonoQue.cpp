deque<int> dq;
void add(int x) {
	while(!dq.empty() && dq.back() < x)dq.pop_back();
	dq.push_back(x);
}
void del(int x) {
	if(!dq.empty() && dq.front() == x)dq.pop_front();
}
int get() {
	if(dq.empty())return 0;
	return dq.front();
}
