int n, m;
int t, cs = 1;
int ara[maxn];
vector < pair < int , int > > divs[maxn+5];

int perPrime[maxn + 7];

void sieve(int n)
{
	for(int i = 2; i <= n; i++){
	    if(divs[i].size()) continue;
	    for(int j = i; j <= n; j += i) divs[j].push_back({i, 0});
	}

	for(int i = 2; i <= n; i++){
	    for(int j = 0; j < divs[i].size(); j++){
	        int cur = divs[i][j].first;
	        int cnt = 0, val = i;
	        while(val % cur == 0) val = val / cur, cnt++;
	        divs[i][j].second = cnt;
	    }
	}
}

int main()
{
	cin >> t;
	sieve(maxn);

	while(t--){
	    scanf("%d %d", &n, &m);
	    memset(perPrime, 0, sizeof(perPrime));
	    for(int i = 1; i <= n; i++){
	        scanf("%d", &ara[i]);
	        for(auto dv : divs[ara[i]]) perPrime[dv.first] = max(perPrime[dv.first], dv.second);
	    }

	    int mxmLCM = 0, mxmAns = 0;

	    for(int i = 1; i <= m; i++){

	        int barbe = 1;
	        for(auto dv : divs[i]){
	            int dif = max(0, dv.second - perPrime[dv.first]);
	            for(int i = 1; i <= dif; i++) barbe = barbe * dv.first;
	        }
	        if(barbe > mxmLCM){
	            mxmLCM = barbe;
	            mxmAns = i;
	        }
	    }
	    printf("%d\n", mxmAns);
	}

	return 0;
}