//Implimentation
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* Left;
    Node* Right;

    Node(int data){
        this->data = data;
        Left = NULL;
        Right = NULL;
    }

    Node* createTree(){
        int data;
        cout<<"Enter the data for the node "<<endl;
        cin>>data;

        if(data == -1){
            return NULL;
        }

        Node* root = new Node(data);

        cout<<"Enter the data for the left node of "<<data<<endl;
        root->Left = createTree();
        cout<<"Enter the data for the right node of "<<data<<endl;
        root->Right = createTree();

        return root;

    }

    //Traversal of the tree
    void postOrder(Node* root){
        if(root == NULL){
            return;
        }

        //root
        cout<<root->data<<" ";

        //left
        postOrder(root->Left);

        //right
        postOrder(root->Right);
    }

    void preOrder(Node* root){
        if(root == NULL){
            return;
        }

        //root
        cout<<root->data<<" ";

        //left
        preOrder(root->Left);

        //right
        preOrder(root->Right);
    }

    void inOrder(Node* root){
        if(root == NULL){
            return;
        }

        //left
        inOrder(root->Left);

        //root
        cout<<root->data<<" ";

        //right
        inOrder(root->Right);
    }

    void levelOrder(Node* root){
        queue<Node*>q;

        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            cout<<temp->data;
            q.pop();

            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }

    //Levelorder by newLine each level
    void levelOrderNewline(Node* root){
        queue<Node*>q;

        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp = q.front();

            if(temp == NULL){
                cout<<endl;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
            cout<<temp->data;
            q.pop();

            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    }

};

int main(){
    //created a dummy object to call the function as it is not static
    Node* temp = new Node(0);
    Node* root = temp->createTree();
    cout<<"The tree is created successfully "<<root->data<<endl;
    temp->inOrder();
    cout<<endl;
    temp->preOrder();
    cout<<endl;
    temp->postOrder();
    cout<<endl;
    temp->levelOrder();
    cout<<endl;

    return 0;
}

//Creation of generic tree 
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> child;

    Node(int data) {
        this->data = data;
    }

    Node* createTree() {
        int data;
        cout << "Enter node data (-1 for NULL): ";
        cin >> data;

        if (data == -1)
            return NULL;

        Node* root = new Node(data);

        int n;
        cout << "Enter number of children of " << data << ": ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter child " << i + 1 << " of " << data << endl;
            Node* newChild = createTree();
            root->child.push_back(newChild);
        }

        return root;
    }
};

int main() {
    Node temp(0);                 // Dummy object
    Node* root = temp.createTree();

    cout << "\nTree created successfully." << endl;
    cout << "Root node = " << root->data << endl;

    return 0;
}


//Heigh of a tree leetcode 104
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int height = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();

            if(temp == NULL){
                height++;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                if(temp->left != NULL){
                q.push(temp->left);
                }

                if(temp->right != NULL){
                q.push(temp->right);
                }
                q.pop();
            }
        }
        return height;
    }
};

//Balanced Binary Tree Leetcode 110
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int height = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();

            if(temp == NULL){
                height++;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                if(temp->left != NULL){
                q.push(temp->left);
                }

                if(temp->right != NULL){
                q.push(temp->right);
                }
                q.pop();
            }
        }
        return height;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool leftisbalanced = isBalanced(root->left);
        bool rightisbalanced = isBalanced(root->right);

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int absdiff = abs(leftheight-rightheight);
        bool isbalanced = (absdiff<=1);

        if(isbalanced && leftisbalanced && rightisbalanced){
            return true;
        }
        else{
            return false;
        }
    }
};

//Lowest Common Ansector
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val){
            return p;
        }
        if(root->val == q->val){
            return q;
        }

        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);

        if(leftans == NULL && rightans == NULL){
            return NULL;
        }
        if(leftans == NULL && rightans !=NULL){
            return rightans;
        }
        if(leftans != NULL && rightans == NULL){
            return leftans;
        }
        else{
            return root;
        }
    }
};

//path sum 2 store all the paths in a array

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int targetsum,int sum,vector<int>path,vector<vector<int>>& ans){
        if(root == NULL){
            return ;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetsum){
                ans.push_back(path);
            }
            else{
                return ;
            }  
        }

        bool leftans = solve(root->left,targetsum,sum,path,ans);
        bool rightans = solve(root->right,targetsum,sum,path,ans);  
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>path;
        vector<vector<int>>ans;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};

//kth ansestor of a binary tree
/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool solve(Node* root, int& k ,int node,int& ans){
        if(root==NULL){
            return false;
        }
        if(root->data == node){
            return true;
        }

        
        bool leftans = solve(root->left,k,node,ans);
        bool rightans = solve(root->right,k,node,ans);
        
        if(leftans || rightans){
            k--;
            if(k==0){
                ans = root->data;
            }
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int kthAncestor(Node *root, int k, int node) {
        int ans = -1;
        solve(root,k,node,ans);
        return ans;
    }
};
