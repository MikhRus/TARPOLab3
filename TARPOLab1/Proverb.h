#ifndef __Proverb__
#define __Proverb__

//------------------------------------------------------------------------------
// Rectangle.h - содержит описание класса прямоугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

#include "Wisdom.h"

//------------------------------------------------------------------------------
// прямоугольник
class Proverb : public Wisdom
{
public:
	string country, text; // ширина, высота
	// переопределяем интерфейс класса
	void InData(ifstream& ifst);  // ввод данных из потока
	void Out(ofstream& ofst);     // вывод данных в стандартный поток

	// создание без инициализации.
	Proverb() {}
};

class ProverbFactory : public WisdomFactory {
public:
	// Конструктор фабрики, устанавливющий признак прямоугольника (равен 1)
	ProverbFactory() :WisdomFactory(2) { }

	// Переопределение метода Create на создание прямоугольников.
	Wisdom* Create(int key) {
		if (key == mark)
			return new Proverb;
		else
			return nullptr;
	}
};

#endif
