/* Kaylan Mettus
CS302-1002
Assignment 6

The implementation file for the radixTree class */

#include "radixTree.h"

const int radixTree::NUM = 12;

//Constructor
radixTree::radixTree()
{
	root = new radixTreeNode;
	root->keyValue = '\0';
	root->endMark = false;
	root->payload = "";
	for (int i = 0; i < NUM; i++)
		root->children[i] = NULL;
}

//Destructor
radixTree::~radixTree()
{
	destroyTree();
}

//Public functions
unsigned int radixTree::nodeCount() const
{
	return nodeCount(root);
}

//Returns the height of the trie
unsigned int radixTree::height() const
{
	return height(root);
}

// Inserts val into the trie
void radixTree::insert(std::string val)
{
	unsigned int length, index, i = 0, level = 0;
    std::string source, pl;
    radixTreeNode *curr;
    
    if (!valid(val))
        return;
        
    // create strings of the source IP and payload
    while (val[i] != '|' && i < val.length())
    {
        i++;
        source = val.substr(0, i);
        length = source.length();
    }
    pl = val.substr(i);
       
    curr = root; 
    
	// find corresponding array index for current character and see if node exists
    for (level = 0; level < length; level++)
    {
        if (val[level] == '.')
            index = 10;
        else if (val[level] == '/')
            index = 11;
        else
            index = static_cast<unsigned int>(val[level]) - static_cast<unsigned int>('0');

		// Create new node if needed
		if (curr->children[index] == NULL)
		{
		curr->children[index] = new radixTreeNode;
		for (int j = 0; j < NUM; j++)
			curr->children[index]->children[j] = NULL;
		curr->children[index]->keyValue = source[level];
		curr->children[index]->endMark = false;
		curr->children[index]->payload = "";
		}

		// Continue stepping down tree if node exists
		curr = curr->children[index];
	}
		curr->payload = pl;
		curr->endMark = true;
}

// Searches trie for a string up to the payload
bool radixTree::search(std::string val) const
{
	unsigned int length, index, i = 0, level = 0;
    std::string searchKey;
    radixTreeNode *curr;
    
    if (!valid(val))
        return false;
    
    // create a string of the just the source IP
    while (val[i] != '|' && i < val.length())
    {
        i++;
        searchKey = val.substr(0, i);
        length = searchKey.length();
    }
        
    curr = root;
    
    // find corresponding array index for current character and see if node exists
    while (curr != NULL && level < length)
    {
        if (searchKey[level] == '.')
            index = 10;
        else if (searchKey[level] == '/')
            index = 11;
        else
            index = static_cast<unsigned int>(searchKey[level]) - static_cast<unsigned int>('0');
        curr = curr->children[index];
        level++;
    }
    return (curr != NULL && curr->endMark) ? true : false;  
}

// Prints every value in the trie
void radixTree::printTree() const
{	
	std::string ip = "";
	
	printTree(root, ip);
}

// Searches a trie for the network section of an IP address and
// Adds all appropriate nodes to the passed queue
void radixTree::fuzzySearch(std::string val, linkedQueue<std::string> &myQueue) const
{
	unsigned int index, level = 0;
	
	if (valid(val) == false)
		return;
	
	radixTreeNode *curr = root;
	
	 // find corresponding array index for current character and see if node exists
    while (curr != NULL && level < val.length())
    {
        if (val[level] == '.')
            index = 10;
        else if (val[level] == '/')
            index = 11;
        else
            index = static_cast<unsigned int>(val[level]) - static_cast<unsigned int>('0');
        curr = curr->children[index];
        level++;
    }

	fuzzySearch(curr, val, myQueue);
}

//Deletes the current trie and resets the sentinel node
void radixTree::destroyTree()
{
	destroyTree(root);
		root = new radixTreeNode;
	root->keyValue = '\0';
	root->endMark = false;
	root->payload = "";
	for (int i = 0;i < NUM; i++)
		root->children[i] = NULL;
}
//Private functions

// Called by the public nodeCount() function
unsigned int radixTree::nodeCount(radixTreeNode *ptr) const
{
	unsigned int count = 1;

		for (int i = 0; i < NUM; i++)
			if (ptr->children[i] != NULL)
				count += nodeCount(ptr->children[i]);

	return count;
}

// Called by the public height() function
unsigned int radixTree::height(radixTreeNode *ptr) const
{
	unsigned int maxDepth = 0, thisDepth = 0;
	
	if (ptr == NULL)
		return 0;

	{
		for (int i = 0; i < NUM; i++)
		{
			thisDepth = height(ptr->children[i]);
			if (thisDepth > maxDepth)
				maxDepth = thisDepth;
		}
		return maxDepth + 1;
	}
}

// Frees all memory allocated for the current tree
void radixTree::destroyTree(radixTreeNode *ptr)
{
	if (ptr != NULL)
	{
		for (int i = 0; i < NUM; i++)
			destroyTree(ptr->children[i]);
		delete ptr;
	}
}

// Called by public PrintTree() function
void radixTree::printTree(radixTreeNode *ptr, std::string val) const
{
	if (ptr != NULL)
	{
		// Keep appending to a string with every recursion
		val += ptr->keyValue;
	
		if (ptr->endMark == true)
		{
			val += ptr->payload;
			// Print when a leaf node has been reached
			std::cout << val << std::endl;
		}

		for (int i = 0; i < NUM; i++)
			printTree(ptr->children[i], val);
	}
}

// Called by the public fuzzySearch function
// Adds all complete IP table entries into a queue 
void radixTree::fuzzySearch(radixTreeNode *curr, std::string val, linkedQueue<std::string> &myQueue) const
{
	if (curr == NULL)
		return;
	else if (curr->endMark == true)
		myQueue.add(curr->payload);
	else
		for (int i = 0; i < NUM; i++)
			fuzzySearch(curr->children[i], val, myQueue);
}

// Checks that the entered string conains only valid characters
bool radixTree::valid(std::string val) const
{
    for (unsigned int i = 0; i < val.length(); i++)
        if (((static_cast<int>(val[i]) < 48 ) || (static_cast<int>(val[i]) > 57)) && (val[i] != '/' && val[i] != '.' && val[i] != '|' && val[i] != ' '))
            return false;
    return true;
}
