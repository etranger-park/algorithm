#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int ASCII_NUM=127 - 32;
int total_num = 0;
// trie node
struct TrieNode
{
    struct TrieNode *children[ASCII_NUM];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    uint32_t c;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;
    pNode->c = 0;
    for (int i = 0; i < ASCII_NUM; i++)
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
        int index = key[i] - ' ';//The first char can be the tree name;
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    (pCrawl->c)++;
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

void get_percentage(struct TrieNode *root,string prefix)
{
    struct TrieNode *pCrawl = root;
    for (char i =0; i<ASCII_NUM;i++)
    {
        if(!root->children[i]) continue;
        char c = i+32;
        string name = prefix +c;
        if(root->children[i]->isEndOfWord)
        {
            cout.setf(ios::fixed);
            cout.precision(4);
            cout<<name <<" "<< root->children[i]->c/(double)total_num * 100<<endl;
        }
        get_percentage(root->children[i],name);
    }
}
// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    char ch;
    struct TrieNode *root = getNode();
    string str ;
    while(getline(cin,str))
    {
        insert(root,str);
        total_num ++;
        str.clear();
    }
    // Construct trie
    get_percentage(root,"");
    return 0;
}
