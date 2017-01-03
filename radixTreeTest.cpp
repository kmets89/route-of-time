//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "radixTree.h"

using namespace std;

int main()
{

// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(30, '-');
	stars.append(65, '*');

	cout << stars << endl << "CS 302 - Assignment #6" << endl;
	cout << endl;

// *****************************************************************
//  Test Trie

	radixTree	myTree0;
	string	addrs0[8] = { "1.0.224.0/19|1|157.130.10.233",
				"1.1.1.0/24|1|85.114.0.217",
				"1.1.33.0/24|1|129.250.0.11",
				"1.1.63.0/24|1|129.250.0.11",
				"1.1.64.0/19|1|216.218.252.164",
				"1.1.127.0/24|1|216.218.252.164",
				"1.1.128.0/17|1|157.130.10.233",
				"1.11.64.0/21|1|157.130.10.233" };
	int	len0 = 8;

	cout << bars << endl << "Test Set #0  (" << len0 << ")"
			<< endl << endl;

	for (int i=0; i<len0; i++)
		myTree0.insert(addrs0[i]);

	for (int i=0; i<len0; i++)
		if (!myTree0.search(addrs0[i]))
		cout << "main: Error, address "" " << addrs0[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree0.height() << endl;
	cout << "Node Count: " << myTree0.nodeCount() << endl;
	cout << endl;

	cout << "Radix Tree Contents: " << endl;
	myTree0.printTree();
	cout << endl;

// *****************************************************************

	radixTree	myTree1;
	string	addrs1[21] = { "60.196.0.0/15|1|213.144.128.203",
				"60.196.0.0/24|1|157.130.10.233",
				"60.196.12.0/24|1|213.144.128.203",
				"60.198.0.0/16|1|216.218.252.164",
				"60.198.0.0/17|1|216.218.252.164",
				"60.198.64.0/18|1|157.130.10.233",
				"60.198.64.0/19|1|216.218.252.164",
				"60.198.96.0/19|1|216.218.252.164",
				"60.198.128.0/17|1|216.218.252.164",
				"60.198.128.0/20|1|157.130.10.233",
				"60.198.240.0/20|1|157.130.10.233",
				"60.198.248.0/22|1|157.130.10.233",
				"60.199.0.0/16|1|216.218.252.164",
				"60.199.0.0/18|1|216.218.252.164",
				"60.199.0.0/24|1|157.130.10.233",
				"60.199.2.0/24|1|216.218.252.164",
				"60.199.10.0/24|1|157.130.10.233",
				"60.199.11.0/24|1|203.181.248.168",
				"60.199.32.0/24|1|157.130.10.233",
				"60.199.33.0/24|1|157.130.10.233",
				"60.199.36.0/24|1|157.130.10.233" };
	int	len1 = 21;

	cout << bars << endl << "Test Set #1  (" << len1 << ")"
			<< endl << endl;

	for (int i=0; i<len1; i++)
		myTree1.insert(addrs1[i]);

	for (int i=0; i<len1; i++)
		if (!myTree1.search(addrs1[i]))
		cout << "main: Error, address "" " << addrs1[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree1.height() << endl;
	cout << "Node Count: " << myTree1.nodeCount() << endl;
	cout << endl;

	cout << "Radix Tree Contents: " << endl;
	myTree1.printTree();
	cout << endl;

// *****************************************************************
//  Test Trie

	radixTree	myTree2;
	string	addrs2[25] = { "1.0.224.0/19|1|157.130.10.233",
				"1.1.1.0/24|1|85.114.0.217",
				"1.1.33.0/24|1|129.250.0.11",
				"1.1.63.0/24|1|129.250.0.11",
				"1.1.64.0/19|1|216.218.252.164",
				"1.1.127.0/24|1|216.218.252.164",
				"1.1.128.0/17|1|157.130.10.233",
				"1.2.224.0/19|1|216.218.252.164",
				"1.4.128.0/17|1|157.130.10.233",
				"1.4.192.0/18|1|195.22.216.188",
				"1.4.192.0/19|1|157.130.10.233",
				"1.4.224.0/19|1|216.218.252.164",
				"1.5.0.0/16|1|157.130.10.233",
				"1.8.1.0/24|1|129.250.0.11",
				"1.8.8.0/24|1|129.250.0.11",
				"1.8.101.0/24|1|157.130.10.233",
				"1.8.243.0/24|1|157.130.10.233",
				"1.9.0.0/16|1|89.149.178.10",
				"1.9.21.0/24|1|203.181.248.168",
				"1.9.204.0/24|1|89.149.178.10",
				"1.9.205.0/24|1|89.149.178.10",
				"1.10.192.0/19|1|195.22.216.188",
				"1.10.224.0/19|1|195.22.216.188",
				"1.11.0.0/21|1|129.250.0.11",
				"1.11.64.0/21|1|157.130.10.233" };
	int	len2 = 25;

	cout << bars << endl << "Test Set #2  (" << len2 << ")"
			<< endl << endl;

	for (int i=0; i<len2; i++)
		myTree2.insert(addrs2[i]);

	for (int i=0; i<len2; i++)
		if (!myTree2.search(addrs2[i]))
		cout << "main: Error, address "" " << addrs2[i]
			<< " "" is lost." << endl;

	cout << "Max Height: " << myTree2.height() << endl;
	cout << "Node Count: " << myTree2.nodeCount() << endl;
	cout << endl;

	cout << "Radix Tree Contents: " << endl;
	myTree2.printTree();
	cout << endl;

// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}
