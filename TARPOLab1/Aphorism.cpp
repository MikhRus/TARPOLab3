#include "Aphorism.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника
void Aphorism::InData(ifstream& ifst) {
	ifst >> author >> text;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника
void Aphorism::Out(ofstream& ofst) {
	ofst << "Aphorism. Author: " << author << "; " << text << endl;
}

namespace {
	AphorismFactory af;
}

