/****************************************************************************
**					      SAKARYA ÜNÝVERSÝTESÝ
**				BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				      BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				     NESNEYE DAYALI PROGRAMLAMA DERSÝ
**					     2019-2020 YAZ DÖNEMÝ
**
**				ÖDEV NUMARASI..........:Prpgramlamaya Giriþ Proje Ödevi
**				ÖÐRENCÝ ADI............:FATÝH DURMAZ
**				ÖÐRENCÝ NUMARASI.......:G191210064
**              DERSÝN ALINDIÐI GRUP...:1/A
****************************************************************************/

#include <fstream> 
#include <iostream> 
#include <stdio.h> 
#include <string>

using namespace std;

int main()
{
    //urun.txt 
    int urunNo;
    int birim;
    double birimFiyati;
    string urunAdi;
    string urunMarkasi;
    string urunKullanimi;

    //proje.txt
    int projeNo;
    string projeAdi;
    string yurutucuFirma;
    string projeSorumlusu;
    string projeKontroloru;

    //hakkedis.txt
    string hakkedisDurumu;
    int urunHakkedisDonemi;
    int projeHakkedisDonemi;
    int aylikHakkedisTutari;

    int secim;
    char islem;
    char cevap = 'e';

    do {
        cout << "\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << " =- PROJE HAKKEDIS ISLEMLERI PROGRAMI -=" << endl;
        cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

        cout << "\n 1) Urun islemleri" << endl;
        cout << "\n 2) Proje islemleri" << endl;
        cout << "\n 3) Hakkedis islemleri" << endl;
        cout << "\n 4) Cikis" << endl;
        cout << "\n Seciminiz: "; cin >> secim;

        if (secim < 1 || secim > 4)
        {
            cout << "\n !!! Lutfen 1, 2, 3  veya 4'ü seciniz !!!" << endl;
        }

        switch (secim)
        {
        case 1:
            system("cls");
            int urunIslem;

            do {
                cout << "\n ---------- URUN ISLEMLERI ----------" << endl;
                cout << "\n 1) Urun ekleme" << endl;
                cout << "\n 2) Urun silme" << endl;
                cout << "\n 3) Urun arama" << endl;
                cout << "\n 4) Raporlama" << endl;
                cout << "\n Seciminiz: "; cin >> urunIslem;

                if (urunIslem < 1 || urunIslem > 4)
                {
                    cout << "\n !!! Lutfen 4 secenekten birini seciniz !!!" << endl;
                }

            } while (urunIslem != 1 && urunIslem != 2 && urunIslem != 3 && urunIslem != 4);

            if (urunIslem == 1)
            {
                system("cls");
                cout << "\n ********** URUN EKLEME **********" << endl;

                ofstream DosyaYaz;
                DosyaYaz.open("urun.txt", ios::app);

                do {
                    cout << "\n===== Eklenen Urun Bilgileri =====" << endl;
                    cout << "\n Urun No              :"; cin >> urunNo;
                    cout << "\n Urunun Birimi        :"; cin >> birim;
                    cout << "\n Urunun Birim Fiyati  :"; cin >> birimFiyati;
                    cout << "\n Urunun Adi           :"; cin >> urunAdi;
                    cout << "\n Urunun Markasi       :"; cin >> urunMarkasi;
                    cout << "\n Urun Kullanimi       :"; cin >> urunKullanimi;
                    cout << "\n Urun Hakkedis Donemi :"; cin >> urunHakkedisDonemi;
                    cout << "\n==================================" << endl;

                    DosyaYaz << urunNo << ' ' << birim << ' ' << birimFiyati << ' ' << urunAdi << ' ' << urunMarkasi << ' ' << urunKullanimi << ' ' << urunHakkedisDonemi << endl;
                    cout << "\n Baska urun kayidi yapacak misin? (e/E) (h/H) "; cin >> cevap;

                } while (!(cevap == 'h'));

                cout << "\n Kayit Isleminiz Gerceklesmistir..." << endl;
                DosyaYaz.close();
            }

            else if (urunIslem == 2)
            {
                system("cls");
                int silinecekUrunNo;

                cout << "\n ********** URUN SILME **********" << endl;
                cout << "\n Silinecek urunun numarasini giriniz(1-15 arasinda) :"; cin >> silinecekUrunNo;

                ifstream DosyaOku("urun.txt");
                ofstream DosyaYaz("gecici_1.tmp");

                while (!DosyaOku.eof())
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunNo == silinecekUrunNo)
                    {
                        cout << "\n===== Silinen Urun Bilgileri =====" << endl;
                        cout << "\n Urun No              :" << urunNo << endl;
                        cout << "\n Urunun Birimi        :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati  :" << birimFiyati << endl;
                        cout << "\n Urunun Adi           :" << urunAdi << endl;
                        cout << "\n Urunun Markasi       :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi       :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi :" << urunHakkedisDonemi << endl;
                        cout << "\n==================================" << endl;

                        cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
                    }
                    else
                    {
                        DosyaYaz << "\n" << urunNo << ' ' << birim << ' ' << birimFiyati << ' ' << urunAdi << ' ' << urunMarkasi << ' ' << urunKullanimi << ' ' << urunHakkedisDonemi;
                    }
                }

                DosyaOku.close();
                DosyaYaz.close();
      
                remove("urun.txt");
                rename("gecici_1.tmp","urun.txt");
            }

            else if (urunIslem == 3)
            {
                system("cls");
                int aranacakUrunNo;
                int gecici = 0;

                cout << "\n ********** URUN ARAMA **********" << endl;
                cout << "\n Aranacak urunun numarasini giriniz(1-15 arasinda) :"; cin >> aranacakUrunNo;

                ifstream DosyaOku("urun.txt");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunNo == aranacakUrunNo)
                    {
                        cout << "\n===== Aranan Urun Bilgileri =====" << endl;
                        cout << "\n Urun No              :" << urunNo << endl;
                        cout << "\n Urunun Birimi        :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati  :" << birimFiyati << endl;
                        cout << "\n Urunun Adi           :" << urunAdi << endl;
                        cout << "\n Urunun Markasi       :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi       :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi :" << urunHakkedisDonemi << endl;
                        cout << "\n=================================" << endl;

                        cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
                        DosyaOku.close();
                        gecici = 1;
                        break;
                    }
                }

                if (gecici == 0)
                {
                    cout << "\n Urun Kayidi Bulunmamaktadir..." << endl;
                }
            }

            else if (urunIslem == 4)
            {
                system("cls");
                int raporFiyat;
                int gecici = 0;

                cout << "\n ********** RAPORLAMA **********" << endl;
                cout << "\n Raporlanacak urunlerin maksimimum fiyatini giriniz(1-100) :";  cin >> raporFiyat;

                ifstream DosyaOku("urun.Txt");
                cout << endl << raporFiyat << " TL ve ondan ucuz olan urunlerin raporu :" << endl;

                while ((!DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (raporFiyat >= birimFiyati > 0)
                    {
                        cout << "\n===== Raporlanan Urun Bilgileri =====" << endl;
                        cout << "\n Urun No              :" << urunNo << endl;
                        cout << "\n Urunun Birimi        :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati  :" << birimFiyati << endl;
                        cout << "\n Urunun Adi           :" << urunAdi << endl;
                        cout << "\n Urunun Markasi       :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi       :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi :" << urunHakkedisDonemi << endl;
                        cout << "\n=====================================" << endl;

                        gecici = 1;
                    }
                }
                
                if (gecici == 0)
                {
                    cout << "\n Raporlanacak Urun Kayidi Bulunmamaktadir..." << endl;
                }

                else if (gecici == 1)
                {
                    cout << "\n Raporlama Isleminiz Gerceklesmistir..." << endl;
                }

                DosyaOku.close();
            }

            break;

        case 2:
            system("cls");
            int projeIslem;

            do {
                cout << "\n ---------- PROJE ISLEMLERI ----------" << endl;
                cout << "\n 1) Proje ekleme" << endl;
                cout << "\n 2) Proje silme" << endl;
                cout << "\n 3) Proje arama" << endl;
                cout << "\n 4) Raporlama" << endl;
                cout << "\n Seciminiz: "; cin >> projeIslem;

                if (projeIslem < 1 || projeIslem > 4)
                {
                    cout << "\n !!! Lutfen 4 secenekten birini seciniz !!!" << endl;
                }

            } while (projeIslem != 1 && projeIslem != 2 && projeIslem != 3 && projeIslem != 4);

            if (projeIslem == 1)
            {
                system("cls");
                cout << "\n ********** PROJE EKLEME **********" << endl;

                ofstream DosyaYaz;
                DosyaYaz.open("proje.txt", ios::app);

                do {
                    cout << "\n===== Eklenen Proje Bilgileri =====" << endl;
                    cout << "\n Proje No              :"; cin >> projeNo;
                    cout << "\n Projenin Adi          :"; cin >> projeAdi;
                    cout << "\n Proje Yurutucu Firma  :"; cin >> yurutucuFirma;
                    cout << "\n Projenin Sorumlusu    :"; cin >> projeSorumlusu;
                    cout << "\n Projenin Kontroloru   :"; cin >> projeKontroloru;
                    cout << "\n Proje Hakkedis Durumu :"; cin >> hakkedisDurumu;
                    cout << "\n Proje Hakkedis Donemi :"; cin >> projeHakkedisDonemi;
                    cout << "\n Proje Hakkedis Tutari :"; cin >> aylikHakkedisTutari;
                    cout << "\n===================================" << endl;

                    DosyaYaz << projeNo << ' ' << projeAdi << ' ' << yurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << ' ' << hakkedisDurumu << ' ' << projeHakkedisDonemi << ' ' << aylikHakkedisTutari << endl;
                    cout << "\n Baska proje kayidi yapacak misin? (e/E) (h/H) "; cin >> cevap;

                } while (!(cevap == 'h'));

                cout << "\n Kayit Isleminiz Gerceklesmistir..." << endl;
                DosyaYaz.close();
            }

            else if (projeIslem == 2)
            {
                system("cls");
                int silinecekProjeNo;

                cout << "\n ********** PROJE SILME **********" << endl;
                cout << "\n Silinecek projenin numarasini giriniz(1-10 arasinda) :"; cin >> silinecekProjeNo;

                ifstream DosyaOku("proje.txt");
                ofstream DosyaYaz("gecici_2.tmp");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru >> hakkedisDurumu >> projeHakkedisDonemi >> aylikHakkedisTutari;

                    if (projeNo == silinecekProjeNo && hakkedisDurumu == "verilmemis")
                    {
                        cout << "\n===== Silinen Proje Bilgileri =====" << endl;
                        cout << "\n Proje No              :" << projeNo << endl;
                        cout << "\n Projenin Adi          :" << projeAdi << endl;
                        cout << "\n Proje Yurutucu Firma  :" << yurutucuFirma << endl;
                        cout << "\n Projenin Sorumlusu    :" << projeSorumlusu << endl;
                        cout << "\n Projenin Kontroloru   :" << projeKontroloru << endl;
                        cout << "\n Proje Hakkedis Durumu :" << hakkedisDurumu << endl;
                        cout << "\n Proje Hakkedis Donemi :" << projeHakkedisDonemi << endl;
                        cout << "\n Proje Hakkedis Tutari :" << aylikHakkedisTutari << endl;
                        cout << "\n==================================" << endl;

                        cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
                    }
                    
                    else
                    {
                        DosyaYaz << "\n" << projeNo << ' ' << projeAdi << ' ' << yurutucuFirma << ' ' << projeSorumlusu << ' ' << projeKontroloru << ' ' << hakkedisDurumu << ' ' << projeHakkedisDonemi << ' ' << aylikHakkedisTutari;
                    }

                    if (projeNo == silinecekProjeNo && hakkedisDurumu == "verilmis")
                    {
                        cout << "\n Hakkedis verilmisler silinemez. Lutfen tekrar deneyiniz..." << endl;
                    }
                }

                DosyaYaz.close();
                DosyaOku.close();

                remove("proje.txt");
                rename("gecici_2.tmp", "proje.txt");
            }

            else if (projeIslem == 3)
            {
                system("cls");
                int aranacakProjeNo;
                int gecici = 0;

                cout << "\n ********** PROJE ARAMA **********" << endl;
                cout << "\n Aranacak projenin numarasini giriniz(1-10 arasinda) :"; cin >> aranacakProjeNo;

                ifstream DosyaOku("proje.txt");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru >> hakkedisDurumu >> projeHakkedisDonemi >> aylikHakkedisTutari;

                    if (projeNo == aranacakProjeNo)
                    {
                        cout << "\n===== Aranan Proje Bilgileri =====" << endl;
                        cout << "\n Proje No              :" << projeNo << endl;
                        cout << "\n Projenin Adi          :" << projeAdi << endl;
                        cout << "\n Proje Yurutucu Firma  :" << yurutucuFirma << endl;
                        cout << "\n Projenin Sorumlusu    :" << projeSorumlusu << endl;
                        cout << "\n Projenin Kontroloru   :" << projeKontroloru << endl;
                        cout << "\n Proje Hakkedis Durumu :" << hakkedisDurumu << endl;
                        cout << "\n Proje Hakkedis Donemi :" << projeHakkedisDonemi << endl;
                        cout << "\n Proje Hakkedis Tutari :" << aylikHakkedisTutari << endl;
                        cout << "\n==================================" << endl;

                        cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
                        DosyaOku.close();
                        gecici = 1;
                        break;
                    }
                }

                if (gecici == 0)
                {
                    cout << "\n Urun Kayidi Bulunmamaktadir..." << endl;
                }
            }

            else if (projeIslem == 4)
            {
                system("cls");
                int raporHakkedisFiyat;
                int gecici = 0;

                cout << "\n ********** RAPORLAMA **********" << endl;
                cout << "\n Raporlanacak projedeki hakkedis tutarinin maksimimum degerini giriniz(1-1000) :";  cin >> raporHakkedisFiyat;

                ifstream DosyaOku("proje.Txt");
                cout << endl << raporHakkedisFiyat << " TL ve ondan ucuz olan aylik hakkedislerin raporu :" << endl;

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru >> hakkedisDurumu >> projeHakkedisDonemi >> aylikHakkedisTutari;

                    if (raporHakkedisFiyat >= aylikHakkedisTutari > 0)
                    {
                        cout << "\n===== Raporlanan Proje Bilgileri =====" << endl;
                        cout << "\n Proje No              :" << projeNo << endl;
                        cout << "\n Projenin Adi          :" << projeAdi << endl;
                        cout << "\n Proje Yurutucu Firma  :" << yurutucuFirma << endl;
                        cout << "\n Projenin Sorumlusu    :" << projeSorumlusu << endl;
                        cout << "\n Projenin Kontroloru   :" << projeKontroloru << endl;
                        cout << "\n Proje Hakkedis Durumu :" << hakkedisDurumu << endl;
                        cout << "\n Proje Hakkedis Donemi :" << projeHakkedisDonemi << endl;
                        cout << "\n Proje Hakkedis Tutari :" << aylikHakkedisTutari << endl;
                        cout << "\n==================================" << endl;

                        gecici = 1;
                    }
                }

                if (gecici == 0)
                {
                    cout << "\n Raporlanacak proje Kayidi Bulunmamaktadir..." << endl;
                }

                else if (gecici == 1)
                {
                    cout << "\n Raporlama Isleminiz Gerceklesmistir..." << endl;
                }

                DosyaOku.close();
            }

            break;

        case 3:
            system("cls");
            int hakkedisIslem;

            do {
                cout << "\n ---------- HAKKEDIS ISLEMLERI ----------" << endl;
                cout << "\n 1) Kullanilan urunleri silme" << endl;
                cout << "\n 2) Kullanilan urunleri listeleme" << endl;
                cout << "\n 3) Kullanilan urunleri arama" << endl;
                cout << "\n 4) Proje icin hakkedis doneminde kullanilan urunlerin listesi ve toplam tutar raporlama" << endl;
                cout << "\n 5) Kayitli projelerin belirtilen donem icin hakkedis tutarlarini raporlama" << endl;
                cout << "\n Seciminiz: "; cin >> hakkedisIslem;

                if (hakkedisIslem < 1 || hakkedisIslem > 5)
                {
                    cout << "\n !!! Lutfen 4 secenekten birini seciniz !!!" << endl;
                }

            } while (hakkedisIslem != 1 && hakkedisIslem != 2 && hakkedisIslem != 3 && hakkedisIslem != 4 && hakkedisIslem != 5);

            if (hakkedisIslem == 1)
            {
                system("cls");
                int kullanilmisUrunNo;

                cout << "\n ********** KULLANILMIS URUN SILME **********" << endl;
                cout << "\n Silinecek urunun numarasini giriniz(1-15 arasinda) :"; cin >> kullanilmisUrunNo;

                ifstream DosyaOku("urun.txt"); 
                ofstream DosyaYaz("gecici_3.tmp");
             
                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunNo == kullanilmisUrunNo && urunKullanimi == "kullanilmis")
                    {
                        cout << "\n===== Silinen Urun Bilgileri =====" << endl;
                        cout << "\n Urun No               :" << urunNo << endl;
                        cout << "\n Urunun Birimi         :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati   :" << birimFiyati << endl;
                        cout << "\n Urunun Adi            :" << urunAdi << endl;
                        cout << "\n Urunun Markasi        :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi        :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi  :" << urunHakkedisDonemi << endl;
                        cout << "\n==================================" << endl;

                        cout << "\n Silme Isleminiz Gerceklesmistir..." << endl;
                    }

                    else
                    {
                        DosyaYaz << "\n" << urunNo << ' ' << birim << ' ' << birimFiyati << ' ' << urunAdi << ' ' << urunMarkasi << ' ' << urunKullanimi << ' ' << urunHakkedisDonemi;
                    }

                    if (urunNo == kullanilmisUrunNo && urunKullanimi == "kullanilmamis")
                    {
                        cout << "\n Kullanilmamis urun sectiniz. Lutfen tekrar deneyiniz..." << endl;
                    }
                }

                DosyaOku.close();
                DosyaYaz.close();

                remove("urun.txt");
                rename("gecici_3.tmp", "urun.txt");
            }

            else if (hakkedisIslem == 2)
            {
                system("cls");
                int gecici = 0;

                cout << "\n ********** KULLANILMIS URUN LISTELEME **********" << endl;
               
                ifstream DosyaOku("urun.txt");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunKullanimi == "kullanilmis")
                    {
                        cout << "\n===== Kullanilan Urun Bilgileri =====" << endl;
                        cout << "\n Urun No               :" << urunNo << endl;
                        cout << "\n Urunun Birimi         :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati   :" << birimFiyati << endl;
                        cout << "\n Urunun Adi            :" << urunAdi << endl;
                        cout << "\n Urunun Markasi        :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi        :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi  :" << urunHakkedisDonemi << endl;
                        cout << "\n=================================" << endl;
                        
                        gecici = 1;
                    }
                }

                if (gecici == 0)
                {
                    cout << "\n Kullanilmis Urun Kayidi Bulunmamaktadir..." << endl;
                }

                cout << "\n Listeleme Isleminiz Gerceklesmistir..." << endl;
                DosyaOku.close();
            }

            else if (hakkedisIslem == 3)
            {
                system("cls");
                int aranacakUrunNo;
                int gecici = 0;

                cout << "\n ********** KULLANILMIS URUN ARAMA **********" << endl;
                cout << "\n Aranacak urunun(kullanilmis) numarasini giriniz :"; cin >> aranacakUrunNo;

                ifstream DosyaOku("urun.txt");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunNo == aranacakUrunNo && urunKullanimi == "kullanilmis")
                    {
                        cout << "\n===== Aranan Urun Bilgileri =====" << endl;
                        cout << "\n Urun No               :" << urunNo << endl;
                        cout << "\n Urunun Birimi         :" << birim << endl;
                        cout << "\n Urunun Birim Fiyati   :" << birimFiyati << endl;
                        cout << "\n Urunun Adi            :" << urunAdi << endl;
                        cout << "\n Urunun Markasi        :" << urunMarkasi << endl;
                        cout << "\n Urun Kullanimi        :" << urunKullanimi << endl;
                        cout << "\n Urun Hakkedis Donemi  :" << urunHakkedisDonemi << endl;
                        cout << "\n=================================" << endl;

                        cout << "\n Arama Isleminiz Gerceklesmistir..." << endl;
                        DosyaOku.close();
                        gecici = 1;
                        break;
                    }
                }

                if (gecici == 0)
                {
                    cout << "\n Kullanilmis Urun Kayidi Bulunmamaktadir..." << endl;
                }
            }

            else if (hakkedisIslem == 4)
            {
                system("cls");
                int raporlanacakDonem_1;
                int toplamTutar = 0;

                cout << "\n ********** KULLANILMIS URUNLERI LISTELEME ve URUNLERIN TOPLAM TUTARI **********" << endl;
                cout << "\n Raporlamak istediginiz hakkedis donemini giriniz (1,2 veya 3) :"; cin >> raporlanacakDonem_1;

                ifstream DosyaOku("urun.txt");
                ofstream DosyaYaz("hakkedis.txt");
               
                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> urunNo >> birim >> birimFiyati >> urunAdi >> urunMarkasi >> urunKullanimi >> urunHakkedisDonemi;

                    if (urunHakkedisDonemi == raporlanacakDonem_1 && urunKullanimi == "kullanilmis")
                    {
                        DosyaYaz << "\n===== Belirtilen Donemdeki Kullanilan Urun Bilgileri =====" << endl;
                        DosyaYaz << "\n Urun No               :" << urunNo << endl;
                        DosyaYaz << "\n Urunun Birimi         :" << birim << "adet" << endl;
                        DosyaYaz << "\n Urunun Birim Fiyati   :" << birimFiyati << " TL" << endl;
                        DosyaYaz << "\n Urunun Adi            :" << urunAdi << endl;
                        DosyaYaz << "\n Urunun Markasi        :" << urunMarkasi << endl;
                        DosyaYaz << "\n Urun Kullanimi        :" << urunKullanimi << endl;
                        DosyaYaz << "\n Urun Hakkedis Donemi  :" << urunHakkedisDonemi << ". donem" << endl;
                        DosyaYaz << "\n==========================================================" << endl;

                        toplamTutar += birimFiyati;
                    }
                }

                DosyaYaz << "\n*****************************************************************" << endl;
                DosyaYaz << "\n Hakkedis Doneminde Kullanilan Urunlerin Toplam Tutarý  :" << toplamTutar << "TL" << endl;
                DosyaYaz << "\n*****************************************************************" << endl;

                cout << "\n -----------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n Toplam Tutar Hesabi ve Listeleme Isleminiz Gerceklesmistir. Hakkedis.txt Dosyasini Kontrol Edebilirsiniz..." << endl;
                cout << "\n -----------------------------------------------------------------------------------------------------------" << endl;

                DosyaOku.close();
                DosyaYaz.close();
            }

            else if (hakkedisIslem == 5)
            {
                system("cls");
                int raporlanacakDonem_2;
                int aylikHakkedisToplami = 0;

                cout << "\n ********** BELIRTILEN DONEM ICIN HAKKEDIS TUTARLARI ve TOPLAMLARI **********" << endl;
                cout << "\n Raporlamak istediginiz hakkedis donemini giriniz (1,2 veya 3) :"; cin >> raporlanacakDonem_2;

                ifstream DosyaOku("proje.txt");
                ofstream DosyaYaz("hakkedis.txt");

                while (!(DosyaOku.eof()))
                {
                    DosyaOku >> projeNo >> projeAdi >> yurutucuFirma >> projeSorumlusu >> projeKontroloru >> hakkedisDurumu >> projeHakkedisDonemi >> aylikHakkedisTutari;

                    if (projeHakkedisDonemi == raporlanacakDonem_2 && hakkedisDurumu == "verilmis")
                    {
                        DosyaYaz << "\n===== Belirtilen Donemdeki Proje Bilgileri =====" << endl;
                        DosyaYaz << "\n Proje No              :" << projeNo << endl;
                        DosyaYaz << "\n Projenin Adi          :" << projeAdi << endl;
                        DosyaYaz << "\n Proje Yurutucu Firma  :" << yurutucuFirma << endl;
                        DosyaYaz << "\n Projenin Sorumlusu    :" << projeSorumlusu << endl;
                        DosyaYaz << "\n Projenin Kontroloru   :" << projeKontroloru << endl;
                        DosyaYaz << "\n Proje Hakkedis Durumu :" << hakkedisDurumu << endl;
                        DosyaYaz << "\n Proje Hakkedis Donemi :" << projeHakkedisDonemi << ". donem" << endl;
                        DosyaYaz << "\n Proje Hakkedis Tutari :" << aylikHakkedisTutari << " TL" << endl;
                        DosyaYaz << "\n================================================" << endl;

                        aylikHakkedisToplami += aylikHakkedisTutari;
                    }
                }

                DosyaYaz << "\n*****************************************************************" << endl;
                DosyaYaz << "\n Hakkedis Doneminde Kullanilan Urunlerin Toplam Tutarý  :" << aylikHakkedisToplami << "TL" << endl;
                DosyaYaz << "\n*****************************************************************" << endl;

                cout << "\n -----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n Aylik Hakkedis Toplami ve Projelerin Hakkedis Tutarlari Raporlanmistir. Hakkedis.txt Dosyasini Kontrol Edebilirsiniz..." << endl;
                cout << "\n -----------------------------------------------------------------------------------------------------------------------" << endl;

                DosyaOku.close();
                DosyaYaz.close();
            }

            break;

        case 4:
            exit(0);
        }

        cout << "\n Programi kullanmaya devam etmek istiyor musunuz? (e/E) (h/H)"; cin >> islem;
        system("cls");
        
    } while (islem == 'e' || islem == 'E');
}