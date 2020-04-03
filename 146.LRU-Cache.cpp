//
// Created by hqnddw on 2019/10/24.
//
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache1 {
public:
    int size;
    list<int> lru;
    unordered_map<int, int> map_value;
    unordered_map<int, list<int>::iterator> map_iter;

    LRUCache1(int capacity) {
        this->size = capacity;
    }

    int get(int key) {
        if (!map_value.count(key)) return -1;
        update(key);
        return map_value[key];

    }

    void put(int key, int value) {
        if (map_value.size() == size && map_value.count(key) == 0) {
            evict();
        }
        update(key);
        map_value[key] = value;
    }

    void update(int key) {
        if (map_iter.count(key))
            lru.erase(map_iter[key]);
        lru.push_front(key);
        map_iter[key] = lru.begin();
    }

    void evict() {
        map_value.erase(lru.back());
        map_iter.erase(lru.back());
        lru.pop_back();
    }
};


class LRUCache {
public:
    int size;
    list<int> lru;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> map;

    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {
        if (kv.count(key)) {
            lru.erase(map[key]);
            lru.push_front(key);
            map[key] = lru.begin();
            return kv[key];
        } else return -1;
    }

    void put(int key, int value) {
        if (lru.size() == size && kv.count(key) == 0) {
            pop_lru();
            lru.push_front(key);
            kv[key] = value;
            map[key] = lru.begin();
        } else if (kv.count(key)) {
            lru.erase(map[key]);
            lru.push_front(key);
            kv[key] = value;
            map[key] = lru.begin();
        } else {
            lru.push_front(key);
            kv[key] = value;
            map[key] = lru.begin();
        }

    }

    void pop_lru() {
        map.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};
