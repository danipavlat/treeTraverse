/*
 *		Dani Pavlat
 *		02/05/2022
 *		CMP SCI 4280
 *
 *		tree.h: contains common function definitions
 *		for modified binary tree construction and traversal
 *
 */

#ifndef TREE_H
	#define TREE_H

	Node * buildTree( FILE * fstream );
	void printInorder(Node * node, int level, FILE * outIn);
	void printPreorder(Node * node, int level, FILE * outPre);
	void printPostorder(Node * node, int level, FILE * outPost);

#endif
