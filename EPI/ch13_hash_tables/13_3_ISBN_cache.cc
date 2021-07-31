/**
 * EPI Chapter 13 Hash tables
 *
 * The International Standard Book Number (ISBN) is a unique commercial book
 * identifier. It is a string of length 10. The first 9 characters are digits;
 * the last character is a check character. The check character is the sum of
 * the first 9 digits, modulo 11, with 10 represented by 'X'. (Modern ISBNs use
 * 13 digits, and the check digit is taken modulo 10; this problem is concerned
 * with 10-digit ISBNs)
 *
 * Create a cache for looking up prices of books identified by their ISBN. You
 * implement lookup, insert, and remove methods. Use the Least Recently Used
 * (LRU) policy for cache eviction. If an ISBN is already present, insert
 * should not change the price, but it should update that entry to be the most
 * recently used entry. Lookup should also update that entry to be the most
 * recently used entry.
 *
 * Hint: Amortize the cost of deletion. Alternatively, use an auxiliary data
 * structure.
 */

#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <cassert>
#include <algorithm>
#include <utility>

using std::vector;
using std::list;
using std::string;
using std::unordered_map;
using std::make_pair;
using std::pair;

template<size_t capacity>
class LRUCache
{
public:
    bool Lookup(int isbn, int& price)
    {
        auto it = isbn_price_table_.find(isbn);
        if (it == isbn_price_table_.end()) {
            return false;
        }

        price = it->second.second;
        
        // Since key has just been accessed, move it to the front.
        MoveToFront(isbn, it);
        return true;
    }

    void Insert(int isbn, int price)
    {
        auto it = isbn_price_table_.find(isbn);

        // Add the value for key only if key is not present. Don't update the
        // existing values.
        if (it != isbn_price_table_.end()) {
            // We should make isbn the most recently used.
            MoveToFront(isbn, it);
        } else {
            if (isbn_price_table_.size() == capacity) {
                // Removes the least recently used isbn to get space.
                isbn_price_table_.erase(lru_queue_.back());
                lru_queue_.pop_back();
            }

            lru_queue_.emplace_front(isbn);
            isbn_price_table_[isbn] = {lru_queue_.begin(), price};
        }
    }

    bool Erase(int isbn)
    {
        auto it = isbn_price_table_.find(isbn);
        if (it == isbn_price_table_.end())
            return false;

        lru_queue_.erase(it->second.first);
        isbn_price_table_.erase(it);
        return true;
    }

private:
    // isbn and <iterator, isbn>
    using Table = unordered_map<int, pair<list<int>::iterator, int>>;

    // Forces this key-value pair to move to the front.
    void MoveToFront(int isbn, const Table::iterator& it)
    {
        lru_queue_.erase(it->second.first);
        lru_queue_.emplace_front(isbn);
        it->second.first = lru_queue_.begin();
    }

    Table isbn_price_table_;
    list<int> lru_queue_;

};

int main()
{
    return 0;
}
