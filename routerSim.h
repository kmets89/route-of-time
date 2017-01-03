/* Kaylan Mettus
CS 302.1002
Assignment #6

The header file for the routerSim class */

#ifndef ROUTERSIM_H
#define ROUTERSIM_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

#include "radixTree.h"

class routerSim
{
public:
	// Constructor
	routerSim();
	// Reads a file containing IP addresses into a tree
	bool readRoutingTable(const std::string);
	// Prints total number of routes found
	void showTotalRoutesCount() const;
	// Prints the number of nodes in the tree
	void showTreeNodeCount() const;
	// Prints the height of the b-tree
	void showTreeHeight() const;
	// Searches the tree for a key 
	bool search(const std::string) const;
	// Finds the router table entries with matching IP hosts and
	// uses the b-tree to populate a queue with them
	void findMatches(std::string, linkedQueue<std::string> &) const;
	// Finds the destination IP for each source IP in a file, outputs
	// both in a text file
	void doRouting(const std::string, const std::string) const;
private:
	unsigned int totalRoutesCount;
	radixTree rTableTree;
	// Splits a router table entry into AS values and destination IP
	void split(const std::string, std::string &, std::string &) const;
	// Finds the lowest total AS values for a set of routing table
	// entries
	std::string selectDestination(linkedQueue<std::string> &) const;
};

#endif
