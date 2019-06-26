//------------------------------------------------------------------------------

#include "Proverb.h"

//------------------------------------------------------------------------------
void Proverb::InData(ifstream& ifst) {
	ifst >> country >> text;
}

void Proverb::Out(ofstream& ofst) {
	ofst << "Proverb. Country: " << country << "; " << text << endl;
}

namespace {
	ProverbFactory pf;
}
