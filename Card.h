#ifndef CARD_H
#define	CARD_H

typedef enum KartTuru {
    Normal, Ogrenci, Emekli
} kartTuru;

class Card {
public:
    Card();
    Card(kartTuru KartTuru, int bakiye);
    Card operator+(const Card& b);

    void setKartTuru(kartTuru KartTuru);
    kartTuru getKartTuru();
    void setBakiye(int bakiye);
    int getBakiye();
private:
    int bakiye;
    kartTuru KartTuru;
};

#endif	/* CARD_H */

