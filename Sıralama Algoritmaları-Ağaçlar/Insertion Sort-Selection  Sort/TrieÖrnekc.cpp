#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Yeni bir Trie düðümü oluþturma
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Trie'ye kelime ekleme
void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
 
    curr->isEndOfWord = true;
}

// Trie'de bir kelimenin aranmasý
bool search(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!curr->children[index])
            return false; 
        curr = curr->children[index];
    }
    return (curr != NULL && curr->isEndOfWord);
}

int main() {
    struct TrieNode* root = createNode();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "openai");
    printf("%s\n", search(root, "hello") ? "Var" : "Yok");
    printf("%s\n", search(root, "world") ? "Var" : "Yok");
    printf("%s\n", search(root, "openai") ? "Var" : "Yok");

    return 0;
}