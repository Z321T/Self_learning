#include <iostream>
using namespace std;

//折半查找
int binarySearch(int arr[], int size, int target) {
    //size为数组大小，target为目标元素
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // 找到目标元素，返回索引
        }
        else if (arr[mid] < target) {
            left = mid + 1; // 在右半部分继续查找
        }
        else {
            right = mid - 1; // 在左半部分继续查找
        }
    }

    return -1; // 未找到目标元素
}



//二叉排序树
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {};
};

//递归式查找
bool search(TreeNode* root, int target) {
    if (root == nullptr) {
        return false; // 未找到目标元素
    }

    if (root->value == target) {
        return true; // 找到目标元素
    }
    if (target < root->value) {
        return search(root->left, target); // 在左子树中查找
    }
    return search(root->right, target); // 在右子树中查找
}
//非递归式查找
bool searchNonRecursive(TreeNode* root, int target) {
    while (root != nullptr) {
        if (root->value == target) {
            return true; // 找到目标元素
        }
        if (target < root->value) {
            root = root->left; // 在左子树中查找
        }
        else {
            root = root->right; // 在右子树中查找
        }
    }
    return false; // 未找到目标元素
}

//二叉排序树的插入
bool insert(TreeNode* root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value); // 创建新节点
        return true;
    }

    if (value == root->value) {
        return false; // 不允许插入重复元素
    }
    if (value < root->value) {
        return insert(root->left, value); // 递归插入到左子树
    }
    else {
        return insert(root->right, value); // 递归插入到右子树
    }
}

//二叉排序树的构造
TreeNode* buildBinarySearchTree(int arr[], int size) {
    TreeNode* root = nullptr;
    for (int i = 0; i < size; ++i) {
        insert(root, arr[i]);
    }
    return root;
}

//二叉排序树的删除
bool deleteNode(TreeNode*& root, int target) {
    if (root == nullptr) {
        return false; // 未找到目标元素
    }

    if (target < root->value) {
        return deleteNode(root->left, target); // 在左子树中删除
    }
    else if (target > root->value) {
        return deleteNode(root->right, target); // 在右子树中删除
    }
    else {
        // 找到目标元素，进行删除
        if (root->left == nullptr) {
            TreeNode* temp = root;
            root = root->right; // 用右子树替代当前节点
            delete temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root;
            root = root->left; // 用左子树替代当前节点
            delete temp;
        }
        else {
            // 找到右子树的最小值，替代当前节点
            TreeNode* minNode = root->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            root->value = minNode->value; // 替换值
            deleteNode(root->right, minNode->value); // 删除最小值节点
        }
        return true;
    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}