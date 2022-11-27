void man(string &s)
{
    int n = (int)s.size();
    vector<int> d1(n);
    for(int i=0 , l=0 , r=-1; i<n; i++) //Find odd palindrome
    {
        int k = (i>r) ? 1 : min(d1[r-i+l] , r-i+1);

        while(0 <= i-k && i+k < n && s[i-k]==s[i+k])
            k++;

        d1[i] = k--;
        if (i+k > r)
        {
            l = i-k;
            r = i+k;
        }
    }
    vector<int> d2(n);
    for(int i=0 , l=0 , r=-1; i<n; i++) //Find even palindrome
    {
        int k = (i>r) ? 0 : min(d2[r-i+l+1] , r-i+1);

        while(0 <= i-k-1 && i+k < n && s[i-k-1]==s[i+k])
            k++;

        d2[i] = k--;
        if (i+k > r)
        {
            l = i-k-1;
            r = i+k;
        }
    }
}
