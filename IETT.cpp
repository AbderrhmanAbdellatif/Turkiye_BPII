#include "Admin.h"
void hazirKullaniciEkle();
void programiClaistir();
void adminSecenekleri();
void kullaniciSecenekleri(int tc);
Admin* a = new Admin();
User* u = new User();
static Person *personListesi[10];
int main() {
    for (int i = 0; i < 10; i++) {
        personListesi[i] = new Person();
        personListesi[i]->setTc(0);
    }
    hazirKullaniciEkle();
    system("clear");
    programiClaistir();
    return 0;
}
void programiClaistir() {
    while (true) {
        puts("IETT");
        cout << " 1- " << "Yonetici Islemleri " << endl;
        cout << " 2- " << "Kullanici Islemleri " << endl;
        cout << " 3 - " << "cikis" << endl;
        int secim = 0;
        cin >> secim;
        if (secim == 1) {
            int tcNo;
            cout << "TC girin: " << endl;
            cin >> tcNo;
            int z = 0;
            int x = 0;
            for (x = 0; x < 10; x++) {
                if (personListesi[x]->getTc() == tcNo && personListesi[x]->getKisiTuru() == admin) {
                    z = 1;
                }
            }
            if (z == 1) {
                system("clear");
                adminSecenekleri();
                return;
            } else
              cout << "Öyle bir Admin bulunmamaktadır.. TC numarasını kontrol edin" << endl;
        } else if (secim == 2) {
            int tcNo;
            cout << "TC girin: " << endl;
            cin >> tcNo;
            int z = 0;
            int x = 0;
            for (x = 0; x < (sizeof (personListesi) / sizeof (*personListesi)); x++) {
                if (personListesi[x]->getTc() == tcNo) {
                    z = 1;
                    break;
                }
            }
            if (z == 1) {
                system("clear");
                kullaniciSecenekleri(tcNo);
                return;
            } else
                cout << "Öyle bir Kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
        } else if (secim == 3) {
            cout<<"Kapanıyor..";
            exit(1);
        } else 
            cout << " Lütfen sadece 1-3 arası bir giriş yapın: " << endl;
    }
}
void adminSecenekleri() {
    while (true) {
        cout << " ************************************ " << endl;
        cout << "       1 - Kullanıcı oluştur " << endl;
        cout << "       2- kullanıcı sil " << endl;
        cout << "       3 - kişi durumunmu  göster " << endl;
        cout << "       4- kişi bul  " << endl;
        cout << "       5- kullanıcı kartlarını birleştir  " << endl;
        cout << "       6- isim soyisim değiştir " << endl;
        cout << "       7-Ana Menü  " << endl;
        cout << " ----------------------------------------- " << endl;
        int secim = 0;
        cin>>secim;
        int tcNo;
        int k = 0;
        kartTuru kT = Normal;
        if (secim == 1) {
            int tcNo = 0;
            cout << "TC girin: ";
            cin >> tcNo;
            if (a->kisiBul(tcNo, personListesi) != 0) {
                cout << "Bu TC numarasına bağlı zaten bir kullanıcı mecvcuttur.. TC numarasını kontrol edin" << endl;
            } else {
                char *ad, *soyad;
                cout << "Kullancını adını girin: ";
                cin >> ad;
                cout << "soyadını girin: ";
                cin >> soyad;
                cout << endl << "Kart türünü girin (Normal 1,Ogrenci 2,Emekli 3 : " << endl;
                cin >> k;
                while (true) {
                    if (k == 1) {
                        kT = Normal;
                        break;
                    }
                    if (k == 2) {
                        kT = Ogrenci;

                        break;
                    } else if (k == 3) {
                        kT = Emekli;
                        break;

                    } else {
                        cout << " Lütfen sadece 1-3 arası bir giriş yapın: " << endl;
                        cin>>k;
                    }
                }
                Person* p = new Person(ad, soyad, tcNo, user);
                a->kullaniciOlustur(p, kT, personListesi);
            }
        } else if (secim == 2) {
            int tcNo = 0;
            cout << "TC girin: " << endl;
            cin >> tcNo;
            Admin* a = new Admin();
            a->kullaniciSil(tcNo, personListesi);
        } else if (secim == 3) {
            cout << "TC girin: " << endl;
            cin >> tcNo;
            a->kisiDurumunuGoster(tcNo, personListesi);
        } else if (secim == 4) {
            cout << "TC girin: " << endl;
            cin >> tcNo;
            if (a->kisiBul(tcNo, personListesi) == 0) {
                cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
            } else {
                cout << "bulundu.." << endl;
            }
        } else if (secim == 5) {
            cout << "TC girin: " << endl;
            cin >> tcNo;
            a->kullaniciKartlariniBirlestir(tcNo, personListesi);
        } else if (secim == 6) {
            int tcNo = 0;
            cout << "TC girin: " << endl;
            cin >> tcNo;
            if (a->kisiBul(tcNo, personListesi) == 0) {
                cout << "Öyle bir kullanıcı bulunmamaktadır.. TC numarasını kontrol edin" << endl;
            } else {
                char *isim, *soyisim;
                cout << " İstediğiniz yeni adını girin: " << endl;
                cin >> isim;
                cout << "İstediğiniz yeni soyadını girin: " << endl;
                cin>>soyisim;
                a->isimSoyisimDegistir(tcNo, isim, soyisim, personListesi);
            }
        } else if (secim == 7) {
            system("clear");
            programiClaistir();
            return;
        } else {
            cout << " Lütfen sadece 1-7 arası bir giriş yapın: " << endl;
            cin >> secim;
        }
    }
}
void kullaniciSecenekleri(int tc) {
    int secim = 0;
    while (true) {
        cout << " ************************************ " << endl;
        cout << "       1 -Bakiye Yukle " << endl;
        cout << "       2- Kart  Okut " << endl;
        cout << "       3 - kart Durumunmu  Goster " << endl;
        cout << "       4-Ana Menu  " << endl;
        cout << " ----------------------------------------- " << endl;
        cin >> secim;
        if (secim == 1) {
            system("clear");
            u->bakiyeYukle(tc, personListesi);
        } else if (secim == 2) {
            system("clear");
            u->kartOkut(tc, personListesi);
        } else if (secim == 3) {
            system("clear");
            cout << tc << endl;
            u->kartDurumunuGoster(tc, personListesi);
        } else if (secim == 4) {
            system("clear");
            programiClaistir();
        } else {
            cout << " Lütfen sadece 1-4 arası bir giriş yapın: " << endl;
            cin >> secim;
        }
    }
}
void hazirKullaniciEkle() {
    Person* p = new Person("hakki", "hakli", 1234, admin);
    a->kullaniciOlustur(p, Normal, personListesi);
    Person* np = new Person("selin", "sakli", 4321, user);
    a->kullaniciOlustur(np, Ogrenci, personListesi);
    ((User *) personListesi[1])->kullaniciKart1.setBakiye(1000);
    ((User *) personListesi[1])->kullaniciKart2.setBakiye(200);
}