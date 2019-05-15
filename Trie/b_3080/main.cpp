#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int ALPHABET=26;
int total_num = 0;
uint64_t facotrialBox[27];
const uint64_t MAX_VAL = 1000000007;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    uint64_t child;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;
    pNode->child = 0;
    for (int i = 0; i < ALPHABET; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl->child + 1;
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - ' ';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

uint64_t get_count(struct TrieNode *root)
{
    int c = 0;
    uint64_t result = 1;
    if(root->child == 0) return 1;
    for (int i =0; i<ALPHABET;i++)
    {
        if(!root->children[i]) continue;
        c++;
        result *= get_count(root->children[i]);
        result %= MAX_VAL;
    }
    if(root->isEndOfWord) c++;
    return (result * facotrialBox[c]) % MAX_VAL;
}
// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    char ch;
    struct TrieNode *root = getNode();
    string str ;
    int N;
    uint64_t result;
    scanf("%d",&N);
    getline(cin,str);
    str.clear();//erase \n
    for(int i=0;i<N;i++)
    {
        getline(cin,str);
        insert(root,str);
        total_num ++;
        str.clear();
    }
    //init factorial Box
    facotrialBox[0] = 1;
    for(int i=1;i<=ALPHABET;i++)
        facotrialBox[i] = (facotrialBox[i-1] * i) % MAX_VAL;

    // Construct trie
    result  = get_count(root);
    cout << result % MAX_VAL << endl;
    return 0;
}
