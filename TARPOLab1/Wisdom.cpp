// Figure.cpp - Реализация функций, поддерживающих работу с базовой фигурой.
// В основном это функции и данные фабрики абстрактной фигуры.

#include "Wisdom.h"

WisdomFactory* WisdomFactory::top = nullptr;
WisdomFactory::WisdomFactory(int m) : mark(m)
{
	this->next = top;
	top = this;
}

//------------------------------------------------------------------------------

// Matrix identification and generation
Wisdom* WisdomFactory::Make(int key)
{
	Wisdom* f = nullptr;
	WisdomFactory* tmp = top;

	// Bypass the factories in the stack to match the key with the desired
	while (tmp) {
		f = tmp->Create(key);
		if (f) return f;
		tmp = tmp->next;
	}
	return nullptr;
}

//------------------------------------------------------------------------------

// Matrix identification, generation and input from the stream
Wisdom* WisdomFactory::In(ifstream& ifst)
{
	Wisdom* pf = nullptr;
	int k;
	ifst >> k;
	pf = Make(k);
	if (pf)
		pf->InData(ifst);
	return pf;
}