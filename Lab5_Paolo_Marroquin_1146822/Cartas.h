#pragma once

class Cartas
{
	struct carta
	{
		//Atributos
		int numero;
		char color;
		bool volteada;

	};
private:
	carta* cartaInicial = nullptr;
public:
	//Cartas(int,char,bool);
	int getNumero();
	char getColor();
	bool getVolteada();
	void setNumero(int);
	void setColor(char);
	void setVolteada(bool);
};