/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    vector<int> list;
    int i;

    void flattenList(vector<NestedInteger> &nestedList, int i)
    {
        if (i == nestedList.size())
            return;
        if (nestedList[i].isInteger())
        {
            list.push_back(nestedList[i].getInteger());
        }
        else
        {
            flattenList(nestedList[i].getList(), 0);
        }
        flattenList(nestedList, i + 1);
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        i = 0;
        flattenList(nestedList, 0);
    }

    int next()
    {
        return list[i++];
    }

    bool hasNext()
    {
        if (i == list.size())
            return false;
        return true;
    }
};

class NestedIterator
{
    stack<NestedInteger *> nodes;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; i--)
        {
            nodes.push(&nestedList[i]);
        }
    }

    int next()
    {
        int result = nodes.top()->getInteger();
        nodes.pop();
        return result;
    }

    bool hasNext()
    {
        while (!nodes.empty())
        {
            NestedInteger *curr = nodes.top();
            // ensure the top most element is an integer not an integer list
            if (curr->isInteger())
            {
                return true;
            }

            nodes.pop();

            // decouple the integer list and add the decoupled element back to stack
            vector<NestedInteger> &adjs = curr->getList();
            for (int i = adjs.size() - 1; i >= 0; --i)
            {
                nodes.push(&adjs[i]);
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */