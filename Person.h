#include <iostream>
#ifndef PERSON_H
#define	PERSON_H

typedef enum KisiTuru {
    admin, user
} kisiTuru;

class Person {
public:
    Person(const char *isim, const char *soyisim, int tcNo, kisiTuru kisiTuru);
    Person();

    void setIsim(const char *isim);
   const char* getIsim();
    void setSoyisim(const char *soyisim);
   const char* getSoyisim();
    void setTc(int tcNo);
    int getTc();
    void setKisiTuru(kisiTuru KisiTuru);
    kisiTuru getKisiTuru();
private:
   const char *isim, *soyisim;
    int tcNo;
    kisiTuru KisiTuru;

};

#endif	/* PERSON_H */

