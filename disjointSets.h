#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H

using namespace std;

// Disjoint Sets class

class disjointSets
{
public:
	disjointSets(int=10);
	~disjointSets();

	int	setUnion(int, int);
	int	setFind(int);
	int	entries() const;
	bool	isEmpty() const;
	void	printSets() const;

private:
	int	setSize;
	int	*links, *ranks;
};

#endif

