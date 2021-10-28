#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
std::vector<string> ans;
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
 
	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
	list<string> word;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
 
	pNode->isEndOfWord = false;
 
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
 
	return pNode;
}bool T=false;
void printAllWords(TrieNode* root)
{       
    // if current node is leaf
    if (root->isEndOfWord)
    {      T=true;
        for(string str : root->word)
            ans.push_back(str);
    }
 
    // recurse for all children of root node
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode* child = root->children[i];
        if(T)
        break;
        if (child)
            printAllWords(child);
    }
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;
 
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
 
		pCrawl = pCrawl->children[index];
	}
 
	// mark last node as leaf
	pCrawl->isEndOfWord = true;
	(pCrawl->word).push_back(key);
}
 
// Returns true if key presents in trie, else
// false
void search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;
 
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			break;
 
		pCrawl = pCrawl->children[index];
	}
	T=false;
		printAllWords(pCrawl);
 
}
 
// Driver
int main()
{
    int n,q,r;
cin>>n;
	// Input keys (use only 'a' through 'z'
	// and lower case)
	string s,keys[n]; 
for(int i=0;i<n;i++)
cin>>keys[i];
	struct TrieNode *root = getNode();
cin>>q;
	int a[q],b[q];
	string x[q],ans[q];
for (int i = 0; i < q; ++i)
{
	cin>>a[i]>>x[i];
	a[i]=b[i];
}
sort(b,b+n);
for (int i = 0; i < b[0]; i++)
insert(root, keys[i]);
search(root,x[0]);
q=q-1;
int	j=0;
while(q--){
for (int i = b[j];i < b[j+1]; i++)
    insert(root, keys[i]);
    search(root,x[i]);
j++;
}


	return 0;
}