#include "Card.h"

void Card::setKartTuru(kartTuru KartTuru) {
    this->KartTuru = KartTuru;
}

kartTuru Card::getKartTuru() {
    return KartTuru;
}

void Card::setBakiye(int bakiye) {
    this->bakiye = bakiye;
}

int Card::getBakiye() {
    return this->bakiye;
}

Card::Card() {
}
Card::Card(kartTuru KartTuru,int bakiye)
{
	this->bakiye = bakiye;
	this->KartTuru = KartTuru;
}
Card Card::operator+(const Card & b) {
    Card card(this->KartTuru, this->bakiye + b.bakiye);
    return card;
}