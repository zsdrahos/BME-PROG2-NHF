#include <iostream>
#include "telefonkonyv.h"

/// Telefonkonyv alaklamzas objektum modelje
/// @details    BME VIK PROG2 NHF
/// @author     Drahos Zsolt
/// @version    1.0
/// @date       2020-05-12

using std::cout;
using std::endl;
using std::cin;

#include "memtrace.h"

void test_1()
{
    cout << "************************** Teszt 1 - Adatok felvetele kodban **************************" << "" << endl;


    cout << "\nAdatok felvetele kodban \n" << endl;
    Telefonkonyv t1;
    Nevjegy n1(Nev("Vezeteknev","Keresztnev","Becenev"),Cim("Orszag","Irany","Varos","Utca/ut","Hazszam"), Tel("1234567890","9876543210"), "email@email.com");
    t1.Hozzaad(&n1);
    Nevjegy n2(Nev("Teszt","Elek","TE"),Cim("Magyarorszag","1111","Budapest","Alma utca","10"), Tel("06301234456","06306555002"), "elek@gmail.com");
    t1.Hozzaad(&n2);
    Nevjegy n3(Nev("Ferenci", "Viva", "Viva"),Cim("Magyarorszag","2234","Maglod","Sip utca","74"), Tel("06295760940","06448599209"), "ferenci@viva.com");
    t1.Hozzaad(&n3);
    Nevjegy n4(Nev("asd", "asd", "asd"),Cim("asd","asd","asd","asd asd","asd"), Tel("asd","asd"), "asd@asd.com");
    t1.Hozzaad(&n4);

    int db = t1.darab();
    cout<<"SIM kartyan tarolt nevjegyek: "<< db <<"\n"<<endl;
    t1.listaz(cout);

    cout<< n2.getNev() << " nevu szemely torlese "<<endl;
    t1.Tororl(&n2);
    t1.listaz_nev(cout);

    t1.Tororl(&n3);
    t1.Tororl(&n4);
    t1.Tororl(&n1);
    t1.listaz_nev(cout);
    t1.listaz(cout);

}

void test_2()
{
    cout << "\n************************** Teszt 2 - Adatok felvetele szabvanyos bemenetrol **************************" << "" << endl;

    Telefonkonyv t1;
    cout << "Adatok felvetele szabvanyos bemenetrol\n" << endl;
    cout << "Nevjegy felvetele: " << endl;

    Nev n5 = n5.beolvas_nev();
    Cim c5 = c5.beolvas_cim();
    Tel t5 = t5.beolvas_tel();
    cout << "Email: ";
    String e5;
    cin >> e5;

    Nevjegy nevjegy_beolvas(n5, c5, t5, e5);
    t1.Hozzaad(&nevjegy_beolvas);

    cout <<""<<endl;
    nevjegy_beolvas.print(cout);
    t1.Tororl(&nevjegy_beolvas);
}

void test_3()
{
    cout << "\n ************************** Teszt 3 - Kereses **************************" << "" << endl;

    Telefonkonyv t1;
    Nevjegy n1(Nev("Vezeteknev","Keresztnev","Becenev"),Cim("Orszag","Irany","Varos","Utca/ut","Hazszam"), Tel("1234567890","9876543210"), "email@email.com");
    t1.Hozzaad(&n1);
    Nevjegy n2(Nev("Teszt","Elek","TE"),Cim("Magyarorszag","1111","Budapest","Alma utca","10"), Tel("06301234456","06306555002"), "elek@gmail.com");
    t1.Hozzaad(&n2);
    Nevjegy n3(Nev("Ferenci", "Viva", "Viva"),Cim("Magyarorszag","2234","Maglod","Sip utca","74"), Tel("06295760940","06448599209"), "ferenci@viva.com");
    t1.Hozzaad(&n3);

    cout << "##################\nAdatok keresese Nev alapjan  \n" << endl;

    Nev nev1("Vezeteknev","Keresztnev", "Becenev");
    printf("-- Ezt keressuk: ");
    nev1.print(cout);
    t1.KeresNev(nev1, cout);

    Nev nev2("Teszt", "Elek");
    printf("-- Ezt keressuk: ");
    nev2.print(cout);
    t1.KeresNev(nev2, cout);

    Nev nev3("Viva");
    printf("-- Ezt keressuk: ");
    nev3.print(cout);
    t1.KeresNev(nev3, cout);

    cout << "##################\nAdatok keresese Telefonszam alapjan   \n" << endl;

    Tel tel1("06301234456","06306555002");                          //mind2 alapján
    printf("-- Ezt keressuk: ");
    tel1.print(cout);
    t1.KeresTel(tel1, cout);

    Tel tel2("06448599209");                                         // csak magán telefonszám alapján
    printf("-- Ezt keressuk: ");
    tel2.print(cout);
    t1.KeresTel(tel2, cout);

    cout << "##################\nAdatok keresese Cim alapjan  \n" << endl;

    Cim cim1("Orszag","Irany","Varos","Utca/ut","Hazszam");
    printf("-- Ezt keressuk: ");
    cim1.print(cout);
    t1.KeresCim(cim1, cout);

    Cim cim2("Magyarorszag");
    printf("-- Ezt keressuk: ");
    cim2.print(cout);
    t1.KeresCim(cim2, cout);

    Cim cim3("2234","Maglod");
    printf("-- Ezt keressuk: ");
    cim3.print(cout);
    t1.KeresCim(cim3, cout);

    t1.Tororl(&n1);
    t1.Tororl(&n2);
    t1.Tororl(&n3);

}

void test_4()
{
    cout << "\n ************************** Teszt 4 - Hibas adatok **************************" << "" << endl;

    Telefonkonyv t1;
    cout << "Adat torlese egy ures tombbol: " << endl;
    Nevjegy n6(Nev("Teszt","Elek","TE"),Cim("Magyarorszag","1111","Budapest","Alma utca","10"), Tel("06301234456","06306555002"), "elek@gmail.com");
    t1.Tororl(&n6);

    cout << "Olyan adat keresese ami nincs benne a tombben: " << endl;

    Cim cim4("Nincs","Nincs");
    printf("-- Ezt keressuk: ");
    cim4.print(cout);
    t1.KeresCim(cim4, cout);



}

int main()
{
    cout << "#####################################################" <<endl;
    cout << "#                                                   #" <<endl;
    cout << "#              TELEFONKONYV ALKALMAZAS              #" <<endl;
    cout << "#                        v1.0                       #" <<endl;
    cout << "#                                                   #" <<endl;
    cout << "#####################################################\n\n" <<endl;

    test_1();
    test_2();
    test_3();
    test_4();

    return 0;
}
