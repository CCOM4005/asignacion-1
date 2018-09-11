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
    int data;
    node *link;
};

class linked_list
{
  private:
    node *head;

  public:
    void insert_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->link = NULL;

        if (head == NULL || head->data > n)
        {
            tmp->link = head;
            head = tmp;
        }
        else
        {
            node *current = head;
            while (current->link != NULL && current->link->data < n)
            {
                current = current->link;
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
            if (current->data == current->link->data)
            {
                counter++;
            }
            else if (current->data != current->link->data && counter != 0)
            {
                cout << "El " << current->data << " - se repite " << counter << ((counter == 1) ? " vez" : " veces") << endl;
                counter = 0;
            }
            current = current->link;
        }
        if (counter != 0)
            cout << "El " << current->data << " - se repite " << counter << ((counter == 1) ? " vez" : " veces") << endl;
    }

    void print_list()
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->link;
        }
    }
};

int main(int argc, char const *argv[])
{
    linked_list list;
    int n = 0;

    cout << "Entra una lista de numeros" << endl;
    cin >> n;
    while (n != -4005)
    {
        cin >> n;
        list.insert_node(n);
    }
    
    list.print_list();
    list.counter();

    return 0;
}
