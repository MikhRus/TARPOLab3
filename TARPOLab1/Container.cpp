//------------------------------------------------------------------------------
// container.cpp - contains an implementation of the methods of the Container class
//------------------------------------------------------------------------------

#include "Container.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

Container::Container() :key(0)
{
	for (int i = 0; i < len; i++)
	{
		cont[i] = nullptr;
	}
}

//------------------------------------------------------------------------------
// clearing the container of elements
void Container::Clear()
{
	for (int i = 0; i < len ; i++)
	{
		if (cont[i])
		{
			Wisdom *pt = cont[i], *tmp;
			do
			{
				tmp = pt->next;
				delete pt;
				
				pt = tmp;
			} while (pt);
			cont[i] = nullptr;
		}
	}
}
//------------------------------------------------------------------------------

int Container::hash_func(int k)
{
	return key % Container::len;
}
//------------------------------------------------------------------------------

void Container::In(ifstream& ifst) {
	Wisdom *pt;
	
	while (!ifst.eof())
	{
		if ((pt = WisdomFactory::In(ifst)) != 0)
		{
			pt->next = *(cont + hash_func(key));
			*(cont + hash_func(key)) = pt;
			key++;
			cout << "Input Value" << endl; 
		}
	}
}

//------------------------------------------------------------------------------

void Container::Out(ofstream & ofst)
{
	ofst << "=====" << endl << "Container contents " << len << " elements." << endl << "=====" << endl;
	for (int i = 0; i < len; i++)
	{
		if (cont[i])
		{
			ofst << "key " << i << ": " << endl << "-----" << endl;
			cont[i]->Out(ofst);
			Wisdom *pt = cont[i]->next;
			while (pt)
			{
				pt->Out(ofst);
				pt = pt->next;
			}
		}
	}
}
