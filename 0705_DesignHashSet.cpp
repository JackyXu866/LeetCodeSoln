class MyHashSet {
public:
    MyHashSet() {
    }
    
    void add(int key) {
        hs[key] = 1;
    }
    
    void remove(int key) {
        hs[key] = 0;
    }
    
    bool contains(int key) {
        return hs[key];
    }
private:
    bitset<1000001> hs;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
