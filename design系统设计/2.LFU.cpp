//
// Created by hqnddw on 2020/9/5.
//
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    unordered_map<int, pair<int, int>> key_value;
    unordered_map<int, list<int> > fre_key;
    unordered_map<int, list<int>::iterator> key_iter;
    int minFreq;
    int size;
    int cap;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (!key_value.count(key)) return -1;
        fre_key[key_value[key].second].erase(key_iter[key]);
        key_value[key].second++;
        fre_key[key_value[key].second].push_back(key);
        key_iter[key] = --fre_key[key_value[key].second].end();
        if (fre_key[minFreq].size() == 0)
            minFreq++;
        return key_value[key].first;
    }

    void put(int key, int value) {
        if(cap<=0) return;
        int v = get(key);
        if (v != -1){
            key_value[key].first = value;
            return;
        }
        if (size == cap){
            key_value.erase(fre_key[minFreq].front());
            key_iter.erase(fre_key[minFreq].front());
            fre_key[minFreq].pop_front();
            size--;
        }
        key_value[key] = {value,1};
        fre_key[1].push_back(key);
        key_iter[key] = --fre_key[1].end();
        minFreq = 1;
        size++;
    }
};