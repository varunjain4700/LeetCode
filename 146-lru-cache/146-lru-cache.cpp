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
    int cap = 0;
    map<int, Node*> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    Node* getnewnode(int key, int value)
    {
        Node *temp = new Node();
        temp->key = key;
        temp->val = value;
        return temp;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())	//if key doesn't exist
            return -1;
       	//if key exists ,return the value and also shift it to the front since it go used recently
        Node *add = mp[key];
        add->prev->next = add->next;
        add->next->prev = add->prev;
        add->next = head->next;
        head->next->prev = add;
        head->next = add;
        add->prev = head;
        return add->val;
    }

    void put(int key1, int value)
    {
        if (head->next == NULL)
        {
            head->next = tail;
            tail->prev = head;
        }
        if (mp.find(key1) == mp.end())	//key does not exists in cache
        {
            if (cap > 0)
            {
               	//insert new element at the beginning of the cache
                cap--;
            }
            else
            {
               	//remove the element from the back of ll as it will be the least recently used

               	//removing the end_node
                Node *temp = tail->prev;
                Node *new_end = tail->prev->prev;
                new_end->next = tail;
                tail->prev = new_end;
                auto it = mp.find(temp->key);
                mp.erase(it);
            }
           	//adding new node at the front
            Node *temp = getnewnode(key1, value);
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            mp[key1] = temp;
        }
        else	//key exists in cache,then change its value and move it to front 
        {
            Node *add = mp[key1];
            add->val = value;
            add->prev->next = add->next;
            add->next->prev = add->prev;
            add->next = head->next;
            head->next->prev = add;
            head->next = add;
            add->prev = head;
        }
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */