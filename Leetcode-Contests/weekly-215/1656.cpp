class OrderedStream
{
    vector<string> v;
    int reach;

public:
    OrderedStream(int n)
    {
        v.resize(n, ".");
        reach = -1;
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> res;
        v[idKey - 1] = value;

        if (idKey - 1 == reach + 1)
        {
            int i = idKey - 1;
            while (i < v.size() && v[i] != ".")
            {
                res.push_back(v[i]);
                ++i;
                reach++;
            }
        }

        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */