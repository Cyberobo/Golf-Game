#include <iostream>
#define satir 15
#define sutun 11
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

int top=0,top_satir=13,top_sutun=5,azaltma=1,mesafe,arttirma=1,hamle_sayisi,skor=0;
string delik="o ";

class oyun
{
public:
//top baslangic pozisyon ayarlama ve posizyondan sonraki yonlendirme icin  f tusuyla yon tusu ve guc verisi alma
void top_haraket(char *ikinci_yon_tuslari,int *guc)
{
    cout<<"KALAN HAMLE SAYINIZ: "<<hamle_sayisi<<endl;
    cout<<"lutfen hangi yonde vurmak istediginizi girin w/s/e/q/a/d: ";
    cin>>*ikinci_yon_tuslari;
    if(*ikinci_yon_tuslari!='w' && *ikinci_yon_tuslari!='s' && *ikinci_yon_tuslari!='e' && *ikinci_yon_tuslari!='q' && *ikinci_yon_tuslari!='a' && *ikinci_yon_tuslari!='d')
    {
        cout<<"lutfen w/s/e/q/a/d harflerinden birini giriniz: ";
        cin>>*ikinci_yon_tuslari;
    }
    cout<<endl;
    cout<<"lutfen guc degerini girin 1/2/3/4/5: ";
    cin>>*guc;
}
//pozisyondan sonraki yon haraketi ve giderkenki hesaplamalar
void top_baslangictan_sonraki_haraket(char ikinci_yon_tuslari)
{

    if(ikinci_yon_tuslari=='w')
    {
        if(top_satir == 1 || top_sutun == 1)
            azaltma-=2;


        else if(top_satir==satir-2 || top_sutun==sutun-2)
        {
            azaltma=0;
            azaltma+=1;

        }

        top_satir-=azaltma;
    }

    else if(ikinci_yon_tuslari=='s')
    {
        if(top_satir == 1 || top_sutun == 1)
            azaltma+=2;


        else if(top_satir==satir-2 || top_sutun==sutun-2)
        {
            azaltma=0;
            azaltma-=1;
        }

        top_satir+=azaltma;
    }

    else if(ikinci_yon_tuslari=='e')
    {

        if(top_satir==1 && top_sutun==sutun-2)
        {
            azaltma-=2;
            arttirma-=2;
        }

        else if(top_satir==1 && top_sutun==1)
        {
            azaltma-=2;
            arttirma+=2;
        }

        else if(top_satir==satir-2 && top_sutun==1)
        {
            azaltma+=2;
            arttirma+=2;
        }

        else if(top_satir==satir-2 && top_sutun==sutun-2)
        {
            azaltma+=2;
            arttirma-=2;
        }

        else if(top_sutun == sutun-2)
        {
            arttirma-=2;
        }

        else if(top_satir==1)
        {
            azaltma-=2;
            arttirma+=0;

        }
        else if(top_sutun==1)
        {
            arttirma+=2;
        }
        else if(top_satir==satir-2)
        {
            arttirma+=0;
            if(azaltma==-1)
                azaltma+=2;
        }
        top_satir-=azaltma;
        top_sutun+=arttirma;
    }

    else if(ikinci_yon_tuslari=='a')
    {
        if(top_satir==1 && top_sutun==sutun-2)
        {
            azaltma+=2;
            arttirma+=2;
        }

        else if(top_satir==1 && top_sutun==1)
        {
            azaltma+=2;
            arttirma-=2;
        }

        else if(top_satir==satir-2 && top_sutun==1)
        {
            azaltma-=2;
            arttirma-=2;
        }

        else if(top_satir==satir-2 && top_sutun==sutun-2)
        {
            azaltma-=2;
            arttirma+=2;
        }

        else if(top_sutun == sutun-2)
        {
            arttirma+=2;
        }

        else if(top_satir==1)
        {
            azaltma+=2;
            arttirma-=0;

        }
        else if(top_sutun==1)
        {
            arttirma-=2;
        }
        else if(top_satir==satir-2)
        {
            arttirma-=0;
            if(azaltma==+1)
                azaltma-=2;
        }


        top_satir+=azaltma;
        top_sutun-=arttirma;
    }

    else if(ikinci_yon_tuslari=='q')
    {
        if(top_satir==1 && top_sutun==sutun-2)
        {
            azaltma-=2;
            arttirma+=2;
        }

        else if(top_satir==1 && top_sutun==1)
        {
            azaltma-=2;
            arttirma-=2;
        }

        else if(top_satir==satir-2 && top_sutun==1)
        {
            azaltma+=2;
            arttirma-=2;
        }

        else if(top_satir==satir-2 && top_sutun==sutun-2)
        {
            azaltma+=2;
            arttirma+=2;
        }

        else if(top_sutun==1)
        {
            arttirma-=2;
        }
        else if(top_satir==1)
        {
            azaltma-=2;

        }
        else if(top_sutun == sutun-2)
        {
            arttirma+=2;
        }

        else if(top_satir==satir-2)
        {
            if(azaltma==-1)
                azaltma+=2;
        }


        top_satir-=azaltma;
        top_sutun-=arttirma;
    }

    else if(ikinci_yon_tuslari=='d')
    {
        if(top_satir==1 && top_sutun==sutun-2)
        {
            azaltma+=2;
            arttirma-=2;
        }

        else if(top_satir==1 && top_sutun==1)
        {
            azaltma+=2;
            arttirma+=2;
        }

        else if(top_satir==satir-2 && top_sutun==1)
        {
            azaltma-=2;
            arttirma+=2;
        }

        else if(top_satir==satir-2 && top_sutun==sutun-2)
        {
            azaltma-=2;
            arttirma-=2;
        }

        else if(top_sutun==1)
        {
            arttirma+=2;
        }
        else if(top_satir==1)
        {
            azaltma+=2;

        }
        else if(top_sutun == sutun-2)
        {
            arttirma-=2;
        }

        else if(top_satir==satir-2)
        {
            if(azaltma==+1)
                azaltma-=2;
        }


        top_satir+=azaltma;
        top_sutun+=arttirma;

    }
}

//top animasyon ve guce gore topu ilerletme
void top_animasyon(char ikinci_yon_tuslari,int guc,int random_satir,int random_sutun,int i,int j)
{
    float hiz = 1.0;
    float surtunme;
    mesafe = guc;
    //girilen guce gore katedecegi mesafeyi hesaplar
    switch (guc)
    {
        case 1:
            mesafe *= 1;
            break;
        case 2:
            mesafe *= 2;
            break;
        case 3:
            mesafe *= 2;
            break;
        case 4:
            mesafe += 10;
            break;
        case 5:
            mesafe += 15;
            break;
        default:
            break;
    }

    //mesafe kacsa o kadar donguye girer ve animasyonlu bir sekilde top ilerler
    for (int a = 0; a < mesafe; a++)
    {
        top_baslangictan_sonraki_haraket(ikinci_yon_tuslari);
        tablo_olusturma(random_satir,random_sutun,i,j);
        hiz*=0.5;
        surtunme=hiz;
        Sleep(surtunme);
        if(top_satir==random_satir && top_sutun==random_sutun)
            break;

    }
}
//tablonun olustugu kisim
void tablo_olusturma(int random_satir,int random_sutun,int i,int j)
{
    system("cls");

    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            if (i == 0 || i == satir - 1 || j == 0 || j == sutun - 1)
                cout<<"# ";
            //topu tabloya bastirma
            else if(i==top_satir && j==top_sutun)
            {
                cout<<top<<" ";
            }
            //baslangic cizgisi
            else if(i==12 && j!=sutun-1)
                cout<<"- ";
            //deligi tabloya bastirma
            else
                if(i==random_satir && j==random_sutun)
                {
                    cout<<delik;
                }
                else
                    cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
}

};

int main()
{
    srand(time(NULL));
    oyun tenis;
    //deligin random olusacagi i ve j kordinatlari
    int random_satir=1+rand()%11;
    int random_sutun=1+rand()%9;
    //baslangic guc degeri
    int guc=0,i,j,skor=0;
        //a,d,f          //w,e,q
    char ikinci_yon_tuslari;

    cout<<"tenis oyununa hosgeldin oyunu baslatmak icin 'enter' tusuna basin"<<endl<<"NOT: MEKANIKLERDE SAG SOL HARAKET YOKTUR OYUNUN KOLAY OLMAMASI ACISINDAN SADECE ILERI GERI VE CAPRAZ HARAKET VARDIR!!!"<<endl<<"VE YONLER HAR ZAMAN TOPUN EN SON HARAKET YONU NEYSE O YONE BAKAR!!!"<<endl;
    getchar();
    //olusturulan fonksiyonlarin hamle sayisi bitimine kadar donguye girmesi
    while(true)
    {
        for(hamle_sayisi=5;hamle_sayisi>0;hamle_sayisi--)
        {
            if(top_satir!=random_satir || top_sutun!=random_sutun)
            {
                tenis.tablo_olusturma(random_satir,random_sutun,i,j);
                tenis.top_haraket(&ikinci_yon_tuslari,&guc);
                tenis.top_animasyon(ikinci_yon_tuslari,guc,random_satir,random_sutun,i,j);

                if(top_satir == 1 || top_satir == satir - 2 || top_sutun == 1 || top_sutun == sutun - 2)
                    tenis.top_baslangictan_sonraki_haraket(ikinci_yon_tuslari);

            }

            else if(top_satir==random_satir && top_sutun==random_sutun)
            {
                random_satir=1+rand()%11;
                random_sutun=1+rand()%9;
                tenis.tablo_olusturma(random_satir,random_sutun,i,j);
                skor+=1;
            }
        }

        if(hamle_sayisi==0)
            cout<<"HAMLE HAKKINIZ BITTI"<<endl<<"SON SKORUNUZ: "<<skor<<endl;
            break;
    }
    return 0;
}
