#include "Trie.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

// Function to sanitize the word, ensuring only a-z lowercase letters.
std::string sanitizeWord(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (std::isalpha(c)) {
            result += std::tolower(c);
        }
    }
    return result;
}

void insertWordsFromFile(const std::string& filePath, Trie& trie) {
    std::ifstream file(filePath);
    std::string word;

    if (file.is_open()) {
        while (file >> word) {
            std::string sanitizedWord = sanitizeWord(word);
            if (!sanitizedWord.empty()) {
                trie.insert(sanitizedWord);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filePath << std::endl;
    }
}

int tester() {
    Trie trie;
    trie.insert("hello");
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    const std::string filePath = argv[1];
    Trie trie;

    insertWordsFromFile(filePath, trie);
    std::cout << "Number of nodes: " << trie.nodeCount(trie.root) << std::endl;
    std::cout << "Average depth: " << trie.averageDepth() << std::endl;

    return 0;
}
