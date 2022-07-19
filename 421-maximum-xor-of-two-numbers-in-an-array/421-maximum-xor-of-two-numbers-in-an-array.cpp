class Trie
{
    private:
        struct Node
        {
            Node *links[2];
        };
    Node * root;
    public:
        Trie()
        {
            root = new Node();
        }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (1 << i) &num;
            if (node->links[bit] == NULL)
                node->links[bit] = new Node();
            node = node->links[bit];
        }
    }
    int get_max(int num)
    {
        int ans = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (1 << i) &num;
            if (node->links[!bit] != NULL)	//we want the reversed bit to maximise the xor,so check for that bit first if it is available or not
            {
                ans += !bit *(1 << i);
                node = node->links[!bit];
            }
            else
            {
                ans += (bit) *(1 << i);
                node = node->links[bit];
            }
        }
        return ans;
    }
};

class Solution
{
    public:
        int findMaximumXOR(vector<int> &nums)
        {
            Trie *obj = new Trie();
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                obj->insert(nums[i]);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = obj->get_max(nums[i]);
                ans = max(ans, nums[i] ^ temp);
            }
            return ans;
        }
};