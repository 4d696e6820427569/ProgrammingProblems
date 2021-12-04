/**
 * LC1032
 * Design an algorithm that accepts a stream of characters and checks if a
 * suffix of these characters is a astring of a given array of strings words.
 *
 * For example, if words = ["abc", "xyz"] and the stream added the 4 characters
 * (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the
 * suffix "xyz" of the characters "axyz" matches "xyz" from words.
 *
 * Implement the StreamChecker class:
 *
 * StreamChecker(String[] words) Initializes the object with the strings array
 * words.
 * boolean query(char letter) Accepts a new character from the stream and
 * returns true if any non-empty suffix from the stream forms a word that is in
 * words.
 */

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <deque>

using std::unordered_map;
using std::vector;
using std::deque;
using std::string;
using std::shared_ptr;
using std::make_shared;

class StreamChecker
{
    struct TrieNode
    {
        TrieNode() : children{}, is_word{false}
        {}

        unordered_map<char, shared_ptr<TrieNode>> children;
        bool is_word;
    };

    StreamChecker(vector<string>& words)
    {
        shared_ptr<TrieNode> node{nullptr};
        for (const auto& word : words) {
            node = trie;
            string reversed_word{word.rbegin(), word.rend()};
            for (const char& c : reversed_word) {
                if (node->children.count(c) == 0) {
                    node->children[c] = make_shared<TrieNode>();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
    }

    bool query(char letter)
    {
        stream.emplace_front(letter);

        shared_ptr<TrieNode> node{trie};
        
        for (const char& c : stream) {
           if (node->is_word) return true;
           if (node->children.count(c) == 0) return false;
           node = node->children[c];
        }
        return node->is_word;
    }
    

    shared_ptr<TrieNode> trie;
    deque<char> stream;
};
