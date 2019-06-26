#ifndef __Figure__
#define __Figure__

//------------------------------------------------------------------------------
// Figure.h - содержит описание обобщающей геометрической фигуры,
// являющееся базовыым классом для всех прочих фигур
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

class Wisdom
{
public:

	virtual void InData(ifstream& ifst) = 0;  // ввод данных из потока
	virtual void Out(ofstream& ofst) = 0;     // вывод данных в стандартный поток

	Wisdom *next;
};

class WisdomFactory {
public:
	// Constructor that provides the initial arrangement of elements in the stack and their ranking
	WisdomFactory(int m);

	// Method to bypass the list of registered matrices.
	// Matrices are registered by their specific matrices factories.
	// Matrices factories  are run before the beginning of the main functions of the program.
	// Key is assigned for identify the matrix.
	static Wisdom* Make(int key);

	// Matrix identification, generation and input from the stream
	static Wisdom* In(ifstream& ifst);

	// Create a specific matrix when the key matches.
	virtual Wisdom* Create(int key) = 0;

protected:
	// Attribute for matrix identification.
	int mark;

	// Pointer to the top of the stack of registered matrices factories.
	static WisdomFactory* top;

	// Pointer to the next element of the factories stack. 
	WisdomFactory* next;
};
#endif