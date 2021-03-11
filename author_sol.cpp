#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int val;
		Node *left, *right;
		int pos;
		Node (int v, int pos) {
			val = v;
			left = NULL;
			right = NULL;
			this->pos = pos;
		}
};

Node *insert(Node *root, int n, int pos) {
	if (root == NULL) {
		cout << pos << '\n';
		root = new Node(n, pos);
		return root;
	}
	if (n <= root->val) {
		root->left = insert(root->left, n, 2 * pos);
	} else {
		root->right = insert(root->right, n, 2 * pos + 1);
	}
	return root;
}

Node *deleteOperation(Node *root, int n, bool check) {
	if (root == NULL) {
		return root;
	} else if (n < root->val) {
		root->left = deleteOperation(root->left, n, check);
		return root;
	} else if (n == root->val) {
		if (check) {
			cout << root->pos << '\n';
		}
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->left && root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL && root->right) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		Node *replace = root->right;
		while (replace->left != NULL) {
			replace = replace->left;
		}
		root->val = replace->val;
		root->right = deleteOperation(root->right, replace->val, false);
		return root;
	} else {
		root->right = deleteOperation(root->right, n, check);
		return root;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Node *root = NULL;
	int tt;
	cin >> tt;
	while (tt--) {
		char ch;
		int n;
		cin >> ch >> n;
		if (ch == 'i') {
			root = insert(root, n, 1);
		} else {
			root = deleteOperation(root, n, true);
		}
	}
	return 0;
}
