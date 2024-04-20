#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
    class node {
    public:
        int val;
        node* next;
        node* prev;
        int key;
        node(int _key, int _value) {
            key = _key;
            val = _value;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        // check the entry is present in the map or not ?
        if (mp.find(key_) != mp.end()) {
            node* existingnode = mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
        }
        // check the capacity of the MAP 
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        // Add the new node
        addnode(new node(key_, value));
        mp[key_] = head->next;
    }

    void display() {
        // Display the Cache Contents
        cout << "LRU Cache Contents:" << endl;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second->val << endl;
    }
    cout << endl;
}
};

int main() { // Driver code to verify LRU Cache
    LRUCache cacheObj(3);
    cacheObj.put(1, 10);
    cacheObj.put(2, 20);
    cacheObj.put(3, 30);
    cacheObj.display();
    cacheObj.get(3);
    cacheObj.put(4, 40);
    cacheObj.get(4);
    cacheObj.get(3);
    cacheObj.display();
    cacheObj.put(5, 50);
    cacheObj.display();
    cacheObj.get(1);
    cacheObj.put(6, 60);
    cacheObj.display();
    return 0;
}