#include <iostream>
#include <map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
;

void insert(Node*& root, int val) {
    if (root == nullptr) {
        root = new Nodeval, nullptr, nullptr;
        return;
    }
    if (val < root->val) {
        insert(root->left, val);
     else {
        insert(root->right, val);
    }


void countChildren(Node* root, map<int, int>& counts) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr && root->right != nullptr) {
        counts[root->val] = 2;
     else if (root->left != nullptr || root->right != nullptr) {
        counts[root->val] = 1;
     else {
        counts[root->val] = 0;
    }
    countChildren(root->left, counts);
    countChildren(root->right, counts);


int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }

    map<int, int> counts;
    countChildren(root, counts);

    for (auto it = counts.begin(); it != counts.end(); it++) {
        cout << it->first << " - " << it->second << endl;
    }

    return 0;
