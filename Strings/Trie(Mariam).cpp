//DON’T FORGET RETURN IN FUNCTION and child[cur]->solve
struct trie 
{
    trie* child[26];
    bool is_leaf;
    int cnt;
  
    trie()
    {
        memset(child, 0, sizeof child);
        is_leaf = false;
        cnt = 0;
    }

    void insert(int idx)
    {
        if(idx == s.size())
            is_leaf = true;
        else
        {
            int cur = s[idx] - 'a';
            if(child[cur] == 0)
                child[cur] = new trie();
            child[cur]->cnt++;
            child[cur]->insert(idx + 1);
        }
    }

    bool word_exist(int idx)
    {
        if(idx == s.size())
            return is_leaf;
        int cur = s[idx] - 'a';
        if(child[cur] == 0)
            return false;
        return child[cur] -> word_exist(idx + 1);
    }


    bool prefix_exist(int idx)
    {
        if(idx == s.size())
            return true; //to count prefixes, return cntr
        int cur = s[idx] - 'a';
        if(child[cur] == 0)
            return 0;
        return child[cur] -> prefix_exist(idx + 1);
    }

    void remove(int idx, string s)
    {
       if(idx == s.size()) 
           return;
       else 
       {
           int cur = s[idx] - '0';
           child[cur]->cnt--; 
           child[cur]->remove(idx + 1, s);
           if(child[cur]->cnt == 0) 
               child[cur] = 0;
       }
    }

} root;
