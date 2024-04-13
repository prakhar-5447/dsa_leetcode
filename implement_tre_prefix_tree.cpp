// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    bool isWord;
    TrieNode *child[26];
    TrieNode()
    {
        isWord = false;
        for (auto &a : child)
            a = nullptr;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *p = root;
        for (auto &a : s)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string key)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }
        return p->isWord;
    }

    bool startsWith(string key)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }
        return true;
    }
};

int main()
{
    Trie s;
    s.insert("apple");
    s.insert("ball");
    cout << s.startsWith("a") << endl;
    cout << s.search("apple") << endl;
}