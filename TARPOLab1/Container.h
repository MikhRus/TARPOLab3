#ifndef __Container__
#define __Container__

#include "Wisdom.h"

//------------------------------------------------------------------------------
// container.h - contains class,
// represents the container - hash, based on a one-dimensional array.

class Container
{
public:
	enum { len = 4 };
	Wisdom* cont[len]; 
	int key;

	int hash_func(int k);
	void In(ifstream& ifst); // entering matrices into a container from input stream
	void Out(ofstream& ofst); // output matrices in output stream
	void Clear(); // container cleaning matrices
	Container();
	~Container() { Clear(); }
};

#endif

