// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

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

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *p = root;
        for (auto &a : word)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool searchUtil(TrieNode *ptr, string word)
    {
        if (word.length() == 0)
            return ptr->isWord;

        if (word[0] == '.')
        {
            for (auto c : ptr->child)
                if (c && searchUtil(c, word.substr(1)))
                    return true;
        }
        else if (ptr->child[word[0] - 'a'] != NULL)
            return searchUtil(ptr->child[word[0] - 'a'], word.substr(1));
        else
            return false;

        return false;
    }
};

int main()
{
    WordDictionary s;
    s.addWord("apple");
    s.addWord("ball");
    cout << s.search("apple") << endl;
}