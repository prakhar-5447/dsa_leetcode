// https://leetcode.com/problems/word-search-ii/description/

#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    vector<TrieNode *> children;
    bool end;
    string word;

    TrieNode() : children(26, nullptr), end(false), word("") {}
};

class Solution
{
    TrieNode *root;
    vector<string> result;

    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

public:
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *ptr)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        if (board[i][j] == '#')
            return;

        if (ptr->children[board[i][j] - 'a'] == nullptr)
            return;

        if (ptr->children[board[i][j] - 'a']->end)
        {
            result.push_back(ptr->children[board[i][j] - 'a']->word);
            ptr->children[board[i][j] - 'a']->end = false;
        }

        char letter = board[i][j];
        board[i][j] = '#';
        for (const auto &dir : dirs)
        {
            dfs(board, i + dir[0], j + dir[1], ptr->children[letter - 'a']);
        }
        board[i][j] = letter;
    }

    void build_trie_tree(const vector<string> &words)
    {
        for (const auto &word : words)
        {
            TrieNode *cur = root;
            for (const char ch : word)
            {
                if (cur->children[ch - 'a'] == nullptr)
                    cur->children[ch - 'a'] = new TrieNode();

                cur = cur->children[ch - 'a'];
            }
            cur->end = true;
            cur->word = word;
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size(), n = board[0].size();

        root = new TrieNode();
        build_trie_tree(words);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<char>> arr = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    Solution s;
    vector<string> words = {"abce", "abc"};
    vector<string> ans = s.findWords(arr, words);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}