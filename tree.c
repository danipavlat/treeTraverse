/*
 *		Dani Pavlat
 *	 	01/25/2021
 *	 	CMP SCI 4280
 *
 *	 	tree.c:
 * 			contains functions for the construction
 * 			and traversals of a modified binary tree
 *
 */

#include <stdio.h>
#include "node.h"

	void buildTree() {
		/*		constructs the modified binary tree based on the
		 * 		value of the last character of the data string				*/
		printf("in buildTree\n");

		/*
		 * 		to build tree:
		 *
		 * 		lastChar < prevLast ?
		 * 			leftNode = lastChar
		 * 			: lastChar > prevLast ?
		 * 				rightNode = lastChar
		 * 				: middleNode = lastChar
		 */
	}

	void printInorder() {
		/*		prints the binary tree using inorder traversal
		 * 		(left child, root/down middle pointer, right child)		*/
		printf("in printInorder\n");
	}

	void printPreorder() {
		/*		prints the binary tree using preorder traversal
		 * 		(root, left child, middle child, right child)					*/
		printf("in printPreorder\n");
	}

	void printPostorder() {
		/*		prints the binary tree using postorder traversal
		 * 		(left child, middle child, right child, root)					*/
		printf("in printPostorder\n");
	}

