// Implementation Problem

class MovieRentingSystem
{
    set<pair<int, pair<int, int>>> _report;          // price, shop, movie
    unordered_map<int, set<pair<int, int>>> _search; // movie -> price, shop
    map<pair<int, int>, int> getPrice;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            // unrented copies initially
            _search[movie].insert({price, shop});
            // get price map
            getPrice.insert({{shop, movie}, price});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;
        for (auto &[price, shop] : _search[movie])
        {
            res.push_back(shop);
            if (res.size() == 5)
                break;
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        // remove from search
        int price = getPrice.find({shop, movie})->second;
        _search[movie].erase({price, shop});

        // put in report
        _report.insert({price, {shop, movie}});
    }

    void drop(int shop, int movie)
    {
        int price = getPrice.find({shop, movie})->second;
        // remove from report
        _report.erase({price, {shop, movie}});
        // put in search
        _search[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;

        for (auto &[price, shopMovie] : _report)
        {
            res.push_back({shopMovie.first, shopMovie.second});
            if (res.size() == 5)
                break;
        }

        return res;
    }
};