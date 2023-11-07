#include "Trie.hpp"

Trie::Trie() {
    root = new node();
    root->isEndOfWord = false;
    root->count = 0;

}

Trie::~Trie() {
    delete root;
}

// implementation of insert function
void Trie::insert(std::string word) {
    node* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == nullptr) { 
            current->children[index] = new node();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}


// implementation of search function
bool Trie::search(std::string word) {
    node* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

// implementation of remove function
void Trie::remove(std::string word) {
    node* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
    }
    current->isEndOfWord = false;
}

//  analyzing Trie data structure
int Trie::nodeCount(node* node) {
    if (!node) return 0;

    int count = 1; // Count this node
    for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        count += nodeCount(node->children[i]);
    }
    return count;
}

void Trie::totalDepth(node* node, int currentDepth, int& totalDepthSum, int& wordCount) {
    if (!node) return;

    if (node->isEndOfWord) {
        totalDepthSum += currentDepth;
        wordCount++;
    }

    for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        if (node->children[i]) {
            totalDepth(node->children[i], currentDepth + 1, totalDepthSum, wordCount);
        }
    }
}

int Trie::averageDepth() {
    int totalDepthSum = 0;
    int wordCount = 0;
    totalDepth(root, 0, totalDepthSum, wordCount);
    return wordCount > 0 ? totalDepthSum / wordCount : 0;
}