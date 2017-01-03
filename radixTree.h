/* Kaylan Mettus
CS302-1002
Assignment 6

The header file for the radixTree class */

#ifndef RADIXTREE_H
#define RADIXTREE_H

#include <string>
#include <iostream>

#include "linkedQueue.h"

class radixTree
{
public:
	//Constructor
	radixTree();
	//Destructor
	~radixTree();
	// Returns number of nodes in tree
	unsigned int nodeCount() const;
	// Returns height of tree
	unsigned int height() const;
	// Inserts a string into the tree
	void insert(std::string);
	// Returns true if a string could be found in the tree
	bool search(std::string) const;
	// Prints all entries in tree
	void printTree() const;
	// Populates a queue with all entries containing a string
	void fuzzySearch(std::string, linkedQueue<std::string> &) const;
	// Frees memory for entire tree
	void destroyTree();
private:
	static const int NUM; // Initialized to 12
	struct radixTreeNode{
		char keyValue;
		bool endMark;
		std::string payload;
		radixTreeNode *children[12];
	};
	radixTreeNode *root;
	unsigned int nodeCount(radixTreeNode *) const;
	unsigned int height(radixTreeNode *) const;
	void destroyTree(radixTreeNode *);
	void printTree(radixTreeNode *, std::string) const;
	void fuzzySearch(radixTreeNode *, std::string, linkedQueue<std::string> &) const;
	bool valid(std::string) const;
};

#endif
