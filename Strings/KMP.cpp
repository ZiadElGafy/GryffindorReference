vector<int> compute_pi(string &s)
{
   int n = s.size();
   vector<int> pi(n);
   pi[0] = 0;
   for (int i = 1; i < n; i++)
   {
       auto j = pi[i - 1];
       while (j && s[i] != s[j])
           j = pi[j - 1];
       j += (s[i] == s[j]);
       pi[i] = j;
   }
   return pi;
}

// Counting the number of occurrences of each prefix
{
   vector<int> ans(n + 1);
   for (int i = 0; i < n; i++)
       ans[pi[i]]++;
   for (int i = n - 1; i > 0; i--)
       ans[pi[i - 1]] += ans[i];
   for (int i = 0; i <= n; i++)
       ans[i]++;
}
