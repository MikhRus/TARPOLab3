#ifndef __Aphorism__
#define __Aphorism__

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

#include "Wisdom.h"

//------------------------------------------------------------------------------
// прямоугольник
class Aphorism : public Wisdom
{
public:
	string author, text; //
	// переопределяем интерфейс класса
	void InData(ifstream& ifst);  // ввод данных из потока
	void Out(ofstream& ofst);     // вывод данных в стандартный поток

	// создание без инициализации.
	Aphorism() {}
};

class AphorismFactory : public WisdomFactory {
public:
	// Конструктор фабрики, устанавливющий признак  (равен 1)
	AphorismFactory() :WisdomFactory(1) { }

	// Переопределение метода Create на создание.
	Wisdom* Create(int key) {
		if (key == mark)
			return new Aphorism;
		else
			return nullptr;
	}
};
#endif

