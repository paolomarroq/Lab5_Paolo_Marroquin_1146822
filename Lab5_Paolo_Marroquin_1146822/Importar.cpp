#include "Cartas.h"
#include "List.h"
#include <iostream>
/*
Cartas::Cartas(int _numero, char _color, bool _volteada)
{
    cartaInicial->numero = _numero;
    cartaInicial->color = _color;
    cartaInicial->volteada = _volteada;

}
*/
char Cartas::getColor()
{
    return cartaInicial->color;

}
int Cartas::getNumero()
{
    return cartaInicial->numero;
}
bool Cartas::getVolteada()
{
    return cartaInicial->volteada;
}
void Cartas::setNumero(int num)
{
    carta* temp = new carta();
    temp->numero = num;
    cartaInicial = temp;
}
void Cartas::setColor(char ch)
{
    cartaInicial->color = ch;
}
void Cartas::setVolteada(bool volteo)
{
    cartaInicial->volteada = volteo;
}

