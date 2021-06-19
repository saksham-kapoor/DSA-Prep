class LRUCache
{
    int size;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value

public:
    LRUCache(int capacity) : size(capacity) {}
    int get(int key)
    {
        if (kv.find(key) == kv.end())
            return -1;
        updateLRU(key);
        return kv[key];
    }
    void put(int key, int value)
    {
        if (kv.size() == size && kv.find(key) == kv.end())
            evict();
        updateLRU(key);
        kv[key] = value;
    }
    void updateLRU(int key)
    {
        if (kv.find(key) != kv.end())
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    void evict()
    {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};
