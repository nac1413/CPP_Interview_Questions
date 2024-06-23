#pragma once
#include<iostream>
#include<vector>
#include<deque>

class BST
{
public:
	int data;
	BST* left;
	BST* right;
	BST(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	~BST() {
		this->left = NULL;
		this->right = NULL;
	}

};


/*
************* CREATE BST *********************
*/
BST* createBST(BST* root, int data) {
	if(root == NULL)
		root = new BST(data);
	else if (data < root->data)
		root->left = createBST(root->left, data);
	else
		root->right = createBST(root->right, data);
	return root;
}


/*
************* IN ORDER TRAVERSAL *********************
*/

void inorder_traversal(BST* root) {
	if (root == NULL)
		return;
	inorder_traversal(root->left);
	std::cout << root->data << " ";
	inorder_traversal(root->right);
}


/*
************* DELETE NODE FROM BST *********************
*/
BST* delete_BST(BST* root, int num) {
	//base case
	if (root == NULL)
		return NULL;

	//if we find the data to be deleted then
	if (root->data == num) {
		// for leaf node
		if (root->left == NULL && root->right == NULL) {
			BST* tmp = root;
			delete root;
			return NULL;
		}
		//for the node having left child only
		else if (root->left != NULL && root->right == NULL) {
			BST* tmp = root->left;
			delete root;
			return tmp;
		}

		//for the node having right child only
		else if (root->left == NULL && root->right != NULL) {
			BST* tmp = root->right;
			delete root;
			return tmp;
		}

		/*for the node having both left and right child
		* in this case find the largest element form left subtree or the lowest element from right subtree
		* In this example I am going to use lowest element from right subtree
		*/
		else {
			BST* curr_prent = root;
			BST* curr = root->right;
			while (curr->left != NULL) {
				curr_prent = curr;
				curr = curr->left;
			}
			if (curr_prent != root)
				curr_prent->left = curr->right;
			else
				curr_prent->right = curr->right;
			root->data = curr->data;
			delete curr;
			return root;
		}
	}
	else if (root->data > num) {
		root->left = delete_BST(root->left, num);
		return root;
	}
	else {
		root->right = delete_BST(root->right, num);
		return root;
	}
	//return root;
}


void getNodes(BST* root, std::vector<int>& vec) {
	if (root == NULL)
		return;
	getNodes(root->left, vec);
	vec.push_back(root->data);
	getNodes(root->right, vec);
}
bool twoSumInBST(BST * root, int target) {
	//Write your code here
	std::vector<int> vec;
	getNodes(root, vec);
	int i = 0, j = vec.size() - 1;
	while (i < j) {
		int sum = vec[i] + vec[j];
		if (sum == target)
			return true;
		else if (sum > target)
			j--;
		else
			i++;
	}

	return false;

}
void getNodes_indq(BST* root, std::deque<BST*>& dq) {
	if (root == NULL)
		return;
	getNodes_indq(root->left, dq);
	dq.push_back(root);
	getNodes_indq(root->right, dq);
}

BST* flatten(BST* root) {
	std::deque<BST*> dq;
	BST* tmp = NULL;
	getNodes_indq(root, dq);
	std::cout << "dq.size() = " << dq.size();

	root = dq.front();
	root->left = NULL;
	root->right = NULL;
	dq.pop_front();
	tmp = root;
	while (dq.size() > 0) {
		tmp->right = dq.front();
		tmp = tmp->right;
		tmp->left = NULL;
		tmp->right = NULL;
		dq.pop_front();
	}
	return root;
}


/*
************* CREATE BST FROM PREORDER ARRAY *********************
*
*/
BST* create_BST_from_Preorder_array_Utill(BST* root, std::vector<int> &pre_order_arr, int& index, int mini, int max) {
	if (index >= pre_order_arr.size())
		return NULL;
	if (index < mini || index > max)
		return NULL;
	root = new BST(pre_order_arr[index++]);
	root->left = create_BST_from_Preorder_array_Utill(root->left, pre_order_arr, index, mini, root->data);
	root->right = create_BST_from_Preorder_array_Utill(root->right, pre_order_arr, root->data, max, root->data);
	
	return root;
}
void create_BST_from_Preorder_array() {
	BST* root = NULL;
	//std::vector<int>pre_order_arr = {20, 10, 5, 15, 13, 35, 30, 42};
	std::vector<int>pre_order_arr = { 15, 10, 7, 13, 21, 20, 25 };
	std::cout << "\nPeeorder array" << std::endl;
	for (auto i : pre_order_arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	int mini = INT_MIN;
	int max = INT_MAX;
	int index = 0;
	root = create_BST_from_Preorder_array_Utill(root, pre_order_arr, index, mini, max);
	inorder_traversal(root);
}








void save_data_from_inorder_traversal(BST* root, std::vector<int>& vec) {
	if (root == NULL)
		return;
	save_data_from_inorder_traversal(root->left, vec);
	vec.push_back(root->data);
	save_data_from_inorder_traversal(root->right, vec);
}

std::vector<int> mergeTwoSortedArray(std::vector<int> vec1, std::vector<int> vec2) {
	int i = 0, j = 0;
	std::vector<int> result;
	while (i < vec1.size() && j < vec2.size()) {
		if (vec1[i] <= vec2[j]) {
			result.push_back(vec1[i]);
			i++;
		}
		else {
			result.push_back(vec2[j]);
			j++;
		}
	}
	while (i++ < vec1.size())
		result.push_back(vec1[i -1]);
	while (j++ < vec2.size())
		result.push_back(vec2[j -1]);

	return result;
}
BST* createBSTFromInorder(std::vector<int>& in, int st, int end) {
	if (st > end)
		return NULL;
	int mid = st + (end - st) / 2;
	BST* root = new BST(in[mid]);
	root->left = createBSTFromInorder(in, st, mid - 1);
	root->right = createBSTFromInorder(in, mid + 1, end);
	return root;
}
void mergeBST(BST* root1, BST* root2)
{
	//step 1 save inorder of root1 and root2
	// result of step 1 will be 2 sorted array
	std::vector<int> inorder1, inorder2;
	save_data_from_inorder_traversal(root1, inorder1);
	save_data_from_inorder_traversal(root2, inorder2);

	//step 2 merge 2 sorted array
	std::vector<int> result = mergeTwoSortedArray(inorder1, inorder2);

	//step 3 create BST from sorted array
	BST* root3 = createBSTFromInorder(result, 0, result.size() - 1);

	//step 4 save result bst into inorder array and return
	std::vector<int>ans;
	save_data_from_inorder_traversal(root3, ans);


	for (auto data : ans)
		std::cout << data << " ";
}