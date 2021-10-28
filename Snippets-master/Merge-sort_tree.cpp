vector<int>tree[4*N];
int a[N];

void build(int node, int l, int r)
{
	if(l==r)
	{
		tree[node].pb(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(node*2, l ,mid);
	build(node*2+1, mid+1, r);
	merge(tree[node*2].begin(),tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
}

int query(int node, int l, int r, int beg, int end, int val)
{
	if(r<beg || l>end || l>r) return 0;
	if(beg<=l && r<=end)
	{
		auto it =upper_bound(tree[node].begin(), tree[node].end(), val);
		return (tree[node].end()-it);
	}
	return query(node*2, l, (l+r)/2, beg, end, val)+query(node*2+1,(l+r)/2 +1,r, beg, end, val);
}