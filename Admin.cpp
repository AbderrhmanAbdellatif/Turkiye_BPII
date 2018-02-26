#include "Admin.h"
int Admin::kisiBul(int tcNo, Person *personel[]) {
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (tcNo == personel[i]->getTc()) {
            break;
        }
    }
    if (i == 10) {
        i = 0;
        return i;
    } else {
        return i;
    }
}
void Admin::kullaniciOlustur(Person *p, kartTuru kartTuru, Person *personel[]) {
    int i = kisiBul(p->getTc(), personel);
    if (i != 0) {
        cout << "Bu TC'numarasına bağlı bir kullancı daha önce mevcuttur.. TC numarasını kontrol edin" << endl;
    } else {
        int y = 0;
        int x = 0;
        for (y = 0; y < (sizeof (personel) / sizeof (*personel)); y++) {
            if (personel[i]->getIsim() == NULL && personel[i]->getKisiTuru() == user) {
                x = 1;
                break;
            }
        }
        if (x == 1) {
            ((Card *) personel[y])->setKartTuru(kartTuru);
            ((User *) personel[y])->kullaniciKart1.setBakiye(0);
            ((User *) personel[y])->kullaniciKart2.setBakiye(0);

            personel[y] = p;
        } else {
            ((Card *) personel[sayac])->setKartTuru(kartTuru);
            ((User *) personel[sayac])->kullaniciKart1.setBakiye(0);
            ((User *) personel[sayac])->kullaniciKart2.setBakiye(0);
            personel[sayac++] = p;
            cout << " Kullancı oluşturulmuştur.." << endl;

        }
        cout << " Kullancı oluşturulmuştur.." << endl;
    }

}

void Admin::kullaniciSil(int tcNo, Person *personel[]) {
    int i = kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {
        personel[i]->setIsim(NULL);
        personel[i]->setSoyisim(NULL);
        personel[i]->setTc(0);
        personel[i]->setKisiTuru(user);
        cout << "Silme işlemi tamamlanmıştır.." << endl;
    }
}
void Admin::kisiDurumunuGoster(int tcNo, Person *personel[]) {
    int i = kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {
        cout << "Kişinin durumu:" << endl;

        cout << "ismi: " << personel[i]->getIsim() << " " << personel[i]->getSoyisim() << endl;
        cout << "TC: " << personel[i]->getTc() << endl;

        cout << "Türü: ";
        switch (personel[i]->getKisiTuru()) {
            case admin: std::cout << "Admin\n";
                break;
            case user: std::cout << "User\n";
                break;
        }
        cout << "Kart tipi: ";
        switch (((Card *) personel[i])-> getKartTuru()) {
            case Normal: std::cout << "Normal\n";
                break;
            case Ogrenci: std::cout << "Öğrenci\n";
                break;
            case Emekli: std::cout << "Emekli\n";
                break;
        }
    }
}
void Admin::kullaniciKartlariniBirlestir(int tcNo, Person * personel[]) {
    int i = kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {
        ((User *) personel[i])->kullaniciKart1 = ((User *) personel[i])->kullaniciKart1 + ((User *) personel[i])->kullaniciKart2;
        ((User *) personel[i])->kullaniciKart2.setBakiye(0);

        cout << "Kullanıcı kartları birleştirilmiştir..." << endl;
    }

}
void Admin::isimSoyisimDegistir(int tcNo, const char *isim, const char *soyisim, Person * personel[]) {
    int i = kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {
        personel[i]->setIsim(isim);
        personel[i]->setSoyisim(soyisim);
        cout << "İsim soyisim değiştirilmiştir..." << endl;
    }
}
