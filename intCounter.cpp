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
            node *next = current->link;
            while(current->link != NULL && current->link->data < n)
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
        int counter = 1;
        while(current->link != NULL)
        {
            if(current->data == current->link->data)
            {
                counter++;
            }
            else
            {
                cout << "El " << current->data << " - se repite " << counter << ((counter == 1) ? " vez" : " veces") << endl;
                counter = 1;
            }
            current = current->link;
        }
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
    list.insert_node(4);
    list.insert_node(6);
    list.insert_node(1);
    list.insert_node(69);
    list.insert_node(7);
    list.insert_node(100);
    list.insert_node(53);
    list.insert_node(4);
    list.insert_node(1);
    list.insert_node(69);
    list.insert_node(100);
    list.insert_node(100);
    list.insert_node(53);
    list.insert_node(4);
    list.insert_node(1);
    list.insert_node(69);
    list.insert_node(100);
    list.insert_node(1);
    list.insert_node(69);
    list.print_list();
    list.counter();

    return 0;
}
