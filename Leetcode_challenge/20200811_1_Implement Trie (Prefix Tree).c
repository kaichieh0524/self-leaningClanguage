// Implement Trie (Prefix Tree) (medium)
// Runtime: 64 ms, faster than 77.72% of C online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 38.2 MB, less than 65.22% of C online submissions for Implement Trie (Prefix Tree).


typedef struct node {
    bool isend;
    struct node* children[26];
} node;

typedef struct {
    node* root;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* trie = calloc(1,sizeof(Trie));
    trie -> root = calloc(1,sizeof(node));
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    node* temp = obj -> root;
    int index = 0;
    while (word[index] != '\0'){
        int index1 = word[index]-'a';
        if (temp -> children[index1]==NULL){
            temp -> children[index1] = calloc(1,sizeof(node));
        }
        temp = temp -> children[index1];
        index++;
    }
    temp -> isend = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    node* temp = obj -> root;
    int index = 0;
    while (word[index] != '\0'){
        int index1 = word[index]-'a';
        if (temp -> children[index1]==NULL){
            return 0;
        }
        temp = temp -> children[index1];
        index++;
    }
    return temp->isend;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    node* temp = obj -> root;
    int index = 0;
    while (prefix[index] != '\0'){
        int index1 = prefix[index]-'a';
        if (temp -> children[index1]==NULL){
            return 0;
        }
        temp = temp -> children[index1];
        index++;
    }
    return 1;
}



void nodefree(node* node){
    if(node == NULL){return;}
    for (int i = 0; i < 26; i++){
        nodefree(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    nodefree(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/