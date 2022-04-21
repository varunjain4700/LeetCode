class MyHashSet
{
    public:
        vector<bool> arr;
    MyHashSet()
    {
        arr.resize(1e6 + 1, 0);
    }

    void add(int key)
    {
        arr[key] = 1;
    }

    void remove(int key)
    {
        arr[key] = 0;
    }

    bool contains(int key)
    {
        if (arr[key])
            return true;
        return false;
    }
};

/**
 *Your MyHashSet object will be instantiated and called as such:
 *MyHashSet* obj = new MyHashSet();
 *obj->add(key);
 *obj->remove(key);
 *bool param_3 = obj->contains(key);
 */