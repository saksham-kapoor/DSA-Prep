class Node
{
public:
    int key, val;
    Node *next, *prev;
    Node(int k, int v)
    {
        key = k, val = v;
        next = prev = nullptr;
    }
};

class LRUCache
{
    int capacity;
    unordered_map<int, Node *> key_address;
    Node *head, *tail;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        auto it = key_address.find(key);
        int res = -1;
        if (it != key_address.end())
        {
            // store value
            res = it->second->val;

            // push it just after head
            put_in_front(it->second);
        }
        return res;
    }

    void put(int key, int value)
    {
        auto it = key_address.find(key);
        if (it != key_address.end())
        {
            // key already in list
            it->second->val = value;

            // push it next to head
            put_in_front(it->second);
        }
        else
        {
            if (key_address.size() == capacity)
                delete_lru_cache();

            Node *node = new Node(key, value);

            // put in front of head
            node->next = head->next;
            node->prev = head;
            head->next = node;
            node->next->prev = node;

            key_address.insert({key, node});
        }
    }

    void put_in_front(Node *node)
    {
        // delete element
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // add it in front of head
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    void delete_lru_cache()
    {
        Node *temp = tail->prev;

        // delete from list
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        // delete from map
        key_address.erase(temp->key);
        delete (temp);
    }
};