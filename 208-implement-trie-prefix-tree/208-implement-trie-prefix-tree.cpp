class Trie
{
    private:
       	//a trie node will have at max 26 reference trie nodes (basically equal to the no.of distinct alphabets),flag is used to indicate that word is inserted in the trie and may also be used to check whether trie contains a particular word or not.
       	//all operations like insertion,seaching,finding a prefix takes time equal to length of the word-->O(len).
        struct Node
        {
            Node *links[26];
            bool flag = false;
        };
    Node * root;
    public:
        /**Initialize your data structure here. */
        Trie()
        {
            root = new Node();
        }

    /**Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (node->links[ch - 'a'] == NULL)
            {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    /**Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (node->links[ch - 'a'] == NULL)
                return false;
            node = node->links[ch - 'a'];
        }
        if (node->flag)
            return true;
        return false;
    }

    /**Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->links[prefix[i] - 'a'] == NULL)
                return false;
            node = node->links[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */