std::vector<ll> vp;
void SieveOfEratosthenes() 
{ 
    vector<bool>prime(100000001,1);
  
    for (ll p=2; p*p<=100000001; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*p; i<=100000001; i += p) 
                prime[i] = false; 
        } 
    } 
    for (ll p=2; p<=100000001; p++) 
       if (prime[p]) 
          vp.pb(p); 
} 