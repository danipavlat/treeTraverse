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
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "tree.h"

int main(int argc, char* argv[]) {
	char * inFile;		// input filename
	char * outPre;	// preorder traversal output filename
	char * outIn;		// inorder traversal output filename
	char * outPost;	// postorder traversal output filename
	FILE * fInput;		// input file

	// check for valid command line arguments
	if (argc > 2) {
		errno = 7;
		perror("ERROR");
		printf("\nUSAGE: \n"
				"P0 \t\t reads from the keyboard until simulated EOF (CTRL + D for unix-style systems or CTRL + Z for Windows)\n"
				"P0 < somefile \t same as above but redirecting from somefile instead of keyboard\n"
				"P0 somefile \t reads from somefile.sp2020\n");
		return 1;
	} else if (argc == 2) {
		// allocates space for input filename + file extension
		inFile = malloc(strlen(argv[1]) + strlen(".sp2022") + 1);
		// adds file extension ".sp2022" to input filename, then opens
		strcpy(inFile, argv[1]);
		strcat(inFile, ".sp2022");
		fInput = fopen(inFile, "r");

		// verify input file exists
		if (fInput == NULL) {
			perror("ERROR");
			return 1;
		}

		// keeps the input filename for output, plus the appropriate traversal
		outPre = malloc(strlen(argv[1]) + strlen(".preorder") + 1);
		strcpy(outPre, argv[1]);
		strcat(outPre, ".preorder");

		outIn = malloc(strlen(argv[1]) + strlen(".inorder") + 1);
		strcpy(outIn, argv[1]);
		strcat(outIn, ".inorder");

		outPost = malloc(strlen(argv[1]) + strlen(".postorder") + 1);
		strcpy(outPost, argv[1]);
		strcat(outPost, ".postorder");
	} else {
		// given input from stdin (Usage: P0 or P0 < xxx.sp2022)

		fInput = stdin;
		// allocate space for output filenames
		outPre = malloc(strlen("output.preorder") + 1);
		outIn = malloc(strlen("output.inorder") + 1);
		outPost = malloc(strlen("output.postorder") + 1);

		// name output files with corresponding traversal
		strcpy(outPre, "output.preorder");
		strcpy(outIn, "output.inorder");
		strcpy(outPost, "output.postorder");
	}

	// builds modified binary tree + traverses
	Node * tree = buildTree(fInput);

	printf("Preorder traversal: \n");
	printPreorder(tree, 0, outPre);

	printf("\nInorder traversal: \n");
	printInorder(tree, 0, outIn);

	printf("\nPostorder traversal: \n");
	printPostorder(tree, 0, outPost);

	return 0;
}
