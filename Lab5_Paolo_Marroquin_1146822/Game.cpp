#include <iostream>
#include "List.h"
#include "Cartas.h"
using namespace std;

void todasLasCartas(List* Lmazo)
{
    int rojas = 0, negras = 0;
    bool lleno = true;
    Cartas* r = new Cartas();
    while (lleno)
    {

        if (rojas == 26 && negras == 26)
        {
            lleno = false;
        }
        else if (rojas < 26)
        {
            for (int i = 0; i < 13; i++)
            {
                if (rojas <= 26)
                {
                    r->setNumero(i + 1);
                    r->setColor('R');
                    r->setVolteada(false);
                    rojas++;
                    Lmazo->Add(*r);
                }
                else
                {
                    i = 0;
                }
            }
        }
        else if (negras < 26)
        {
            for (int i = 0; i < 13; i++)
            {
                if (negras <= 26)
                {
                    r->setNumero(i + 1);
                    r->setColor('N');
                    r->setVolteada(false);
                    negras++;
                    Lmazo->Add(*r);
                }
                else
                {
                    i = 0;
                }
            }
        }
    }
}
void mazoRandom(List* Lmazo, List* Rmazo)
{
    int tama = 52, random, tamacte, TR = 0, TL = 0;
    Cartas* mazoRandom = new Cartas();
    srand(time(NULL));
    tamacte = tama;
    for (int i = 0; i < tamacte; i++)
    {
        random = (rand() % tama) + 1;
        tama--;
        *mazoRandom = Lmazo->GetItem(random);

        Rmazo->Add(*mazoRandom);
        Lmazo->RemoveAt(random);
    }

}
void crearGrupos(List* Rmazo, List* LG1, List* LG2, List* LG3, List* LG4, List* LG5, List* LG6, List* LG7)
{
    Cartas* grupos = new Cartas();
    int grupo = 1;
    while (grupo < 8)
    {

        if (grupo == 1)
        {
            *grupos = Rmazo->GetItem(0);
            LG1->Add(*grupos);
            Rmazo->RemoveAt(0);
            grupo++;
        }
        else if (grupo == 2)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG2->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
        else if (grupo == 3)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG3->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
        else if (grupo == 4)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG4->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
        else if (grupo == 5)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG5->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
        else if (grupo == 6)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG6->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
        else if (grupo == 7)
        {
            for (int i = 0; i < grupo; i++)
            {
                *grupos = Rmazo->GetItem(0);
                LG7->Add(*grupos);
                Rmazo->RemoveAt(0);
            }
            grupo++;
        }
    }

}
bool interGrupo(List* deAqui, List* aAca)
{
    Cartas intde, intpara;
    int TdeAqui = deAqui->Count(), TaAca = aAca->Count();
    if (TdeAqui != 7) intde = deAqui->GetItem(0);
    else intde = deAqui->GetItem(TdeAqui - 1);
    if (TaAca != 7) intpara = aAca->GetItem(0);
    else intpara = aAca->GetItem(TaAca - 1);
    if (intde.getColor() != intpara.getColor() && intde.getNumero() < intpara.getNumero())
    {
        deAqui->RemoveAt(0);
        intde.setVolteada(true);
        aAca->Insert(0, intde);
        return true;
    }
    else return false;

}
void shuffle(List* revolver)
{
    int tama = revolver->Count(), random, tamacte;
    tamacte = tama;
    List* aux = new List();
    Cartas* cart = new Cartas();
    srand(time(NULL));
    for (int i = 0; i < tama; i++)
    {
        random = rand() % tama;
        tama--;
        *cart = revolver->GetItem(i);
        aux->Add(*cart);
        revolver->RemoveAt(i);
    }
    revolver = aux;
}
bool ganar(int interG1, int interG2, int interG3, int interG4, int interG5, int interG6, int interG7)
{
    if (interG1 >= 5)return true;
    else if (interG2 >= 5)return true;
    else if (interG3 >= 5)return true;
    else if (interG4 >= 5)return true;
    else if (interG5 >= 5)return true;
    else if (interG6 >= 5)return true;
    else if (interG7 >= 5)return true;
    else return false;
}
int grupoMayor(int TG1, int TG2, int TG3, int TG4, int TG5, int TG6, int TG7)
{
    int mayor = 0;
    if (TG7 > TG6)
    {
        mayor = TG7;
        return mayor;
    }
    else if (TG6 > TG5)
    {
        mayor = TG6;
        return mayor;
    }
    else if (TG5 > TG4)
    {
        mayor = TG5;
        return mayor;
    }
    else if (TG4 > TG3)
    {
        mayor = TG4;
        return mayor;
    }
    else if (TG3 > TG2)
    {
        mayor = TG3;
        return mayor;
    }
    else if (TG2 > TG1)
    {
        mayor = TG2;
        return mayor;
    }
    else
    {
        mayor = TG1;
        return mayor;
    }

}
void Juego(List* Rmazo, List* LG1, List* LG2, List* LG3, List* LG4, List* LG5, List* LG6, List* LG7)
{
    int TG1 = LG1->Count(), TG2 = LG2->Count(), TG3 = LG3->Count(), TG4 = LG4->Count(), TG5 = LG5->Count(), TG6 = LG6->Count(), TG7 = LG7->Count(), TMazo = Rmazo->Count(), NG1, NG2, NG3, NG4, NG5, NG6, NG7, NMazo, mayor, op = 0, cartaDeAqui, cartaaAca, mostrarMazo = 0, IG1 = 0, IG2 = 0, IG3 = 0, IG4 = 0, IG5 = 0, IG6 = 0, IG7 = 0, Imazo = 0;
    char CG1, CG2, CG3, CG4, CG5, CG6, CG7, CMazo, R;
    bool  gano = false, inter, mazoM = true;
    string mazoString;
    List* mazoMostrar = new List();
    mayor = grupoMayor(TG1, TG2, TG3, TG4, TG5, TG6, TG7);

    cin >> R;
    if (R == 'R' || R == 'r')
    {
        do
        {
            if (IG1 < 0) IG1 = 0;
            if (IG2 < 0) IG2 = 0;
            if (IG3 < 0) IG3 = 0;
            if (IG4 < 0) IG4 = 0;
            if (IG5 < 0) IG5 = 0;
            if (IG6 < 0) IG6 = 0;
            if (IG7 < 0) IG7 = 0;

            switch (op)
            {
            case 1:
                if (mostrarMazo == 1)
                {
                    mazoMostrar->GetItem(0).setVolteada(true);
                    mostrarMazo++;
                }
                else
                {
                    mazoMostrar->Add(Rmazo->GetItem(0));
                    Rmazo->RemoveAt(0);
                    mazoMostrar->GetItem((mazoMostrar->Count()) - 1).setVolteada(true);
                }
                break;
            case 2:
                cout << "De que grupo desea mover una carta? (Coloque 8 si desea mover una carta del mazo) \nDel grupo numero: ";
                cin >> cartaDeAqui;
                cout << "A que grupo desea mover la carta? \nAl grupo numero: ";
                cin >> cartaaAca;
                if (cartaDeAqui == 1)
                {
                    if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG1, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG1--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG1, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG1--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG1, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG1--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG1, LG5);
                        if (inter)
                        {
                            IG5++;
                            IG1--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG1, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG1--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG1, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG1--;
                        }
                    }
                }
                else if (cartaDeAqui == 2)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG2, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG2--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG2, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG2--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG2, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG2--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG2, LG5);
                        if (inter)
                        {
                            IG5++;
                            IG2--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG2, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG2--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG2, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG2--;
                        }
                    }
                }
                else if (cartaDeAqui == 3)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG3, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG3--;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG3, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG3--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG3, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG3--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG3, LG5);
                        if (inter)
                        {
                            IG5++;
                            IG3--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG3, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG3--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG3, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG3--;
                        }
                    }
                }
                else if (cartaDeAqui == 4)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG4, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG4--;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG4, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG4--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG4, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG4--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG4, LG5);
                        if (inter)
                        {
                            IG5++;
                            IG4--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG4, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG4--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG4, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG4--;
                        }
                    }
                }
                else if (cartaDeAqui == 5)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG5, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG5--;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG5, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG5--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG5, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG5--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG5, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG5--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG5, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG5--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG5, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG5--;
                        }
                    }
                }
                else if (cartaDeAqui == 6)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG6, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG6--;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG6, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG6--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG6, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG6--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG6, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG6--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG6, LG5);
                        if (inter)
                        {
                            IG5++;
                            IG6--;
                        }
                    }
                    else if (cartaaAca == 7)
                    {
                        inter = interGrupo(LG6, LG7);
                        if (inter)
                        {
                            IG7++;
                            IG6--;
                        }
                    }
                }
                else if (cartaDeAqui == 7)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(LG7, LG1);
                        if (inter)
                        {
                            IG1++;
                            IG7--;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(LG7, LG2);
                        if (inter)
                        {
                            IG2++;
                            IG7--;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(LG7, LG3);
                        if (inter)
                        {
                            IG3++;
                            IG7--;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(LG7, LG4);
                        if (inter)
                        {
                            IG4++;
                            IG7--;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(LG7, LG5); if (inter)
                        {
                            IG5++;
                            IG7--;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(LG7, LG6);
                        if (inter)
                        {
                            IG6++;
                            IG7--;
                        }
                    }
                }
                else if (cartaDeAqui == 8)
                {
                    if (cartaaAca == 1)
                    {
                        inter = interGrupo(mazoMostrar, LG1);
                        if (inter)
                        {
                            IG1++;
                        }
                    }
                    else if (cartaaAca == 2)
                    {
                        inter = interGrupo(mazoMostrar, LG2);
                        if (inter)
                        {
                            IG2++;
                        }
                    }
                    else if (cartaaAca == 3)
                    {
                        inter = interGrupo(mazoMostrar, LG3);
                        if (inter)
                        {
                            IG3++;
                        }
                    }
                    else if (cartaaAca == 4)
                    {
                        inter = interGrupo(mazoMostrar, LG4);
                        if (inter)
                        {
                            IG4++;
                        }
                    }
                    else if (cartaaAca == 5)
                    {
                        inter = interGrupo(mazoMostrar, LG5);
                        if (inter)
                        {
                            IG5++;
                        }
                    }
                    else if (cartaaAca == 6)
                    {
                        inter = interGrupo(mazoMostrar, LG6);
                        if (inter)
                        {
                            IG6++;
                        }
                    }
                    else
                    {
                        inter = interGrupo(mazoMostrar, LG7);
                        if (inter)
                        {
                            IG7++;
                        }
                    }
                }
                if (!inter)
                {
                    cout << "No se puede mover esta crata del grupo " << cartaDeAqui << " al grupo " << cartaaAca << endl;
                }
                else Imazo++;
                break;
            case 3:
                shuffle(Rmazo);
                cout << "Mazo mazclado";
                break;
            case 4:
                cout << "Mejor suerte a la proxima";
                exit(0);
                break;
            }
            //Imprimir
            TG1 = LG1->Count();
            TG2 = LG2->Count();
            TG3 = LG3->Count();
            TG4 = LG4->Count();
            TG5 = LG5->Count();
            TG6 = LG6->Count();
            TG7 = LG7->Count();
            LG1->GetItem(TG1 - 1).setVolteada(true);
            LG2->GetItem(TG2 - 1).setVolteada(true);
            LG3->GetItem(TG3 - 1).setVolteada(true);
            LG4->GetItem(TG4 - 1).setVolteada(true);
            LG5->GetItem(TG5 - 1).setVolteada(true);
            LG6->GetItem(TG6 - 1).setVolteada(true);
            LG7->GetItem(TG7 - 1).setVolteada(true);
            if (mostrarMazo <= 0)
            {
                mazoMostrar->Add(Rmazo->GetItem(0));
                Rmazo->RemoveAt(0);
                mostrarMazo++;
            }
            if (mazoMostrar->GetItem((mazoMostrar->Count()) - 1).getVolteada())
            {
                cout << "Mazo: ";
                for (int i = 0; i < mazoMostrar->Count(); i++)
                {
                    NMazo = mazoMostrar->GetItem(i).getNumero();
                    CMazo = mazoMostrar->GetItem(i).getColor();
                    cout << NMazo << CMazo << "\t";
                }
                cout << endl;
            }
            else
            {
                cout << "Mazo: --" << endl;
            }
            cout << "G1\tG2\tG3\tG4\tG5\tG6\tG7\n";
            for (int i = 0; i < mayor; i++)
            {
                if (LG1->GetItem(i).getVolteada() && i < TG1)
                {

                    NG1 = LG1->GetItem(TG1 - (i + 1)).getNumero();
                    CG1 = LG1->GetItem(TG1 - (i + 1)).getColor();
                    cout << NG1 << CG1 << "\t";

                }
                else
                {
                    if (i < TG1)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG2->GetItem(i).getVolteada() && i < TG2)
                {
                    NG2 = LG2->GetItem(TG2 - (i + 1)).getNumero();
                    CG2 = LG2->GetItem(TG2 - (i + 1)).getColor();
                    cout << NG2 << CG2 << "\t";
                }
                else
                {
                    if (i < TG2)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG3->GetItem(i).getVolteada() && i < TG3)
                {
                    NG3 = LG3->GetItem(TG3 - (i + 1)).getNumero();
                    CG3 = LG3->GetItem(TG3 - (i + 1)).getColor();
                    cout << NG3 << CG3 << "\t";
                }
                else
                {
                    if (i < TG3)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG4->GetItem(i).getVolteada() && i < TG4)
                {
                    NG4 = LG4->GetItem(TG4 - (i + 1)).getNumero();
                    CG4 = LG4->GetItem(TG4 - (i + 1)).getColor();
                    cout << NG4 << CG4 << "\t";
                }
                else
                {
                    if (i < TG4)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG5->GetItem(i).getVolteada() && i < TG5)
                {
                    NG5 = LG5->GetItem(TG5 - (i + 1)).getNumero();
                    CG5 = LG5->GetItem(TG5 - (i + 1)).getColor();
                    cout << NG5 << CG5 << "\t";
                }
                else
                {
                    if (i < TG5)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG6->GetItem(i).getVolteada() && i < TG6)
                {
                    NG6 = LG6->GetItem(TG6 - (i + 1)).getNumero();
                    CG6 = LG6->GetItem(TG6 - (i + 1)).getColor();
                    cout << NG6 << CG6 << "\t";
                }
                else
                {
                    if (i < TG6)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                if (LG7->GetItem(i).getVolteada() && i < TG7)
                {
                    NG7 = LG7->GetItem(TG7 - 1).getNumero();
                    CG7 = LG7->GetItem(TG7 - 1).getColor();
                    cout << NG7 << CG7 << "\t";
                }
                else
                {
                    if (i < TG7)
                    {
                        cout << "--\t";
                    }
                    else
                    {
                        cout << "\t";
                    }
                }
                cout << endl;

            }
            //finImprimir
            gano = ganar(IG1, IG2, IG3, IG4, IG5, IG6, IG7);
            cout << "Que desea hacer?\n1. Tomar del mazo\n2. Mover e grupos\n3. Mezclar mazo\n4. Rendirse\nIngrese el numero de la opcion que desa: ";
            cin >> op;
        } while (!gano);
    }
    else
    {
        cout << "No ingreso 'R' \n";
    }
    if (gano)
    {
        cout << "Felicidades ha ganado, realizó " << Imazo << " intercambios de cartas.";
    }

}
int main()
{
    List* MAZO = new List(), * randMazo = new List(), * G1 = new List(), * G2 = new List(), * G3 = new List(), * G4 = new List(), * G5 = new List(), * G6 = new List(), * G7 = new List();
    Cartas* cartas;


    cout << "Bienvenido a solitario\nPresione 'R'\n";
    todasLasCartas(MAZO);
    mazoRandom(MAZO, randMazo);
    crearGrupos(randMazo, G1, G2, G3, G4, G5, G6, G7);
    Juego(randMazo, G1, G2, G3, G4, G5, G6, G7);

    cout << "Adios";
}