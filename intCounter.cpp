//
//  main.cpp
//  intCounter
//
//  Created by Jonathan  Nieves on 9/10/18.
//  Copyright © 2018 Firebits. All rights reserved.
//

#include <iostream>

using namespace std;

struct node
{
    int number;
    node *link;
};

class linked_list                   // Clase que define la estructura de la lista encadenada
{
  private:
    node *head;                     // Puntero que almacena la dirección del primer elemento de la lista

  public:
    void insert_node(int n)         // Método de inserción ordenada
    {
        node *tmp = new node;
        tmp->number = n;            // Se crea el nuevo nodo
        tmp->link = NULL;           // y se insertan los valores

        if (head == NULL || head->number > n)       // Inserta el nuevo nodo en la cabeza
        {                                           // si su valor es nulo, o si el numero
            tmp->link = head;                       // de la cabeza es mayor, el nuevo nodo
            head = tmp;                             // pasa a ser la cabeza
        }
        else
        {
            node *current = head;
            while (current->link != NULL &&         // Inserta el nuevo nodo en la lista
                    current->link->number < n)      // donde corresponde a que el número
            {                                       // a insertar sea menor al número 
                current = current->link;            // del siguiente nodo
            }
            tmp->link = current->link;
            current->link = tmp;
        }
    }

    void counter()
    {
        node *current = head;
        int counter = 0;
        while (current->link != NULL)                                               
        {
            if (current->number == current->link->number)                           // Mientras los números sean iguales se va
            {                                                                       // acumulando la cantidad de veces que se
                counter++;                                                          // repite, de lo contrario se presenta la
            }                                                                       // cantidad de veces que el número se 
            else if (current->number != current->link->number && counter != 0)      // se repite en pantalla, siempre y cuando
            {                                                                       // se repita una vez o mas
                cout << "El " << current->number << " - se repite " << counter 
                << ((counter == 1) ? " vez" : " veces") << endl;
                counter = 0;
            }
            else if(current->link == NULL && counter != 0)
            {
                cout << "El " << current->number << " - se repite " << counter 
                << ((counter == 1) ? " vez" : " veces") << endl;
            }
            current = current->link;
        }
    }

    void print_list()
    {
        node *current = head;                               // Presenta los números de la lista
        while (current != NULL)
        {
            cout << current->number << endl;
            current = current->link;
        }
    }
};

int main(int argc, char const *argv[])
{
    linked_list list;
    int n = 0;

    cout << "Entra una lista de numeros (para terminar entra -4005)" << endl;
    cin >> n;
    while (n != -4005)                             // Función para que el usuario entre la
    {                                              // cantidad de datos que prefiera
        cin >> n;                                  // para terminar entra -4005
        list.insert_node(n);
    }
    
    list.print_list();
    list.counter();

    return 0;
}
