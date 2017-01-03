/* Kaylan Mettus
CS 302.1002
Assignment #6

The implementation file for the routerSim class */

#include "routerSim.h"

// Constructor
routerSim::routerSim()
{
	totalRoutesCount = 0;
}

// Public functions

// Reads IP addresses from a file into a Tree
// Returns false if the file was unable to be opened
bool routerSim::readRoutingTable(const std::string fileName)
{
	std::ifstream inFile;
	std::string addr;
	inFile.open(fileName.c_str());
	
	if (!inFile)
		return false;
	
	while (std::getline(inFile, addr))
	{
		rTableTree.insert(addr);
		totalRoutesCount++;
	}
		
	inFile.close();
	return true;
}

// Prints the total number of routes
void routerSim::showTotalRoutesCount() const
{
	std::cout << "Total Routes Count: " << totalRoutesCount << std::endl;
}

// Prints the number of nodes in the tree
void routerSim::showTreeNodeCount() const
{
	std::cout << "Tree Node Count: " << rTableTree.nodeCount() << std::endl;	
}

//Prints the height of the tree
void routerSim::showTreeHeight() const
{
	std::cout << "Tree Height: " << rTableTree.height() << std::endl;
}

//Searches the tree for val.  Returns T if found, F otherwise
bool routerSim::search(const std::string val) const
{
	return rTableTree.search(val) ? true : false;
}

//Searches the bTree and populates a linked queue containing all
// entries starting with val
void routerSim::findMatches(std::string val, linkedQueue<std::string> &myQueue) const
{
	rTableTree.fuzzySearch(val, myQueue);
}

//Reads a list of IP addresses, and finds the destination address for 
// each one.  Outputs source and destination IPs to a textfile
void routerSim::doRouting(const std::string sourceFile, const std::string destFile) const
{
	std::ifstream inFile;
	std::ofstream outFile;
	std::string ip, destip, temp;
	int p, p2;
	linkedQueue<std::string> ipQueue;
	
	inFile.open(sourceFile.c_str());
	outFile.open(destFile.c_str());
	
	while (std::getline(inFile, ip))
	{	
		temp = ip;
		//get network section of ip
		p = temp.find('.');
		p2 = temp.find('.', p + 1);
		temp.resize(p2);
		// Populate ipQueue with partial matches
		findMatches(temp, ipQueue);
		// Find the destination IP from the routing table AS values
		destip = selectDestination(ipQueue);
		outFile << ip << '\t' << destip << std::endl;
	}
	
	inFile.close();
	outFile.close();
}

// Private functions
void routerSim::split(const std::string entry, std::string &as, std::string &dest) const
{
	int begPos, endPos;
	// find the pipes in the string
	begPos = entry.find_first_of("|");
	endPos = entry.find_last_of("|");
	
	// AS prefixes are between first and last |
	as = entry.substr(begPos + 1, (endPos - begPos) - 1);
	// Destination IP address is after the second |
	dest = entry.substr(endPos + 1);
}

// Parses matching IP hosts in a queue to find the destination IP. 
// Destination IP is the first entry with the lowest sum of AS values
std::string routerSim::selectDestination(linkedQueue<std::string> &myQueue) const
{
	int min = std::numeric_limits<int>::max();
	int pos, num, sum = 0;
	std::string entry, as, asSub, dest, finalDest = "No Matches";
	std:: stringstream ss;
	
	while (!myQueue.isEmpty())
	{
		entry = myQueue.front();
		split(entry, as, dest);
	
		//break AS string into numbers and sum them
		while (!as.empty())
		{
			pos = as.find(' ');
			asSub = as.substr(0, pos);
			as.erase(0, ++pos);
			ss << asSub;
			ss >> num;
			sum += num;
			if (pos == 0)
				as.clear();
			ss.clear();
		}
		// The first smallest value in the queue is the destination
		if (sum < min)
		{
			min = sum;
			finalDest = dest;
		}
		
		// Remove item from queue and process next until empty
		myQueue.remove();	
	}
		
	return finalDest;
}
