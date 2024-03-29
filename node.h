/*
 *		Dani Pavlat
 *		02/05/2022
 *		CMP SCI 4280
 *
 *		node.h: node structure with three child pointers
 *			for use in modified binary tree
 *
 */

#ifndef NODE_H
	#define NODE_H

	typedef struct Node {
			struct Node * left;
			struct Node * middle;
			struct Node * right;
			char lastChar;
			char * data;
		} Node;

#endif
