class LRUCache
{
    public:

        struct Node
        {
            int key;
            int val;
            Node * prev;
            Node * next;
        };
    Node *head = new Node();
    Node *tail = new Node();
    unordered_map<int, Node*> mp;
    int cap = 0, sz = 0;
    Node* getnewnode(int key, int value)
    {
        Node *temp = new Node();
        temp->key = key;
        temp->val = value;
        return temp;
    }
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        else
        {
            Node *node = mp[key];
            if (node->prev != NULL)
                node->prev->next = node->next;
            if (node->next != NULL)
                node->next->prev = node->prev;
            Node *temp = getnewnode(key, node->val);
            mp[key] = temp;
            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
            return temp->val;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())	//if key is already present
        {
            Node *node = mp[key];
            if (node->next == tail)
            {
                tail->prev = node->prev;
            }
            if (node->prev != NULL)
                node->prev->next = node->next;
            if (node->next != NULL)
                node->next->prev = node->prev;
        }
        else
        {
            if (head->next == NULL)
            {
                sz++;
                Node *temp = getnewnode(key, value);
                mp[key] = temp;
                head->next = temp;
                temp->next = tail;
                tail->prev = temp;
                temp->prev = head;
                return;
            }
            else
            {
                if (sz == cap)
                {
                    Node *node = tail->prev;
                    node->prev->next = tail;
                    tail->prev = node->prev;
                    auto it = mp.find(node->key);
                    mp.erase(it);
                }
                else {}
            }
            if (sz < cap)
                sz++;
        }
        Node *temp = getnewnode(key, value);
        mp[key] = temp;
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
       	// Node *head2 = head;
       	// while (head2 != NULL)
       	// {
       	//     cout << head2->val << " ";
       	//     head2 = head2->next;
       	// }
       	// cout << endl;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */