#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::queue;
using std::pair;
using std::unordered_map;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }

    TreeNode* build_tree() {
        if (key.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(key[0]);
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < key.size(); i++) {
            mp[key[i]] = {left[i], right[i]};
        }
        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();
            if(mp[parent->val].first == -1) {
                parent->left = nullptr;
            } else {
                TreeNode* left = new TreeNode(key[mp[parent->val].first]);
                parent->left = left;
                q.push(left);
            }
            if (mp[parent->val].second == -1) {
                parent->right = nullptr;
            } else {
                TreeNode* right = new TreeNode(key[mp[parent->val].second]);
                parent->right = right;
                q.push(right);
            }
        }
        return root;
    }

    void in_order_helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        in_order_helper(root->left, result);
        result.push_back(root->val);
        in_order_helper(root->right, result);
    }

    void pre_order_helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        pre_order_helper(root->left, result);
        pre_order_helper(root->right, result);
    }

    void post_order_helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        post_order_helper(root->left, result);
        post_order_helper(root->right, result);
        result.push_back(root->val);
    }

    vector <int> in_order() {
        vector<int> result;
        // Finish the implementation
        // You may need to add a new recursive method to do that

        TreeNode* root = build_tree();
        in_order_helper(root, result);
        return result;
    }

    vector <int> pre_order() {
        vector<int> result;
        // Finish the implementation
        // You may need to add a new recursive method to do that


        TreeNode* root = build_tree();
        pre_order_helper(root, result);
        return result;
    }

    vector <int> post_order() {
        vector<int> result;
        // Finish the implementation
        // You may need to add a new recursive method to do that

        TreeNode* root = build_tree();
        post_order_helper(root, result);
        return result;
    }
};

void print(vector <int> a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
}

int main_with_large_stack_space() {
    ios_base::sync_with_stdio(0);
    TreeOrders t;
    t.read();
    print(t.in_order());
    print(t.pre_order());
    print(t.post_order());
    return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

    return main_with_large_stack_space();
}

