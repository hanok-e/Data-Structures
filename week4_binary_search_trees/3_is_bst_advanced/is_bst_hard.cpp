#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::pair;

struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* build_tree(const vector<Node>& tree) {
    vector<int> key(tree.size()); vector<int> left(tree.size()); vector<int> right(tree.size());
    if (key.size() == 0) {
        return nullptr;
    }
    for (int i = 0; i < tree.size(); i++) {
        key[i] = tree[i].key;
        left[i] = tree[i].left;
        right[i] = tree[i].right;
    }
    TreeNode* root = new TreeNode(key[0]);
    queue<TreeNode*> q;
    q.push(root);
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < key.size(); i++) {
        mp[key[i]].push_back({left[i], right[i]});
    }
    unordered_set<int> us;
    for (int i : key) {
        us.insert(i);
    }
    for (int i : us) {
        std::reverse(mp[i].begin(), mp[i].end());
    }

    while (!q.empty()) {
        TreeNode* parent = q.front();
        q.pop();
        if(mp[parent->val].back().first == -1) {
            parent->left = nullptr;
        } else {
            TreeNode* left = new TreeNode(key[mp[parent->val].back().first]);
            parent->left = left;
            q.push(left);
        }
        if (mp[parent->val].back().second == -1) {
            parent->right = nullptr;
        } else {
            TreeNode* right = new TreeNode(key[mp[parent->val].back().second]);
            parent->right = right;
            q.push(right);
        }
        mp[parent->val].pop_back();
    }
    return root;
}

bool IsBinarySearchTreeHelper(TreeNode* curr_node, long long low, long long high) {
    if (curr_node == nullptr) {
        return true;
    }
    if (curr_node->val < low || curr_node->val >= high) {
        return false;
    }
    bool isLeftBalanced = IsBinarySearchTreeHelper(curr_node->left, low, curr_node->val);
    bool isRightBalanced = IsBinarySearchTreeHelper(curr_node->right, curr_node->val, high);
    return isRightBalanced && isLeftBalanced;
}


bool IsBinarySearchTree(const vector<Node>& tree) {
    // Implement correct algorithm here
    TreeNode* root = build_tree(tree);
    return IsBinarySearchTreeHelper(root, LONG_MIN, LONG_MAX);
}



int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
