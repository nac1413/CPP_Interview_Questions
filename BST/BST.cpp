#include"BST.h"
#define N 14

int main() {
	BST* root = NULL;
	BST* flat_root = NULL;
	BST* tmp = NULL;
	int option = 0;
	int num = 0;
	//int arr[N]={10, 8, 21, 7, 27, 5, 4, 3, 6, 22};
	int arr[N] = { 10, 50, 35, 56, 55, 54, 53, 52, 51, 58, 60, 5, 4, 8 };
	std::vector<int> case5_bst1_vec = { 10, 8, 21, 7, 27 };
	std::vector<int> case5_bst2_vec = { 5, 4, 3, 6, 22 };
	BST* case5_BST1 = NULL;
	BST* case5_BST2 = NULL;
	for (auto i : arr) {
		root = createBST(root, i);
	}
	inorder_traversal(root);
	std::cout << std::endl << "Press 1 for delete the node" << std::endl;
	std::cout << "Press 2 for Two Sum  - Input is a BST " << std::endl;
	std::cout << "Press 3 for Flatten BST To A Sorted List " << std::endl;
	std::cout << "Press 4 for Create BST from preorder array" << std::endl;
	std::cout << "Press 5 for Merge 2 BST " << std::endl;
	std::cin >> option;
	switch (option)
	{
	case 1:
		std::cout << "ENter the element to delete " << std::endl;
		std::cin >> num;
		std::cout << "Before delete the tree nodes are" << std::endl;
		inorder_traversal(root);

		std::cout << std::endl << "After delete the tree nodes are" << std::endl;
		root = delete_BST(root, num);
		inorder_traversal(root);

		break;
	case 2:
		num = 70;
		if (twoSumInBST(root, num))
			std::cout << "Pair exist whose some is equeal to " << num << std::endl;
		else
			std::cout << "Pair does not exist whose some is equeal to " << num <<std::endl;
		break;
	case 3:
		flat_root = flatten(root);
		tmp = flat_root;
		std::cout << "\nFlatten tree = " << std::endl;
		while (tmp) {
			std::cout << tmp->data << " ";
			tmp = tmp->right;
		}
		break;
	case 4:
		create_BST_from_Preorder_array();
		break;
	case 5:
		for ( int i = 0; i < case5_bst1_vec.size(); i++)
			case5_BST1 = createBST(case5_BST1, case5_bst1_vec[i]);

		for (int i = 0; i < case5_bst2_vec.size(); i++)
			case5_BST2 = createBST(case5_BST2, case5_bst2_vec[i]);

		std::cout << "Before merge " << std::endl;
		std::cout << "Inorder travresal of BST1" << std::endl;
		inorder_traversal(case5_BST1);

		std::cout << "\nInorder travresal of BST2" << std::endl;
		inorder_traversal(case5_BST2);

		std::cout << "After  merge " << std::endl;
		mergeBST(case5_BST1, case5_BST2);
		break;
	default:
		break;
	}
	return 0;
}