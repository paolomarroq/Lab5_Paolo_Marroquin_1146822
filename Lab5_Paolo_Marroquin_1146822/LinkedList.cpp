#include <iostream>
#include "List.h"
#include "Cartas.h"


void List::Add(Cartas nueva)
{
	Node* add_node = new Node();
	add_node->data = nueva;

	if (header == nullptr)
	{
		header = add_node;
	}
	else
	{
		Node* temp = header;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = add_node;

	}
}
void List::Clear()
{
	Node* nextNode = header;
	Node* aux = header;
	int cont1 = 0, cont2 = 0;

	while (header->next)
	{
		if (nextNode->next)
		{
			nextNode = nextNode->next;
			cont1++;
		}
		else
		{
			while (cont2 != cont1 - 1)
			{
				aux = aux->next;
				cont2++;
			}
			delete nextNode;
			aux->next = NULL;
			aux = header;
			nextNode = header;
			cont1 = 0;
			cont2 = 0;
		}
	}
}
bool List::Contains(Cartas item, List* aux)
{
	Node* buscar = header;
	int posicion = 0;
	while (buscar->next)
	{
		if (item.getNumero() == buscar->data.getNumero() && item.getColor() == buscar->data.getColor())
		{
			return true;

		}
		else
		{
			buscar = buscar->next;
			posicion++;
		}
	}
	return false;
}
int List::Count()
{
	int cont = 0;
	Node* contar = header;
	while (contar->next != nullptr)
	{
		contar = contar->next;
		cont++;
	}
	return cont + 1;
}
Cartas List::GetItem(int Indice)
{
	int buscarIndice = 0;
	Node* buscarI = header;
	while (buscarIndice != Indice && buscarI->next != nullptr)
	{
		buscarI = buscarI->next;
		buscarIndice++;
	}
	return buscarI->data;
}
int List::IndexOf(Cartas Item, List* aux)
{
	int buscarItem = 0;
	Node* buscarI = header;
	while (buscarI->next)
	{
		if (Item.getNumero() != buscarI->data.getNumero())
		{
			buscarI = buscarI->next;
			buscarItem++;
		}
		else
		{
			return buscarItem;
		}
	}
	return -1;

}
void List::Insert(int Indice, Cartas Item)
{
	Node* insertar = header;
	Node* nuevo = new Node();
	Node* aux;
	nuevo->data = Item;
	int insertarEn = 0;
	while (insertarEn != Indice)
	{
		if (insertarEn != Indice - 1)
		{
			insertar = insertar->next;
			insertarEn++;
		}
		else
		{
			aux = insertar->next;
			insertar->next = nuevo;
			nuevo->next = aux;
			insertarEn++;
		}
	}
	if (Indice == 0)
	{
		nuevo->next = insertar;
		header = nuevo;
	}
}
int List::LastIndexOf(Cartas Item, List* aux)
{
	int buscarUltimoItem = 0, coincidencia = -1;
	Node* buscarI = header;
	while (buscarI->next)
	{
		if (Item.getNumero() != buscarI->data.getNumero() && Item.getColor() != buscarI->data.getColor())
		{
			buscarI = buscarI->next;
			buscarUltimoItem++;
		}
		else
		{
			buscarI = buscarI->next;
			coincidencia = buscarUltimoItem;
			buscarUltimoItem++;
		}
	}
	return coincidencia;
}
bool List::Remove(Cartas Item, List* auxi)
{
	Node* remover = header;
	Node* modificar = header;
	Node* aux;
	int contR = 0, contM = 0;
	while (remover->next)
	{
		if (remover->data.getNumero() != Item.getNumero() && remover->data.getColor() != Item.getColor())
		{
			remover = remover->next;
			contR++;
		}
		else
		{
			while (contM != contR - 1)
			{
				modificar = modificar->next;
				contM++;
			}
			aux = remover->next;
			delete remover;
			modificar->next = aux;
			return true;
		}

	}
	return false;
}
void List::RemoveAt(int Indice)
{
	int contR = 0, contM = 0;;
	Node* remover = header;
	Node* modificar = header;
	Node* aux;
	while (contR <= Indice)
	{
		if (contR != Indice && modificar->next != NULL && remover->next)
		{
			remover = remover->next;
			contR++;
		}
		else
		{
			while (contM != contR - 1 && modificar->next != nullptr && contR != 0)
			{
				modificar = modificar->next;
				contM++;
			}
			if (contR == 0)
			{
				aux = remover->next;
				header = aux;
				delete remover;
				contR = contR + 2;
			}
			else if (modificar->next)
			{
				aux = remover->next;
				delete remover;
				modificar->next = aux;
				contR++;
			}
			else
			{
				modificar->next = NULL;
				contR++;
			}
		}
	}
}
void List::SetItem(int Indice, Cartas Item)
{
	int cont = 0;
	Node* reemplazar = header;
	while (cont <= Indice)
	{
		if (cont != Indice)
		{
			reemplazar = reemplazar->next;
			cont++;
		}
		else
		{
			reemplazar->data = Item;
			cont++;
		}
	}
}
