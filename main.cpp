//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "weightedGraph.h"

using namespace std;

int main(int argc, char *argv[])
{

// *****************************************************************
//  Headers...

	string	stars, bars, dashes;
	string	gFile;
	stars.append(55, '*');
	bars.append(55, '=');
	dashes.append(40,'-');
	const char* bold   = "\033[1m";
	const char* unbold   = "\033[0m";
	bool	doTesting=false;

	cout << stars << endl << bold << "CS 302 - Assignment #11" << endl;
	cout << "Weighted Graph Algorithms" << unbold << endl;
	cout << endl;

// ------------------------------------------------------------------
//  Check arguments

	if (argc == 1) {
		cout << "Usgae: ./main <-t|graphFileName>" << endl;
		return	0;
	}

	if (argc == 2) {
		if (string(argv[1]) == "-t")
			doTesting = true;
		else
			gFile = string(argv[1]);
	}

	if (argc > 2) {
		cout << "Error, invalid command line arguments." << endl;
		return	0;
	}



// ------------------------------------------------------------------
//  Basic error testing...

	if (doTesting) {

		cout << stars << endl;
		cout << "Error testing: " << endl << endl;

		weightedGraph	badGraph;

		badGraph.createGraph(-2);
		badGraph.createGraph(2);
		badGraph.createGraph(10);		// ok
		badGraph.addEdge(11, -11, 100);
		badGraph.addEdge(51, 11, 100);
		badGraph.addEdge(-11, 11, 100);
		badGraph.addEdge(3, 3, 10);
		badGraph.addEdge(5, 7, 100);		// ok
		badGraph.setTitle("Unused Example");

		badGraph.printTopoSort();		// no work
		badGraph.printMST();			// no work

		if (badGraph.getTitle() != "Unused Example")
			cout << "main: title functions do not work." << endl;

		cout << bars << endl;
		cout << "Simple Example Graph: " << endl << endl;

		weightedGraph	myGraph1("Graph Example #1");
		string	tstFile = "test/graph0.txt";

		if (myGraph1.readGraph(tstFile)) {
			myGraph1.printMatrix();
			myGraph1.topoSort();
			myGraph1.printTopoSort();
			myGraph1.kruskals();
			myGraph1.printMST();
		} else {
			cout << "main: Error reading " << tstFile << "." << endl;
		}

		if (myGraph1.getVertexCount() != 7)
			cout << "main: Error, graph 0, vertex count incorrect." << endl;

		if (myGraph1.getEdgeCount() != 12)
			cout << "main: Error, graph 0, vertex edge incorrect." << endl;

		weightedGraph	myGraph2;
		if (myGraph2.getTitle() != "Untitled Graph")
			cout << "main: Error, default title incorrect." << endl;

		cout << endl;
		return	0;
	}


// ------------------------------------------------------------------
//  Main processing...

	cout << bars << endl;

	weightedGraph	myGraph;

	if (myGraph.readGraph(gFile)) {
		myGraph.printMatrix();
		cout << bars << endl;
		myGraph.topoSort();
		myGraph.printTopoSort();
		cout << bars << endl;
		myGraph.kruskals();
		myGraph.printMST();
	} else {
		cout << "main: Error reading " << gFile << "." << endl;
	}

	cout << endl;

// *****************************************************************
//  All done.

	cout << endl << stars << endl <<
		"Game Over, thank you for playing." << endl;

	return 0;
}

