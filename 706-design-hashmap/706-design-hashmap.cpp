class MyHashMap
{
    public:
        vector<list<pair<int, int>>> mp;
    int size;
    MyHashMap()
    {
        size = 100;
        mp.resize(size);
    }
    int hash(int key)
    {
        return key % size;
    }

    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = mp[i].begin();
        while (it != mp[i].end())
        {
            if (it->first == key)
                return it;
            it++;
        }
        return it;
    }

    bool contains(int key)
    {
        int i = hash(key);
        if (search(key) != mp[i].end())
            return true;
        return false;
    }

    void put(int key, int value)
    {
        int i = hash(key);
        if (contains(key))
        {
            search(key)->second = value;
            return;
        }
        mp[i].push_back({ key,
            value });
    }

    int get(int key)
    {
        if (!contains(key))
            return -1;
        return search(key)->second;
    }

    void remove(int key)
    {
        if (!contains(key))
            return;
        int i = hash(key);
        mp[i].erase(search(key));
    }
};

/**
 *Your MyHashMap object will be instantiated and called as such:
 *MyHashMap* obj = new MyHashMap();
 *obj->put(key,value);
 *int param_2 = obj->get(key);
 *obj->remove(key);
 */