multiset < int > s;
multiset < int > :: iterator it;

...

FOR(i, 1, n)
{
    s.insert(a[i]);

    it = s.lower_bound(a[i]);

    it++;

    if(it != s.end())
        s.erase(it);
}

cout << s.size() << endl;