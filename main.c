#include <stdio.h>
#include <stdlib.h>

// genel tanimlamalar
char koyAdi[50];
char ad[50];
char calgiAdi[50];
int altin=10;
int seviye=1;
int tecrube=10;

// temel nitelikler ([0,100)] araliginda olmali
int can = 50;
int tokluk = 50;
int uyku = 50;
int hijyen = 50;
int mutluluk = 50;
int enerji = 50;
int yaraticilik = 50;

// beceriler ([3,25] araliginda olmali
int guc = 3;
int ceviklik = 3;
int dayaniklilik = 3;
int karizma = 3;
int toplayicilik =3 ;

// menü gösterme fonksiyonu
void menuGoster(){
    printf("\n----ANA MENU----\n");
    printf("1. Us merkezine don\n");
    printf("2. Kamp alanina git\n");
    printf("3. Steller Sifa Istasyonu'na git\n");
    printf("4. Hana git\n");
    printf("5. Gezegen kesfet\n");
    printf("6. Sifali bitki topla\n");
    printf("7. Seviye atla\n");
    printf("8. Durumu goster\n");
    printf("9. Oyundan cik\n\n");
}
void usMerkezineDon(){
    int secim;

    printf("\nUs merkezine donuyorsunuz...\n\n");
    printf("\t---Secenekler---\t\n");
    printf(" 1. Ortak alanda calgi cal/ sarki soyle\n");
    printf(" 2. Dus al\n");
    printf(" 3. Odana gidip uyu\n");
    printf(" 4. Koy meydanina don\n\n");
    printf("Us merkezinde yapilacak islemi seciniz: ");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            printf("\nSarki soyluyorsunuz, mutluluk, enerji ve uyku seviyeniz artti!\n");
            // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
            mutluluk = (mutluluk + 5 > 100) ? 100 : mutluluk + 5;
            enerji = (enerji + 5 > 100) ? 100 : enerji + 5;
            uyku = (uyku + 5 > 100) ? 100 : uyku + 5; // sarki söylediginde enerjisi arttigi için uyku degeri artti.
            tokluk = (tokluk - 5 < 0) ? 0 : tokluk - 5;
            hijyen = (hijyen - 5 < 0) ? 0 : hijyen - 5;
            durumGoster();
            canKontrol();
            break;
        case 2:
            printf("\nDus aldiniz, hijyen, mutluluk ve guc seviyeniz artti!\n");
            // temel nitelikler kontrol edilerek arttiriliyor.
            hijyen = (hijyen + 10 > 100) ? 100 : hijyen + 10;
            mutluluk = (mutluluk + 10 > 100) ? 100 : mutluluk + 10; // temizlendigi için mutlu oldu.
            // beceriler kontrol edilerek arttiriliyor.
            guc = (guc++ > 25) ? 25 : guc++;
            durumGoster();
            canKontrol();
            break;
        case 3:
            printf("\nOdaniza gidip dinlendiniz, uyku, enerji ve guc seviyeniz artti!\n");
            // temel nitelikler kontrol edilerek arttiriliyor.
            uyku = (uyku + 15 > 100) ? 100 : uyku + 15;
            enerji = (enerji + 15 > 100) ? 100 : enerji + 15;
            // beceriler kontrol edilerek arttiriliyor. 25'den büyük olmamali.
            guc = (guc + 5 > 25) ? 25 : guc + 5; // dinlendigi için güç topladi.
            durumGoster();
            canKontrol();
            break;
        case 4:
            printf("\nKoy meydanina dondun. 1 tane altin kaybettin. Altin kazanmak icin daha cesur olmalisin!\n");
            altin--; // köy meydanina döndügünde vazgeçtigi için 1 altin kaybeder.
            durumGoster();
            break;
        default:
            printf("\nGecersiz bir secim yaptiniz! Lutfen tekrar deneyiniz.");
            break;
     }
}
void kampAlaninaGit(){
    int secim;

    printf("\n-------Kamp alanina gidildi.-------\n\n");
    printf("\n------ Secenekler ------\n");
    printf(" 1. Kamp atesinin basinda calgi cal/sarki soyle.\n");
    printf(" 2. Nehirde yikan.\n");
    printf(" 3. Cadirina girip uyu.\n");
    printf(" 4. Koy meydanina don.\n\n");
    printf("Kamp alaninda yapilacak islemi seciniz: ");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            printf("\nCalginizi calip sarki soyledin. Karizma, mutluluk, enerji, uyku ve tecrube degerin artti!\n");
            // beceriler kontrol edilerek arttiriyoruz. 25'den büyük olmamali.
            karizma = (karizma++ > 25) ? 25 : karizma++;
            // temel nitelikleri kontrol ederek arttiriyoruz. 100den büyük olmamali.
            mutluluk = (mutluluk + 10 > 100) ? 100 : mutluluk + 10;
            enerji = (enerji + 10 > 100)? 100 : enerji + 10;
            uyku = (uyku + 10 > 100) ? 100 : uyku + 10; // enerjisi arttigi icin uykusu acildi
            tecrube+=30;
            seviyeAtla();
            durumGoster();
            canKontrol();
            break;
        case 2:
            printf("\nNehirde yikandin. Hijyen, mutluluk ve gucun artti!\n");
            // temel nitelikleri kontrol ederek arttiriyoruz. 100den büyük olmamali.
            hijyen= (hijyen + 30 > 100) ? 100 : hijyen + 30;
            mutluluk = (mutluluk + 10 > 100) ? 100 : mutluluk + 10;
            // beceriler kontrol edilerek arttiriyoruz. 25'den büyük olmamali.
            guc = (guc++ > 25) ? 25 : guc++;
            durumGoster();
            canKontrol();
            break;
        case 3:
            printf("\nCadirina girip uyudun. Uyku, enerji, guc ceviklik ve dayaniklilik degerin artti! Artik daha guclu, cevik ve dayanikli bir oyuncusun!\n");
            // temel nitelikleri kontrol ederek arttiriliyor. 100den büyük olmamali.
            uyku = (uyku + 20 > 100) ? 100 : uyku + 20; // uyku deðiþkeninin deðeri karakter uyudugunda artiyor, uykusu geldiginde ise azaliyor.
            enerji = (enerji + 20 > 100)? 100 : enerji + 20;
            // beceriler kontrol edilerek arttiriliyor. 25'den büyük olmamali.
            guc = (guc++ > 25) ? 25 : guc++;
            ceviklik = (ceviklik++ > 25) ? 25 : ceviklik++;
            dayaniklilik = (dayaniklilik++ > 25) ? 25 : dayaniklilik++;
            durumGoster();
            canKontrol();
            break;
        case 4:
            printf("\nKoy meydanina dondun. 1 tane altin kaybettin. Altin kazanmak icin daha cesur olmalisin!\n");
            altin--; // köy meydanina döndügünde vazgeçtigi için 1 altin kaybeder.
            durumGoster();
            break;
        default:
            printf("\nGecersiz bir secim yaptin!\n");
            break;
    }
}
void sifaIstasyonunaGit(){
    int secim;

    printf("\n---Steller sifa istasyonuna gidildi.---\n\n");
    printf("\n--------Secenekler--------\n");
    printf(" 1. Sifacidan yaralarini sarmasini iste.\n");
    printf(" 2. Sifacidan merhem yapip surmesini iste.\n");
    printf(" 3. Kesif sirasinda yaralandin. Ameliyat olman gerekiyor.\n");
    printf(" 4. Gezegenus sifa iksirini ic.\n");
    printf(" 5. Koy meydanina don.\n\n");
    printf("Sifa istasyonunda yapilacak islemi seciniz:");
    scanf("%d",&secim);

    //sifa istasyonunda oyuncunun cani artiyor ve azaliyor
    switch(secim){
    case 1:
        printf("\nSifaci yaralarini sardi! 10 adet can kazandin.\n");
        // temel nitelikler kontrol edilerek arttiriliyor.
        can = (can + 10 > 100) ? 100 : can + 10;
        durumGoster();
        canKontrol();
        break;
    case 2:
        printf("\nSifaci merhemini surdu! 5 adet can kazandin.\n");
        // temel nitelikler kontrol edilerek arttiriliyor.
        can = (can + 5 > 100) ? 100 : can + 5;
        durumGoster();
        canKontrol();
        break;
    case 3:
        printf("\nAmeliyat oldun, cok kan kaybettin. 15 adet canin gitti.\n");
        // temel nitelikler kontrol edilerek arttiriliyor.
        can = (can-15 < 0) ? 0 : can -15;
        durumGoster();
        canKontrol();
        break;
    case 4:
        printf("\nGezegenus sifa iksiri ictin! 7 adet can kazandin.\n");
        // temel nitelikler kontrol edilerek arttiriliyor.
        can = (can + 7 > 100) ? 100 : can + 7;
        durumGoster();
        canKontrol();
        break;
    case 5:
        printf("\nKoy meydanina dondun. 1 tane altin kaybettin. Altin kazanmak icin daha cesur olmalisin!\n");
        altin--;  // köy meydanýna döndüðünde vazgeçtigi için 1 altin kaybeder.
        durumGoster();
        break;
    default:
        printf("\nGecersiz secim yaptin!\n");
        break;
    }
}
void hanaGit(){
    int secim,yemekSecimi,icecekSecimi;

    printf("\nHan'a gidiyorsunuz...\n");
    printf("\n\t---Secenekler---\t\n");
    printf(" 1. Yiyecek satin al ve ye\n");
    printf(" 2. Icecek satin al, ic ve eglen\n");
    printf(" 3. Enstruman cal ve sarki soyle\n");
    printf(" 4. Koy meydanina don\n\n");
    printf("Handa yapilacak islemi seciniz: ");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            printf("\nYiyecekler: \n");
            printf("1. Yahni(5 altin)\n2.Corba(4 altin)\n3.Mevsim Salata(3 altin)\n4.Meyve(1 altin)\n");
            printf("\nHangi yiyecegi alacaginizi seciniz: ");
            scanf("%d",&yemekSecimi);
            // yapilan seçime göre tokluk degeri kontrollü bir sekilde arttiriliyor.
            switch(yemekSecimi){
                case 1:
                    if(altin>=5){
                        printf("\nBu yemegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Yahni yediniz ve tokluk seviyeniz artti, uyku seviyeniz azaldi!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 30 > 100) ? 100 : tokluk + 30;
                        uyku = (uyku - 30 < 0) ? 0 : uyku - 30; // uykusu geldigi için uyku seviyesi azaldi.
                        altin-=5;
                    }
                    else{
                        printf("\nBu yemegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 2:
                    if(altin>=4){
                        printf("\nBu yemegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Corba ictiniz ve tokluk seviyeniz artti, uyku seviyeniz azaldi!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 20 > 100) ? 100 : tokluk + 20;
                        uyku = (uyku - 20 < 0) ? 0 : uyku - 20; // uykusu geldigi için uyku seviyesi azaldi.
                        altin-=4;
                    }
                    else{
                        printf("\nBu yemegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 3:
                    if(altin>=3){
                        printf("\nBu yemegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Mevsim salata yediniz ve tokluk seviyeniz artti, uyku seviyeniz azaldi!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 10 > 100) ? 100 : tokluk + 10;
                        uyku = (uyku - 10 < 0) ? 0 : uyku - 10; // uykusu geldigi için uyku seviyesi azaldi.
                        altin-=3;
                    }
                    else{
                        printf("\nBu yemegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 4:
                    if(altin>=1){
                        printf("\nBu yemegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Meyve yediniz ve tokluk seviyeniz artti, uyku seviyeniz azaldi!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 5 > 100) ? 100 : tokluk + 5;
                        uyku = (uyku - 5 < 0) ? 0 : uyku - 5; // uykusu geldigi için uyku seviyesi azaldi.
                        altin-=1;
                    }
                    else{
                        printf("\nBu yemegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                default:
                    printf("\nGecersiz bir secim yaptiniz! Lutfen tekrar deneyiniz.\n");
                    break;
            }
            durumGoster();
            canKontrol();
            break;
        case 2:
            printf("\nIcecekler: \n");
            printf("1. Ayran(5 altin)\n2.Gazoz(4 altin)\n3.Soda(3 altin)\n4.Su(1 altin)\n");
            printf("\nHangi icecegi alacaginizi seciniz: ");
            scanf("%d",&icecekSecimi);
            switch(icecekSecimi){
                case 1:
                    if(altin>=5){
                        printf("\nBu icecegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Ayran ictiniz ve tokluk seviyeniz artti, uyku seviyeniz azaldi!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 5 > 100) ? 100 : tokluk + 5;
                        uyku = (uyku - 5 < 0) ? 0 : uyku - 5; // uykusu geldigi için uyku seviyesi azaldi.
                        altin-=5;
                    }
                    else{
                        printf("\nBu icecegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 2:
                    if(altin>=4){
                        printf("\nBu icecegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Gazoz ictiniz ve tokluk seviyeniz artti!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 4 > 100) ? 100 : tokluk + 4;
                        altin-=4;
                    }
                    else{
                        printf("\nBu icecegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 3:
                    if(altin>=3){
                        printf("\nBu icecegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Soda ictiniz ve tokluk seviyeniz artti!\n");
                        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 3 > 100) ? 100 : tokluk + 3;
                        altin-=3;
                    }
                    else{
                        printf("\nBu icecegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                case 4:
                    if(altin>=1){
                        printf("\nBu icecegi satin alabilirsiniz. Afiyet olsun!\n");
                        printf("Su ictiniz ve tokluk seviyeniz artti!\n");
                       // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                        tokluk = (tokluk + 1 > 100) ? 100 : tokluk + 1;
                        altin-=1;
                    }
                    else{
                        printf("\nBu icecegi satin alamazsiniz. Altin yetersiz!\n");
                    }
                    break;
                default:
                    printf("\nGecersiz bir secim yaptiniz! Lutfen tekrar deneyiniz.\n");
                    break;
            }
            printf("\nIcecek icerek eglendiniz. Enerjiniz ve mutlulugunuz artti!\n");
            // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
            mutluluk = (mutluluk + 5 > 100) ? 100 : mutluluk + 5;
            enerji = (enerji + 5 > 100) ? 100 : enerji + 5;
            durumGoster();
            canKontrol();
            break;
        case 3:
            if(hijyen<=20){
                printf("\nHanda sarki soyleyemezsiniz. Gidip temizlenin lutfen!\n");
            }
            else{
                printf("\nHanda sarki soyleyip enstruman caldiniz.\n");
                printf("Karizma,altin ve tecrubeniz artti!\n");
                altin+=10+(karizma*hijyen)/100;
                // beceriler kontrol edilerek arttiriliyor.
                karizma = (karizma + 3 > 25) ? 25 : karizma + 3;
                tecrube+=20;
                seviyeAtla();
                durumGoster();
                canKontrol();
            }
            break;
        case 4:
            printf("\nKoy meydanina dondun. 1 tane altin kaybettin. Altin kazanmak icin daha cesur olmalisin!\n");
            altin--;  // köy meydanina döndügünde vazgeçtigi için 1 altin kaybeder.
            durumGoster();
            break;
        default:
            printf("\nGecersiz bir secim yaptiniz! Lutfen tekrar deneyiniz.\n");
            break;
    }
}
void gezegenKesfet(){

    srand(time(NULL));
    int rastgeleSayi,secim,yemeksecimi;

    printf("\n-----Gezegen kesfet secenegi secildi.-----\n");
    printf("\n\t-----Secenekler----\t\n");
    printf(" 1. Gezegenden sifali bitki topla ve avlan.\n");
    printf(" 2. Ugilugi gezegenini kesfet (kolay).\n");
    printf(" 3. Ugilugi gezegenine ev yap (orta).\n");
    printf(" 4. Ugilugi gezegeninde yiyecek bul (zor).\n");
    printf(" 5. Koy meydanina don.\n\n");
    printf("Yapmak istediginiz islemi seciniz: ");
    scanf("%d",&secim);

    switch (secim) {
        case 1:
            sifaliBitkiTopla();
            durumGoster();
            canKontrol();
            break;
        case 2:
            //10 ile 15 arasında rastgele değerler üretilir
            rastgeleSayi = (rand() % 11) + 15;
            printf("\nUgilugi gezegenini kesfettin ve %d altin kazandin! Yaraticilik ve tecrube puanin artti!\n", rastgeleSayi);
            altin += rastgeleSayi;
            yaraticilik= (yaraticilik + 5 > 100) ? 100 : yaraticilik + 5;
            tecrube+=30;
            kolaySavas();// uzaylilar ile savasiliyor
            seviyeAtla();
            durumGoster();
            break;
        case 3:
           //20 ile 30 arasında rastgele değerler üretilir
            rastgeleSayi = (rand() % 21) + 30;
            printf("Ugilugi gezegeninde ev yaptin ve %d altin kazandin. Yararicilik ve tecrube puanin artti! \n", rastgeleSayi);
            altin += rastgeleSayi;
            yaraticilik= (yaraticilik + 10 > 100) ? 100 : yaraticilik + 10;
            tecrube+=60;
            ortaSavas();//uzaylılar ile savaşışıyor
            seviyeAtla();
            durumGoster();
            canKontrol();
            break;
        case 4:
            // 20 ile 55 arasinda rastgele degerler üretilir
            rastgeleSayi = (rand() % 21) + 55;
            printf("\nSecim yap: \n1.Ekmek\n2.Yahni\n3.Elma\n4.Mantar\n");
            scanf("%d",&yemeksecimi);
           //yapılan seçime göre tokluk değeri kontrollü bir şekilde arttırılır
            switch(yemeksecimi){
                case 1:
                    printf("\nUgilugi gezegeninde yiyecek buldun! Tokluk degerin 10 puan artti. Uykusu geldi ve uyku seviyesi azaldi.\n");
                    // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                    tokluk = (tokluk + 10 > 100) ? 100 : tokluk + 10;
                    uyku = (uyku - 10 < 0) ? 0 : uyku - 10; // uykusu geldigi için uyku seviyesi azaldi.
                    break;
                case 2:
                    printf("\nUgilugi gezegeninde yiyecek buldun! Tokluk degerin 50 puan artti.Uykusu geldi ve uyku seviyesi azaldi.\n");
                    // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                    tokluk = (tokluk + 50 > 100) ? 100 : tokluk + 50;
                    uyku = (uyku - 50 < 0) ? 0 : uyku - 50; // uykusu geldigi için uyku seviyesi azaldi.
                    break;
                case 3:
                    printf("\nUgilugi gezegeninde yiyecek buldun! Tokluk degerin 5 puan artti.Uykusu geldi ve uyku seviyesi azaldi.\n");
                    // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
                    tokluk = (tokluk + 5 > 100) ? 100 : tokluk + 5;
                    uyku = (uyku - 5 < 0) ? 0 : uyku - 5; // uykusu geldigi için uyku seviyesi azaldi.
                    break;
                case 4:
                    printf("\nUgilugi gezegeninde yiyecek buldun! Ancak buldugunuz yiyecekler zehirliydi 5 canin gitti.\n");
                    // temel nitelikler kontrol edilerek azaltiliyor.
                    can = (can - 5 < 0) ? 0 : can - 5;
                    break;
                default:
                    printf("\nGecersiz bir secim yaptiniz. Lutfen tekrar deneyiniz!");
            }
            altin += rastgeleSayi;
            tecrube+=90;
            printf("Altin ve tecrube puanin artti.\n");
            printf("\n");
            zorSavas();// uzaylilar ile savasiliyor
            printf("\n");
            seviyeAtla();
            printf("\n");
            durumGoster();
            printf("\n");
            canKontrol();
            break;
        case 5:
            printf("\nKoy meydanina dondun. 1 tane altin kaybettin. Altin kazanmak icin daha cesur olmalisin!\n");
            altin--;  // köy meydanina döndügünde vazgeçtigi için 1 altin kaybeder.
            durumGoster();
            break;
        default:
            printf("\nGezegen kesfedemedin. Tekrar deneyebilirsin.\n");
            break;
    }
}
void sifaliBitkiTopla() {

    srand(time(NULL)); // Rastgelelik için baslangiç
    printf("\n--- Yakin Cevreden Sifali Bitki Toplama ---\n");

    float bitkiSans = toplayicilik * 4; // sifali bitki bulma sansi
    int rastgeleDeger;

    //sifali bitki bulma
    rastgeleDeger = rand() % 101;

    if (rastgeleDeger <= bitkiSans) {
        printf("\nSifali bitki buldunuz! Caniniz 10 artti.\n");
        // temel nitelikler kontrol edilerek arttiriliyor.
        can = (can + 10 > 100) ? 100 : can + 10;
    } else {
        printf("\nSifali bitki bulamadiniz.\n");
    }

    // Meyve toplama
    rastgeleDeger = rand() % 101;
    if (rastgeleDeger <= bitkiSans) {
        printf("\nMeyve buldunuz! Toklugunuz ve uyku degeriniz 10 artti.\n");
        // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
        tokluk = (tokluk + 10 > 100) ? 100 : tokluk + 10;
        uyku = (uyku - 10 < 0) ? 0 : uyku - 10; // uykusu geldigi için uyku seviyesi azaldi.

    } else {
        printf("\nMeyve bulamadiniz.\n");
    }

    // Av hayvani avlama
    rastgeleDeger = rand() % 101;
    if (rastgeleDeger <= (bitkiSans / 2)) {
        printf("\nAv hayvani avladiniz! Toklugunuz ve uyku degeriniz 50 artti.\n");
      // temel nitelikler kontrol edilerek arttirilip azaltiliyor.
        tokluk = (tokluk + 50 > 100) ? 100 : tokluk + 50;
        uyku = (uyku - 50 < 0) ? 0 : uyku - 50; // uykusu geldigi için uyku seviyesi azaldi.
    } else {
        printf("\nAv hayvani avlayamadiniz.\n");
    }
    printf("\n");
}
void seviyeAtla(){

    printf("\nSeviye atlama ekrani...\n");

    if(tecrube>=100){
        printf("\nTebrikler! Seviye atladiniz! Verilen yeni 5 yetenek puaninizi harcayabilirsiniz\n");
        seviye++;
        tecrube=0; // her yeni seviyede tecrube sifirlaniyor.
        // puanlar beceriler arasinda esit bir sekilde paylasiliyor ve beceriler kontrollü bir sekilde arttiriliyor.
        guc = (guc++ > 25) ? 25 : guc++;
        ceviklik = (ceviklik++ > 25) ? 25 : ceviklik++;
        dayaniklilik = (dayaniklilik++ > 25) ? 25 : dayaniklilik++;
        karizma = (karizma++ > 25) ? 25 : karizma++;
        toplayicilik = (toplayicilik++ > 25) ? 25 : toplayicilik++;
        durumGoster();
        // puanlarin hepsinin dogru bir sekilde kullanilip kullanilmayacagi kontrol ediliyor.
        // becerilerin en az degeri, baslangic degerlerine 1 eklenmis halleri olmali ki puanlarin hepsine dogru dagitildiğini anlayabilsin.
        if(guc>=4 && ceviklik>=4 && dayaniklilik>=4 && karizma>=4 && toplayicilik>=4){ // beceriler en az 3 olabildigi için alt sinir 4'ten baslar.
            printf("Puanlarin hepsi dogru sekilde harcandi!");
        }
    }
    else{
        printf("\nSeviye atlayamadiniz. Tecrube puaniniz yetersiz!\n");
    }
}
void durumGoster(){

    printf("\nDurumunuz gosteriliyor...\n");
    printf("\t\n--- %s Karakterinin Guncel Durumu ---\n",ad);
    printf("\tAd: %s\n", ad);
    printf("\tCalgi: %s\n", calgiAdi);
    printf("\tAltin: %d\n", altin);
    printf("\tSeviye: %d\n", seviye);
    printf("\tTecrube: %d/100\n", tecrube);
    printf("\tCan: %d\n", can);
    printf("\tTokluk: %d\n", tokluk);
    printf("\tUyku: %d\n", uyku);
    printf("\tHijyen: %d\n", hijyen);
    printf("\tMutluluk: %d\n", mutluluk);
    printf("\tEnerji: %d\n", enerji);
    printf("\tYaraticilik: %d\n", yaraticilik);
    printf("\tGuc: %d\n", guc);
    printf("\tCeviklik: %d\n", ceviklik);
    printf("\tDayaniklilik: %d\n", dayaniklilik);
    printf("\tKarizma: %d\n", karizma);
    printf("\tToplayicilik: %d\n", toplayicilik);
}
void kolaySavas(){

    // Haydut özellikleri
    //1 ile 3 arasinda rastgele degerler üretilir
    int kolayGuc = (rand() % 3) + 1;
    int kolayCeviklik = (rand() % 3) + 1;
    int kolayDayaniklilik = (rand() % 3) + 1;

    printf("\nKarsiniza bir uzayli cikti! Uzayli Bilgileri --> Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n", kolayGuc, kolayCeviklik, kolayDayaniklilik);

    // Kaçma veya savas seçimi
    printf("1. Savas\n2. Kac\nSeciminiz: ");
    int secim2;
    scanf("%d", &secim2);

    if (secim2 == 2) { // Kaçma
        float kacmaIhtimali = (4.0 * ceviklik) / 100.0;
        if ((rand() % 100) < (kacmaIhtimali * 100)) {
            printf("\nBasariyla kactiniz!\n");

        }
        else {
            printf("Kacamadiniz! Savas basliyor...\n");
        }
    }

    // Savas
    while (can > 0 && kolayDayaniklilik > 0) {
        // Çeviklik karsilastirmasi. çevikligi büyük olan savasa ilk baslar
        int ilkVuran = (kolayCeviklik > ceviklik) ? 1 : 0;
        if (kolayCeviklik == ceviklik) {//çeviklikleri esit ise saldiri sirasi %50 sans ile belirlenir
            ilkVuran = rand() % 2; // %50 sans
        }

        if (ilkVuran) { // Haydut saldiriyor
            int verilenHasar = 4 * kolayGuc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * dayaniklilik / 100);
            can -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("\nUzayli size %d hasar verdi. Kalan caniniz: %d\n", alinanHasar, can);
        } else { // Ozan saldiriyor
            int verilenHasar = 4 * guc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * dayaniklilik / 100);
            kolayDayaniklilik -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("\nUzayliya %d hasar verdiniz. Uzaylinin kalan dayanikliligi: %d\n", alinanHasar, kolayDayaniklilik);
        }
    }

    if (can <= 0) {
        printf("\nUzayli tarafindan yenildiniz!\n");

    }
    else if (kolayDayaniklilik <= 0) {
        printf("\nUzayliyi yendiniz! Tecrube kazandiniz.\n");
        tecrube+=20;
    }
}
void ortaSavas(){

    // Haydut özellikleri
    int ortaGuc = (rand() % 3) + 4; // 4-6 arasinda
    int ortaCeviklik = (rand() % 3) + 4;
    int ortaDayaniklilik = (rand() % 3) + 4;

    printf("\nKarsiniza bir uzayli cikti! Uzayli Bilgileri --> Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n",ortaGuc, ortaCeviklik, ortaDayaniklilik);

    // Kaçma veya savaþ seçimi
    printf("1. Savas\n2. Kac\nSeciminiz: ");
    int secim3;
    scanf("%d", &secim3);

    if (secim3 == 2) { // Kaçma
        float kacmaIhtimali = (4.0 * ceviklik) / 100.0;
        if ((rand() % 100) < (kacmaIhtimali * 100)) {
            printf("Basarýyla kactiniz!\n");

        } else {
            printf("Kacamadiniz! Savas basliyor...\n");
        }
    }

    // Savaþ
    while (can > 0 && ortaDayaniklilik > 0) {
        int ilkVuran = (ortaCeviklik >ceviklik) ? 1 : 0;
        if (ortaCeviklik == ceviklik) {
            ilkVuran = rand() % 2;
        }

        if (ilkVuran) { // Haydut saldiriyor
            int verilenHasar = 4 * ortaGuc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * dayaniklilik / 100);
            can -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("Uzayli size %d hasar verdi. Kalan caniniz: %d\n", alinanHasar, can);
        } else { // Ozan saldýrýyor
            int verilenHasar = 4 * guc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * ortaDayaniklilik / 100);
            ortaDayaniklilik -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("Uyazliya %d hasar verdiniz. Uzaylinin kalan dayanikliliði: %d\n",alinanHasar, ortaDayaniklilik);
        }
    }

    if (can <= 0) {
        printf("Uzayli tarafindan yenildiniz!\n");
    }
     else if (ortaDayaniklilik <= 0) {
        printf("Uzayliyi yendiniz! Tecrube kazandiniz.\n");
        tecrube += 20;
    }
}
void zorSavas(){

    int zorGuc = (rand() % 4) + 7; // 7-10 arasýnda
    int zorCeviklik = (rand() % 4) + 7;
    int zorDayaniklilik = (rand() % 4) + 7;

    printf("Karsiniza bir uzayli cikti! Uzayli Bilgileri --> Guc: %d, Ceviklik: %d, Dayaniklilik: %d\n",zorGuc, zorCeviklik, zorDayaniklilik);

    // Kaçma veya savaþ seçimi
    printf("1. Savas\n2. Kac\nSeciminiz: ");
    int secim4;
    scanf("%d", &secim4);

    if (secim4 == 2) { // Kaçma
        float kacmaIhtimali = (4.0 * ceviklik) / 100.0;
        if ((rand() % 100) < (kacmaIhtimali * 100)) {
            printf("Basariyla kactiniz!\n");

        } else {
            printf("Kacamadiniz! Savas basliyor...\n");
        }
    }

    // Savaþ
    while (can > 0 && zorDayaniklilik > 0) {
        int ilkVuran = (zorCeviklik > ceviklik) ? 1 : 0;
        if (zorCeviklik == ceviklik) {
            ilkVuran = rand() % 2;
        }

        if (ilkVuran) { // Haydut saldýrýyor
            int verilenHasar = 4 * zorGuc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * dayaniklilik / 100);
            can -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("Uzayli size %d hasar verdi. Kalan caniniz: %d\n", alinanHasar, can);
        } else { // Ozan saldýrýyor
            int verilenHasar = 4 * guc;
            int alinanHasar = verilenHasar - (verilenHasar * 4 * zorDayaniklilik / 100);
            zorDayaniklilik -= (alinanHasar > 0) ? alinanHasar : 0;
            printf("Uzayliya %d hasar verdiniz. Uzaylinin kalan dayanikliligi: %d\n",alinanHasar, zorDayaniklilik);
        }
    }

    if (can <= 0) {
        printf("Uzayli tarafindan yenildiniz!\n");

    } else if (zorDayaniklilik <= 0) {
        printf("Uzayliyi yendiniz! Tecrube kazandiniz.\n");
        tecrube += 30;
    }
}
void canKontrol() {

    // Hayati niteliklerin kritik seviyelerini kontrol et.
    int canAzalmasi = 0;

    if (tokluk == 0) {
        canAzalmasi += 20; // Toklugun sifir olmasi cani 20 azaltir.
        printf("UYARI: Tokluk sifir! Karakterin cani 20 azalacak.\n");
    } else if (tokluk < 20) {
        printf("DÝKKAT: Tokluk kritik seviyede (%d).\n", tokluk);
    }

    if (uyku == 0) {
        canAzalmasi += 10; // Uykunun sifir olmasi cani 10 azaltir.
        printf("UYARI: Uyku sifir! Karakterin cani 10 azalacak.\n");
    } else if (uyku < 20) {
        printf("DÝKKAT: Uyku kritik seviyede (%d).\n", uyku);
    }

    if (mutluluk == 0) {
        canAzalmasi += 5; // Mutluluðun sifir olmasi cani 5 azaltir.
        printf("UYARI: Mutluluk sifir! Karakterin cani 5 azalacak.\n");
    } else if (mutluluk < 20) {
        printf("DÝKKAT: Mutluluk kritik seviyede (%d).\n", mutluluk);
    }

    if (enerji == 0) {
        canAzalmasi += 15; // Enerjinin sifir olmasi cani 15 azaltir.
        printf("UYARI: Enerji sifir! Karakterin cani 15 azalacak.\n");
    } else if (enerji < 20) {
        printf("DÝKKAT: Enerji kritik seviyede (%d).\n", enerji);
    }

    // Can azalmasini uygula
    if (canAzalmasi > 0) {
        can -= canAzalmasi;
        printf("UYARI: Karakterin cani %d puan azaldi! Guncel can: %d\n", canAzalmasi, can);

        // Karakterin cani sifirin altina düserse oyun biter.
        if (can <= 0) {
            printf("!!! OYUN BITTI: Karakterin cani kalmadi.\n");
            can = 0; // Can sifirdan asagiya düsmesin.
        }
    }
}
int main(){
    int secim,sayi;

    printf("Hos geldiniz.Lutfen bilgilerinizi giriniz.\n\n");
    printf("Metaverse koyunuz icin bir isim seciniz: ");
    gets(koyAdi);
    printf("Bas kahramanin adini giriniz: ");
    gets(ad);
    printf("Kullanilacak calginin adini giriniz: ");
    gets(calgiAdi);
    printf("\nOyunumuza hos geldiniz %s! %s calginiz ile oyuna hazir olun.\n",ad,calgiAdi);

    while(1){

        menuGoster();
        printf("Lutfen bir secim yapiniz: ");
        scanf("%d",&secim);

        getchar(); // kullanici girisi temizlendi

        switch(secim){
            case 1:
                usMerkezineDon();
                break;
            case 2:
                kampAlaninaGit();
                break;
            case 3:
                sifaIstasyonunaGit();
                break;
            case 4:
                hanaGit();
                break;
            case 5:
                gezegenKesfet();
                break;
            case 6:
                sifaliBitkiTopla();
                break;
            case 7:
                seviyeAtla();
                break;
            case 8:
                durumGoster();
                break;
            case 9:
                printf("\nOyundan cikma secenegini sectiniz.\n");
                printf("Cikis yapmak istediginize emin misiniz? Cikis yapmak icin 1'e basiniz: ");
                scanf("%d",&sayi);
                if(sayi==1){
                     printf("Oyundan cikis yapiliyor. Iyi gunler!\n");
                     return 0;
                }
                break;
            default:
                printf("Gecersiz bir secim yaptiniz. Ana menuye yonlendiriliyorsunuz...\n");
                break;
        }
    }
    return 0;
}
