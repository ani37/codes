vector<ll> A(N), tree(N << 2);
 //1 base indexing
void build(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = A[start];
    }
    else {
        ll mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
 
void update(ll node, ll start, ll end, ll pos, ll val) {

  if (start == end) 
  {
    A[pos] += val;
    tree[node] += val;
  } 
  else
   {
    ll mid = (start + end) / 2;
    if (start <= pos and pos <= mid)
     {
      update(2*node, start, mid, pos, val);
    }
    else
     {
      update(2*node+1, mid+1, end, pos, val);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
  }
}
 
ll query(ll node, ll start, ll end,ll left,ll right) {
    if (end < left || start > right)  
        return 0;  
  if (left <= start and right>=end) {
    return tree[node];
  }
  ll mid = (start + end) / 2;
  ll p1 = 0, p2 = 0;
    p2 = query(2*node+1, mid+1, end,left,right);
    p1 = query(2*node, start, mid,left,right);
    return (p1 + p2);
}