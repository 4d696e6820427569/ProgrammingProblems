#include <unordered_map>
#include <string>
#include <memory>

using std::string;
using std::unordered_map;
using std::shared_ptr;
using std::make_shared;

class WordDictionary
{
public:
    struct TrieNode
    {
        TrieNode() : children{}, word{false}
        {}

        unordered_map<char, shared_ptr<TrieNode>> children;
        bool word;
    };

    WordDictionary() : trie{make_shared<TrieNode>()}
    {}

    void addWord(string word) {
        shared_ptr<TrieNode> node = trie;

        for (const char& c : word) {
            if (node->children.count(c) == 0) {
                node->children[c] = make_shared<TrieNode>();
            }
            node = node->children.at(c);
        }
        node->word = true;
    }

    bool search(string word) {
        return searchInNode(word, trie);
    }

private:
    bool searchInNode(string word, shared_ptr<TrieNode> node) {
        for (size_t i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node->children.count(c) == 0) {
                // If the current character is '.'
                // Check all possible nodes at this level.
                if (c == '.') {
                    for (const auto& pair : node->children) {
                        shared_ptr<TrieNode> child = node->children.at(pair.first);
                        if (searchInNode(word.substr(i + 1), child))
                            return true;
                    }
                }

                return false;
            } else {
                node = node->children.at(c);
            }
        }

        return node->word;
    }

    shared_ptr<TrieNode> trie;
};
