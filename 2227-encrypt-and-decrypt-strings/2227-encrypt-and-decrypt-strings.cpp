class Encrypter
{
    public:
        map<char, string> mp;
    vector<string> dict1;
    Encrypter(vector<char> &keys, vector<string> &values, vector< string > &dict)
    {
        dict1 = dict;
        for (int i = 0; i < keys.size(); i++)
            mp[keys[i]] = values[i];
    }

    string encrypt(string word1)
    {
        string ans;
        for (int i = 0; i < word1.size(); i++)
            ans += mp[word1[i]];
        return ans;
    }

    int decrypt(string word2)
    {
        int ans = 0;
        for (int i = 0; i < dict1.size(); i++)
        {
            string temp;
            for (int j = 0; j < dict1[i].size(); j++)
            {
                temp += mp[dict1[i][j]];
            }
            if (temp == word2)
                ans++;
        }
        return ans;
    }
};

/**
 *Your Encrypter object will be instantiated and called as such:
 *Encrypter* obj = new Encrypter(keys, values, dictionary);
 *string param_1 = obj->encrypt(word1);
 *int param_2 = obj->decrypt(word2);
 */