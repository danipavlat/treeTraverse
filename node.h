	/*
	 *		Dani Pavlat
	 *		01/25/2021
	 *		CMP SCI 4280
	 *
	 *		node.h: node structure with three child pointers
	 *			for use in modified binary tree
	 *
	 */

#ifndef NODE_H
	#define NODE_H

	typedef struct Node {
			struct Node* left;
			struct Node* middle;
			struct Node* right;
			char data[];
		} Node;

#endif
