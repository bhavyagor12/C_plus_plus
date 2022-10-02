#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *letters[26];
    bool endOfWord = false;

    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (letters[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        letters[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return letters[ch - 'a'];
    }
    // setting endOfWord to true at the end of the word
    void setEnd(bool val)
    {
        endOfWord = val;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return endOfWord;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd(true);
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    void deleteWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                cout << "word not present" << endl;
            }
            node = node->get(word[i]);
        }

        if (node->isEnd())
        {
            node->setEnd(false);
            cout << "word is deleted" << endl;
        }
        else
        {
            cout << "word not present" << endl;
        }
    }
};

int main()
{
    Trie trie;
    while (1)
    {
        cout << endl;
        cout << "Enter 1 for inserting, 2 for searching, 3 for deleting,  any other input for exiting " << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {

            cout << "Enter word to be inserted:" << endl;
            string insertWord;
            cin >> insertWord;
            trie.insert(insertWord);
            cout << "word inserted" << endl;
            continue;
        }
        else if (choice == 2)
        {

            cout << "Enter word to be search:" << endl;
            string wordToSearch;
            cin >> wordToSearch;
            if (trie.search(wordToSearch))
            {
                cout << "word is present" << endl;
            }
            else
            {
                cout << "word is absent" << endl;
            }
            continue;
        }

        else if (choice == 3)
        {

            string wordToDelete;
            cout << "Enter word to be deleted" << endl;
            cin >> wordToDelete;
            trie.deleteWord(wordToDelete);
            continue;
        }
        else
        {
            cout << "Thank you!!" << endl;
            break;
        }
    }
}
