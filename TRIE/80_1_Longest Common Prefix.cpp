// Longest Common Prefix

// https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?leftPanelTab=0
//TC=o(n^2)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    //for traversing all characters of string
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            //not match
            if(arr[j].length()<i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}


//using trie

#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childcount;
    bool isTerminate;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childcount = 0;
        isTerminate = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word) {
        // base case in the recursion
        if (word.length() == 0) {
            root->isTerminate = true;
            return;
        }
        // Assumption, word will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) { // element is present in the trie
            child = root->children[index];
        } else { // When absent
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }
        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string& ans) {
        TrieNode* current = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (current->childcount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                current = current->children[index];
            } else {
                break;
            }
            if (current->isTerminate) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie('\0');

    // insert all strings into the trie
    for (int i = 0; i < n; i++) {
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}
