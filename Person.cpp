#include "Person.h"
Person::Person(const char *isim, const char *soyisim, int tcNo, kisiTuru KisiTuru)
: isim(isim), soyisim(soyisim), tcNo(tcNo), KisiTuru(KisiTuru) {
}
Person::Person()
{
}
void Person::setIsim(const char *isim) {
    this->isim = isim;
}

const char* Person::getIsim() {
    return this->isim;
}

void Person::setSoyisim(const char *soyisim) {
    this->soyisim = soyisim;
}

const char* Person::getSoyisim() {
    return this->soyisim;
}
void Person::setTc(int tcNo) {
    this->tcNo=tcNo;
}
int Person::getTc() {
    return tcNo;
}

void Person::setKisiTuru(kisiTuru KisiTuru) {
    this->KisiTuru = KisiTuru;
}

kisiTuru Person::getKisiTuru() {
    return KisiTuru;
}
