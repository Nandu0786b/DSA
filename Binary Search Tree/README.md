                    
                                                BINARY SEARCH TREE  

Binary Search Tree is a node-based binary tree data structure which has the following properties:

    1.    The left subtree of a node contains only nodes with keys lesser than the node’s key.
    2.    The right subtree of a node contains only nodes with keys greater than the node’s key.
    3.    The left and right subtree each must also be a binary search tree.

This property is applicable for the all Node  

https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221215114732/bst-21.png  


Example           
                              7
                            /   \
                          4      9
                         / \    / \
                        2   5  8   11
                             \     \
                              6     13

Worst-Case Time Complexity: 
  Insertion: O(n)
In the worst case scenario, where the BST is unbalanced and degenerates into a linked list, the time complexity for insertion becomes O(n), where n is the number of nodes in the tree. This can happen if the elements are inserted in sorted order. EX:- skewed BST

Search: O(n)
Similarly, in the worst case scenario where the BST is unbalanced, the time complexity for search becomes O(n) as well. This occurs when the elements are inserted in sorted order, leading to a skewed tree. EX:- skewed BST

Deletion: O(n)
In the worst-case scenario, where the BST is unbalanced and degenerates into a linked list, the time complexity for deletion becomes O(n), where n is the number of nodes in the tree. This occurs when the node to be deleted has two children and the tree is unbalanced, requiring a traversal to find the inorder predecessor or successor. EX:- skewed BST

Average Time Complexity:
Insertion: O(log n)
On average, assuming a balanced BST, the time complexity for insertion is O(log n), where n is the number of nodes in the tree. This is because, in a balanced BST, each level roughly divides the remaining elements in half, leading to a logarithmic growth rate.

Search: O(log n)
Likewise, for search operations in a balanced BST, the average time complexity is O(log n). By traversing the tree from the root to the desired node, the search operation eliminates approximately half of the remaining elements at each level.

Deletion: O(log n)
On average, assuming a balanced BST, the time complexity for deletion is O(log n), where n is the number of nodes in the tree. This is because, in a balanced BST, each level roughly divides the remaining elements in half, leading to a logarithmic growth rate.

Inorder producer :- jab inorder print karenga tho x ka just aga wala x ka producer hoga

Inorder successor :- jab inorder print karenga tho x ka just agala element x ka successor hoga


