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

	struct Node  * newNode(char * string) {
		// creates a new node with null pointers for child nodes
		Node * temp = (struct Node *)malloc(sizeof(struct Node));

		temp -> data = string;
		temp -> left
			= temp -> middle
			= temp -> right
			= NULL;

		return temp;
	}

	void buildTree( FILE * fstream ) {
		/*		constructs the modified binary tree based on the
		 * 		value of the last character of the data string				*/

		Node * node = NULL;	// root node
		char string[50];
		char newChar;
		char lastChar;

		// loop through strings in fstream
		while (scanf("%s", string) != EOF) {
			if ( node == NULL) {	// if root node
				node = newNode(string);
			} else {
				// get the last characters for comparison
				newChar = string[ strlen(string - 1) ];

				// create child nodes based value of last character
				if ( newChar < lastChar ) {
					node -> left = newNode(string);
				} else if ( newChar > lastChar ) {
					node -> right = newNode(string);
				} else {
					node -> middle = newNode(string);
				}
			}
			// set lastChar for next loop iteration
			lastChar = node -> data[ strlen(node -> data) -1 ];
		}
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

