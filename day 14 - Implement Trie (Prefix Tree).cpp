class node{
public:
    int value;
    node *children[26];
    node(){
        value = 0;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};


class Trie {
private:
    node *root;
    int count;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
        count = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *p = root;
        int len = word.size();
        for (int i=0;i<len;i++){
            int idx = word[i] - 'a';
            if (! p->children[idx]){
                p->children[idx] = new node();
            }
            p = p->children[idx];
        }
        count++;
        p->value = count;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *p = root;
        int len = word.size();
        for (int i=0;i<len;i++){
            int idx = word[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        if (p->value!=0){
            return true;
        }else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *p = root;
        int len = prefix.size();
        for (int i=0;i<len;i++){
            int idx = prefix[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */