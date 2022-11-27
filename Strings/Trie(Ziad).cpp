struct Trie{
    struct Node{
        Node* edges[26];
        /// Extra Node Attributes
    } *root = new Node();
 
    void add(string& s){
        Node* cur = root;
 
        for(auto& i : s){
            int rank = i - 'a';
 
            if(cur -> edges[rank] == NULL)
                cur -> edges[rank] = new Node();
 
            cur = cur -> edges[rank];
 
            /// Extra Node Addition Operations
        }
    }
 
    void erase(string& s){
        Node* cur = root;
 
        for(auto& i : s){
            int rank = i - 'a';
 
            cur = cur -> edges[rank];
 
            /// Node Removal Operations
        }
    }
 
    int query(string& s){
        int ret = 0;
        Node* cur = root;
 
        for(auto& i : s){
            int rank = i - 'a';
 
            /// Query Operations
        }
 
        return ret;
    }
}tr;
