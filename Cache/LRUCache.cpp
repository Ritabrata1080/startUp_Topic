/*
    Created by Ritabrata, 14/12/2024
*
*/

#include <iostream>
#include <unordered_map>
#include <list>

// Define a template for LRUCache
template <typename Key, typename Value>
class LRUCache {
private:
    size_t capacity; // Maximum capacity of the cache
    std::list<std::pair<Key, Value>> cacheList; // Doubly linked list to store keys and values
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap; // Map for fast lookups

public:
    LRUCache(size_t capacity) : capacity(capacity) {}

    // Function to get a value from the cache
    Value get(const Key& key) {
        // Check if the key is in the cache
        if (cacheMap.find(key) == cacheMap.end()) {
            throw std::runtime_error("Key not found in cache");
        }

        // Move the accessed item to the front of the list (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    // Function to put a key-value pair into the cache
    void put(const Key& key, const Value& value) {
        // Check if the key is already in the cache
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update the value and move the item to the front of the list
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
            return;
        }

        // If the cache is full, remove the least recently used item
        if (cacheList.size() >= capacity) {
            auto last = cacheList.back();
            cacheMap.erase(last.first); // Remove from map
            cacheList.pop_back(); // Remove from list
        }

        // Insert the new key-value pair at the front of the list
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    // Function to display the contents of the cache
    void display() const {
        for (const auto& pair : cacheList) {
            std::cout << "[" << pair.first << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache<int, std::string> cache(3); // Create an LRU cache with a capacity of 3

    // Add items to the cache
    cache.put(1, "One");
    cache.put(2, "Two");
    cache.put(3, "Three");

    std::cout << "Cache after initial insertions: ";
    cache.display();

    // Access some items
    try {
        std::cout << "Accessing key 2: " << cache.get(2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Cache after accessing key 2: ";
    cache.display();

    // Add another item, causing an eviction
    cache.put(4, "Four");
    std::cout << "Cache after adding key 4: ";
    cache.display();

    // Try to access an evicted key
    try {
        std::cout << "Accessing key 1: " << cache.get(1) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
