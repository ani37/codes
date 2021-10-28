//https://www.codechef.com/ENFE2019/problems/CHWLD matrix expo by ashish gupta
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int SZ=3;
const int MOD=1e9+7;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

struct matrix
{
	int arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
int n, k, l, m;
int res[SZ], res2[SZ];

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int l, r;
		cin>>l>>r;
		for(int n=l;n<=r;n++)
		{
			if(n==0)
				cout<<1<<" ";
			if(n==1)
				cout<<5<<" ";
			if(n==2)
				cout<<10<<" ";
			if(n<=2)
				continue;
			matrix ans;
			ans.makeiden();
			res[0]=10, res[1]=5, res[2]=1;
			matrix mat;
			mat.arr[0][0]=2, mat.arr[0][1]=(-1+MOD)%MOD, mat.arr[0][2]=2;
			mat.arr[1][0]=1, mat.arr[1][1]=0, mat.arr[1][2]=0;
			mat.arr[2][0]=0, mat.arr[2][1]=0, mat.arr[2][2]=2;
			matrix expo=power(mat, n-2);
			ans = ans * expo;
			for(int i=0;i<SZ;i++)
			{
				res2[i]=0;
				for(int j=0;j<SZ;j++)
					res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
			}
			for(int i=0;i<SZ;i++)
				res[i]=res2[i];
			cout<<res[0]<<" ";
		}
		cout<<endl;
	}
	return 0;
}