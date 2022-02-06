/*
 *	 	Dani Pavlat
 * 		02/05/2022
 * 		CMP SCI 4280
 *
 * 		customTree.c:
 * 			main driver function: creates and traverses
 * 			a modified binary tree
 *
 */

#include <stdio.h>
#include "node.h"
#include "tree.h"

int main(int argc, char* argv[]) {
	// process command line arguments first and error if improper
	// if filename given, make sure file is readable, error otherwise
	// set up keyboard processing so that below this point there is only one version of the code

	/*Node * root = buildTree(file);

	printPreorder(root);
	printInorder(root);
	printPostorder(root);
	*/

	FILE * fstream = stdin;

	Node * tree = buildTree(fstream);
	printPreorder(tree, 0);
//	printInorder();
//	printPostorder();

	return 0;
}
