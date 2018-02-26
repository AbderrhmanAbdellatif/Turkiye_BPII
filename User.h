#include "Card.h"
#include "Person.h"
#ifndef USER_H
#define	USER_H

class User : public Person {
public:
    Card kullaniciKart1,kullaniciKart2;
    void bakiyeYukle(int tcNo,Person *personel[]);
    void kartOkut(int tcNo,Person *personel[]);
    void kartDurumunuGoster(int tcNo,Person *personel[]);
};

#endif	/* USER_H */

