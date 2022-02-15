/*
 *		Dani Pavlat
 *	 	02/14/2022
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
		// creates a new node with null pointers for child nodes
		Node * temp = malloc(sizeof(Node));
		temp -> data = malloc(strlen(string) + 1);

		temp -> lastChar = last;
		strcpy(temp -> data, string);
		temp -> left
			= temp -> middle
			= temp -> right
			= NULL;

		return temp;
	}

	Node * insertNode(Node * node, char * string, char newChar) {
		// inserts a new node based on value of the string's last character
		if (node == NULL) {
		        return newNode(string, newChar);
		    } else {
		        if (newChar < node -> lastChar) {
		            node -> left = insertNode(node -> left, string, newChar);
		        } else if (newChar > node -> lastChar) {
		            node -> right = insertNode(node -> right, string, newChar);
		        } else {
		        	node -> middle = insertNode(node -> middle, string, newChar);
		        }
		    }

		    return (node); // return the new pointer to the caller
	}

	Node buildTree( FILE * fInput ) {
		/*		constructs the modified binary tree based on the
		 * 		value of the last character of the data string				*/

		Node * node = NULL;		// root node
		char * string = NULL;		// string to be added to tree
		char newChar = NULL;		// last char in string, for comparison

		string = malloc(50 * sizeof(char));
		// loop through strings in fInput
		while ( scanf("%s", string) != EOF) {
			newChar = string[strlen(string) - 1];
			// insert a new node for each string, based on string's last char
			node = insertNode(node, string, newChar);
		}

		return * node;	// returns completed tree
	}

	void outputTraversal(Node * node, int level, FILE * outFile) {
		// prints traversal to console
		printf("%*c%c:%-9s \n", level * 2, ' ', node -> lastChar, node -> data);

		// writes traversal output to file
		fprintf(outFile, "%*c%c:%-9s \n", level * 2, ' ', node -> lastChar, node -> data);
	}

	void printInorder(Node * node, int level, FILE * out) {
		/*		prints the binary tree using inorder traversal
		 * 		(left child, root/down middle pointer, right child)		*/

		if (node == NULL) {
			return;
		}
		// first recur down left
		printInorder(node -> left, level + 1, out);
		// print root + write to output file
		outputTraversal(node, level, out);

		// then middle, then right child
		printInorder(node-> middle, level + 1, out);
		printInorder(node -> right, level + 1, out);
	}

	void printPreorder(Node * node, int level, FILE * out) {
		/*		prints the binary tree using preorder traversal
		 * 		(root, left child, middle child, right child)					*/

		if (node == NULL) {
			return;
		}
		// first print the data of the node + also write to output file
		outputTraversal(node, level, out);

		// then, recur on left, middle, and right subtrees
		printPreorder(node -> left, level + 1, out);
		printPreorder(node -> middle, level + 1, out);
		printPreorder(node -> right, level + 1, out);
	}

	void printPostorder(Node * node, int level, FILE * out) {
		/*		prints the binary tree using postorder traversal
		 * 		(left child, middle child, right child, root)					*/

		if (node == NULL) {
			return;
		}
		// first recur on left, middle, and right subtrees
		printPostorder(node -> left, level + 1, out);
		printPostorder(node-> middle, level + 1, out);
		printPostorder(node -> right, level + 1, out);
		// then print the data of the node + also write to output file
		outputTraversal(node, level, out);
	}
