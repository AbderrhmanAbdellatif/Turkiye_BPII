#include "Admin.h"
#include "User.h"

void User::bakiyeYukle(int tcNo, Person *personel[]) {
    Admin* a = new Admin();
    int i = a->kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {
        int miktar1 = 0, miktar2 = 0;
        cout << "kart 1'e yüklemek istediğiniz miktarı girin: " << endl;
        cin>>miktar1;
        cout << "kart 2'e yüklemek istediğiniz miktarı girin: " << endl;
        cin>>miktar2;

        ((User *) personel[i])->kullaniciKart1.setBakiye(miktar1 + ((User *) personel[i])->kullaniciKart1.getBakiye());
        ((User *) personel[i])->kullaniciKart2.setBakiye(miktar2 + ((User *) personel[i])->kullaniciKart2.getBakiye());
    }
}

void User::kartOkut(int tcNo, Person *personel[]) {
    Admin* a = new Admin();
    int i = a->kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {//  Normal=-2000,Student=-1000,Retired=-0
       

        int kart = 0;
        cout << "kart 1'i mi okutacaksınız kart 2'i mi ((1) yada (2) yazin)" << endl;
        cin>>kart;

        kartTuru kT = ((User *) personel[i])->kullaniciKart1.getKartTuru();
        double kalanBakiye1 = ((User *) personel[i])->kullaniciKart1.getBakiye();
        double kalanBakiye2 = ((User *) personel[i])->kullaniciKart2.getBakiye();

        if (kart == 1) {
            if (kT == Normal) {
                if (kalanBakiye1 < 2000) {
                    cout << "kart 1'deki bakiyeniz yetersizdir, kalan bakiyeniz: " << kalanBakiye1 << endl;
                } else {
                    ((User *) personel[i])->kullaniciKart1.setBakiye(kalanBakiye1 - 2000);
                }
            } else if (kT == Ogrenci) {
                if (kalanBakiye1 < 1000) {
                    cout << "kart 1'deki bakiyeniz yetersizdir, kalan bakiyeniz: " << kalanBakiye1 << endl;
                } else {
                    ((User *) personel[i])->kullaniciKart1.setBakiye(kalanBakiye1 - 1000);
                }
            }
        } else if (kart == 2) {
            if (kT == Normal) {
                if (kalanBakiye2 < 2000) {
                    cout << "kart 2'deki bakiyeniz yetersizdir, kalan bakiyeniz: " << kalanBakiye2 << endl;
                } else {
                    ((User *) personel[i])->kullaniciKart2.setBakiye(kalanBakiye2 - 2000);

                }
            } else if (kT == Ogrenci) {
                if (kalanBakiye2 < 1000) {
                    cout << "kart 2'deki bakiyeniz yetersizdir, kalan bakiyeniz: " << kalanBakiye2 << endl;
                } else {
                    ((User *) personel[i])->kullaniciKart2.setBakiye(kalanBakiye2 - 1000);

                }
            }

        } else {
            cout << "Lütfen sadece (1) yazda (2) yazın" << endl;

        }

    }
}

void User::kartDurumunuGoster(int tcNo, Person *personel[]) {
    Admin* a = new Admin();

    int i = a->kisiBul(tcNo, personel);
    if (i == 0) {
        cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
    } else {

        cout << "Kartın türü: ";
        switch (((Card *) personel[i])->getKartTuru()) {
            case Normal: std::cout << "Normal\n";
                break;
            case Ogrenci: std::cout << "Öğrenci\n";
                break;
            case Emekli: std::cout << "Emekli\n";
                break;
        }
        cout << "Kart 1'de kalan bakiye: " << ((User *) personel[i])->kullaniciKart1.getBakiye() << endl;
        cout << "Kart 2'de kalan bakiye: " << ((User *) personel[i])->kullaniciKart2.getBakiye() << endl;

    }



}