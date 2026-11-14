class Codec {
public:
    string preorder(TreeNode* root, string s) {
        if (root == NULL) {
            s += "-1#";
            return s;
        }
        s += to_string(root->val) + '#';
        s = preorder(root->left, s);
        s = preorder(root->right, s);
        return s;
    }

    string serialize(TreeNode* root) {
        string s = "";
        return preorder(root, s);
    }

    TreeNode* Build(int& idx, vector<int>& arr, int n) {
        if (idx >= n) {
            return NULL;
        }
        if (arr[idx] == -1) {
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(arr[idx++]);

        root->left = Build(idx, arr, n);
        root->right = Build(idx, arr, n);
        return root;
    }

    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        int n = data.size(); 
        string x = "";
        vector<int> arr; 
        for (char ch : data) {
            if (ch == '#') {
                arr.push_back(stoi(x));
                x = "";
            } else {
                x += ch;
            }
        }

        int idx = 0;
        return Build(idx, arr, arr.size());
    }
};