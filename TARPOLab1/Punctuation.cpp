#include "Wisdom.h"
#include "Riddle.h"
#include "Proverb.h"
#include "Aphorism.h"
#include "Container.h"

//------------------------------------------------------------------------------
int CountingMarks(string a);
// Вычисление 
int Punctuation(Wisdom* w) {
	Riddle* r = nullptr;
	Proverb* p = nullptr;
	Aphorism* a = nullptr;

	if ((r = dynamic_cast<Riddle*>(w)) != nullptr) {
		return CountingMarks(r->riddle);
	}
	else if ((p = dynamic_cast<Proverb*>(w)) != nullptr) {
		return CountingMarks(p->text);
	}
	else if ((a = dynamic_cast<Aphorism*>(w)) != nullptr) {
		return CountingMarks(a->text);
	}
	else {
		return 0;
	}
}

//------------------------------------------------------------------------------
 int CountingMarks(string a) {
	int arr[8]{ 0 };
	for (auto sym : a) {
		switch (sym) {
		case '.': ++arr[0]; break;
		case '?': ++arr[1]; break;
		case '!': ++arr[2]; break;
		case '-': ++arr[4]; break;
		case ';': ++arr[5]; break;
		case ':': ++arr[6]; break;
		case '"': ++arr[7]; break;
		}
	};
	int result = 0;
	for (int i = 0; i < 8; i++) {
		result = result + arr[i];
	};
	if (arr[7] != 0)
		return result - (1 * arr[7]);
	else 
		return result;
}

void NumberOfSigns(Container* c, ofstream& ofst) {
	/*for (int i = 0; i < c->len; i++) {
		ofst << i << ": Number of signs = " << Punctuation(c->cont[i]) << endl;
	}*/

	for (int i = 0; i < c->len; i++)
	{
		if (c->cont[i])
		{
			ofst << i << ": Number of signs = " << Punctuation(c->cont[i]) << endl;
			Wisdom* pt = c->cont[i]->next;
			while (pt)
			{
				ofst << i << ": Number of signs = " << Punctuation(pt) << endl;
				pt = pt->next;
			}
		}
	}
}