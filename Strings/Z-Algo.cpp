// Return an array, eh akbar length h5do mn index i yukon prefix mn el string, 
// to make sure that the length is to the last of the string i + z[i] == s.size(), 
// 3shan a search 3la pattern f string, new string = pattern + char msh mwgod flstring + text

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
