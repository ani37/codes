
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
const ll N   =  500005;
const ll mod = 1e9 + 7;

using namespace std;

typedef struct TrieNode
{
	int leaf=0;
	struct TrieNode* child[26]={NULL};
}trie;

void add(string s, trie* t)
{
	trie* temp=t;
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";
		if(!temp->child[s[i]-'a'])
			temp->child[s[i]-'a']=new trie;
		temp=temp->child[s[i]-'a'];
	}
	temp->leaf++;
	cout<<"\tdone\n";
}

bool search(string s, trie* t)
{
	trie* temp=t;
	for(char x:s)
	{
		//cout<<x<<" ";
		if(temp->child[x-'a'])
			temp=temp->child[x-'a'];
		else
			return false;
	}
	return true;
}

int main()
{
	trie *head=new trie;
	add("amazing",head);

	cout<<search("amazi",head);
}