// Trie.hpp
#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>

const int ALPHABET_LENGTH = 26;

struct node {
    node* children[ALPHABET_LENGTH];
    bool isEndOfWord;
    int count;
};

class Trie {
public:
    node* root;

    // Constructor and destructor for the Trie class
    Trie();
    ~Trie();

    // Member functions
    void insert(const std::string word);
    bool search(const std::string word);
    void remove(const std::string word);

    // Analysis functions
    int nodeCount(node* node);
    void totalDepth(node* node, int currentDepth, int& totalDepthSum, int& wordCount); 
    int averageDepth();
};

#endif // TRIE_HPP
