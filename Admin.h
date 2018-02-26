#include "Person.h"
#include "User.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;
#ifndef ADMIN_H
#define	ADMIN_H
static int sayac = 0;
class Admin : public Person {
public:
    int kisiBul(int tcNo,Person *personel[]);
    void kullaniciOlustur(Person *p, kartTuru kartTuru,Person *personel[]);
    void kullaniciSil(int tcNo,Person *personel[]);
    void kisiDurumunuGoster(int tcNo,Person *personel[]);
    void kullaniciDurumunuGoster(int tcNo,Person *personel[]);
    void kullaniciKartlariniBirlestir(int tcNo,Person *personel[]);
    void isimSoyisimDegistir(int tcNo, const char *isim, const char *soyisim,Person *personel[]);
};

#endif	/* ADMIN_H */

