/*
 *		Dani Pavlat
 *	 	02/05/2022
 *	 	CMP SCI 4280
 *
 *	 	tree.c:
 * 			contains functions for the construction
 * 			and traversals of a modified binary tree
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

	struct Node  * newNode(char * string, char last) {
		// TODO: THIS SEEMS OK

		// creates a new node with null pointers for child nodes
		Node * temp = malloc(sizeof(Node));
		temp -> data = malloc(strlen(string) + 1);

		temp -> lastChar = last;
		temp -> data = string;
		temp -> left
			= temp -> middle
			= temp -> right
			= NULL;

		return temp;
	}

	Node * insertNode(Node * node, char * string, char newChar) {
		// TODO: THIS ALSO SEEMS OK
		// inserts a new node based on value of the string's last character
		if (node == NULL) {
		        node = newNode(string, newChar);
//		        printf("%s\n", node -> data);
		    } else {
		        if (newChar < node -> lastChar) {
//		        	printf("left: ");
		            node -> left = insertNode(node -> left, string, newChar);
		        } else if (newChar > node -> lastChar) {
//		        	printf("right: ");
		            node -> right = insertNode(node -> right, string, newChar);
		        } else {
//		        	printf("middle: ");
		        	node -> middle = insertNode(node -> middle, string, newChar);
		        }
		    }

		    return (node); // return the new pointer to the caller
	}

	Node buildTree( FILE * fstream ) {
		// TODO: ALSO OK
		/*		constructs the modified binary tree based on the
		 * 		value of the last character of the data string				*/

		Node * node = NULL;	// root node
		char * string;				// string to be added to tree
		char newChar;				// last char in string, for comparison

		string = malloc(50 * sizeof(char));
		// loop through strings in fstream
		while (scanf("%s", string) != EOF) {
			newChar = string[strlen(string) - 1];
			// insert a new node for each string, based on string's last char
			node = insertNode(node, string, newChar);
		}

		return * node;	// returns completed tree
	}

	void printInorder() {
		/*		prints the binary tree using inorder traversal
		 * 		(left child, root/down middle pointer, right child)		*/
		printf("in printInorder\n");
	}

	void printPreorder(Node * node, int level) {
		// TODO: Why can't I access the data string?????

		/*		prints the binary tree using preorder traversal
		 * 		(root, left child, middle child, right child)					*/
		int i;

		if (node == NULL) {
			return;
		}
		// first print the data of the node
		for (i = 0; i < (level * 2); i++) {
			printf(" ");
		}
		printf("%c: %s\n", node -> lastChar, node -> data);
		// then, recur on left, middle, and right subtrees
		printPreorder(node -> left, level + 1);
		printPreorder(node -> middle, level + 1);
		printPreorder(node -> right, level + 1);
	}

	void printPostorder() {
		/*		prints the binary tree using postorder traversal
		 * 		(left child, middle child, right child, root)					*/
		printf("in printPostorder\n");
	}

