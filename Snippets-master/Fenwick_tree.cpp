void build(ll n, vector<long long>&tree)
{
  for(ll i=1;i<=n;i++)
  {
    if(i+(i&(-i))<=n)
    {
      tree[i+(i&(-i))]+=tree[i];
    }
  }
}

void update(ll pos,long long val, ll n, vector<long long>&tree)
{
  tree[pos]+=val;
  while((pos+pos&(-pos))<=n)
  {   
    pos+=pos&(-pos);
    tree[pos]+=val;
  }
}

long long query(ll idx, vector<long long>&tree)
{
  ll ans=tree[idx];
  while(idx-idx&(-idx)>0)
  {
    idx-=idx&(-idx);
    ans+=tree[idx];
  }
  return ans;
}