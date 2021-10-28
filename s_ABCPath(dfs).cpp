
   // https://www.geeksforgeeks.org/find-length-of-the-longest-consecutive-path-in-a-character-matrix/
#include<bits/stdc++.h> 
#define fr(i,a,n) for(int i=a;i<n;i++)

using namespace std; 

// tool matrices to recur for adjacent cells. 
int x[] = {0, 1, 1, -1, 1, 0, -1, -1}; 
int y[] = {1, 0, 1, 1, -1, -1, 0, -1}; 

// dp[i][j] Stores length of longest consecutive path 
// starting at arr[i][j]. 
int dp[51][51]; 
char mat[51][51];
// check whether mat[i][j] is a valid cell or not. 
bool isvalid(int m,int n,int i, int j) 
{ 
  if (i < 0 || j < 0 || i >= n || j >= m) 
  return false; 
  return true; 
} 

// Check whether current character is adjacent to previous 
// character (character processed in parent call) or not. 
bool isadjacent(char prev, char curr) 
{ 
  return ((curr - prev) == 1); 
} 

// i, j are the indices of the current cell and prev is the 
// character processed in the parent call.. also mat[i][j] 
// is our current character. 
int getLenUtil(int m,int n,int i, int j, char prev) 
{ 
  // If this cell is not valid or current character is not 
  // adjacent to previous one (e.g. d is not adjacent to b ) 
  // or if this cell is already included in the path than return 0. 
  if (!isvalid(m,n,i, j) || !isadjacent(prev, mat[i][j])) 
    return 0; 

  // If this subproblem is already solved , return the answer 
  if (dp[i][j] != -1) 
    return dp[i][j]; 

  int ans = 0; // Initialize answer 

  // recur for paths with differnt adjacent cells and store 
  // the length of longest path. 
  for (int k=0; k<8; k++) 
  ans = max(ans, 1 + getLenUtil(m,n, i + x[k], 
                j + y[k], mat[i][j])); 

  // save the answer and return 
  return dp[i][j] = ans; 
} 

// Returns length of the longest path with all characters consecutive 
// to each other. This function first initializes dp array that 
// is used to store results of subproblems, then it calls 
// recursive DFS based function getLenUtil() to find max length path 


// Driver program 
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);   
        cin.tie(NULL);
   int T=1;
  //cin>>T;
  while(1)
  {
int n,m,ans=0; 
 cin>>n>>m;
  if(n==0 and m==0)
      break;
 for (int i = 0; i < n; ++i)
  {
    fr(j,0,m)
    {
      cin>>mat[i][j];
    }
  }

  memset(dp, -1, sizeof dp); 

  for (int i=0; i<n; i++) 
  { 
    for (int j=0; j<m; j++) 
    { 
      // check for each possible starting point 
      if (mat[i][j] =='A') { 

        // recur for all eight adjacent cells 
        for (int k=0; k<8; k++) 
        ans = max(ans, 1 + getLenUtil(m,n, 
                  i + x[k], j + y[k], 'A')); 
      } 
    } 
  }
  cout<<"Case "<<T<<": "<<ans<<"\n";
  T++;
}
  return 0; 
} 

