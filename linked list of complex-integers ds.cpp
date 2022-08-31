#include <iostream>
#include <string.h>
#include "complex-integer ds.cpp"
using namespace std;

class Node
{
    private:
        ComplexNumber num;
    public:
        Node * next;
        Node()
        {
            next = NULL;
            cout << "Constructor of Node" << endl;
        }
        Node(const ComplexNumber& n) : num(n.get_real(), n.get_imaginary())
        {
            next = NULL;
            cout << "Constructor of Node" << endl;
        }
        Node(const Node& n) : num(n.num.get_real(), n.num.get_imaginary())
        {
            next = n.next;
            cout << "Constructor of Node" << endl;
        }
        ~Node()
        {
            cout << "Destructor of Node" << endl;
        }
        ComplexNumber& get_num()
        {
            return num;
        }
};

class LinkedList
{
    private:
        Node * next;
    public:
        LinkedList()
        {
            next = NULL;
            cout << "Default constructor of LL" << endl;
        }
        /*~LinkedList()
        {
            Node * nxt;
            Node * l;
            l = next;
            while (l!=NULL)
            {
                nxt = l;
                l = l->next;
                delete nxt;
            }
            cout << "Destructor of Linked list "<<endl;
        }*/
        friend void display_LL(LinkedList * l);
        friend bool search_LL(LinkedList * l, const ComplexNumber comp);
        LinkedList operator+ (const ComplexNumber& n)
        {
            Node * node = new Node(n);
            Node * temp;
            temp = next;
            if (temp == NULL)
            {
                next = node;
                return *this;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
                return *this;
            }
            cout << "\n\n";
        }
        LinkedList operator+ (LinkedList& n)
        {
            Node * temp;
            temp = next;
            if (temp == NULL)
            {
                return n;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = n.next;
                return *this;
            }
        }
        LinkedList operator- ()
        {
            Node * temp;
            temp = next;
            if (temp == NULL)
            {
                cout << "Empty" <<endl;
            }
            else if (temp->next == NULL)
            {
                cout << "Deleted node: ";
                display(temp->get_num());
                next = NULL;
            }
            else
            {
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                cout << "Deleted node: ";
                display(temp->get_num());
                temp->next = NULL;
            }
            return *this;
        }
        LinkedList operator= (LinkedList& l)
        {
            next = l.next;
            return *this;
        }
        LinkedList operator= (ComplexNumber n[10])
        {
            for (int i=0; i<10; i++)
            {
                (*this)+n[i];
            }
            return *this;
        }
        LinkedList operator<< (int k)
        {
            if (k == 0)
            {
                return *this;
            }
            Node* current = next;
            int ct = 1;
            while (ct < k && current != NULL)
            {
                current = current->next;
                ct++;
            }
            if (current == NULL)
            {
                next = NULL;
                return *this;
            }
            Node* kthNode = current;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = NULL;
            next = current;
            return *this;
        }
        LinkedList operator>> (int v)
        {
            int k;
            k = this->length() - v;
            if (k == 0)
            {
                return *this;
            }
            Node* current = next;
            int ct = 1;
            while (ct < k && current != NULL)
            {
                current = current->next;
                ct++;
            }
            if (current == NULL)
            {
                next = NULL;
                return *this;
            }
            current->next = NULL;
            return *this;
        }
        int length()
        {
            Node * temp;
            temp = next;
            int ct =0;
            while (temp!=NULL)
            {
                ct++;
                temp = temp->next;
            }
            return ct;
        }
        void operator* (int x)
        {
            if (this->length() >= x && x>0)
            {
                Node * temp;
                temp = next;
                if (temp->next == NULL)
                {
                    cout << "Deleted node: ";
                    display(temp->get_num());
                    next = NULL;
                }
                else if (x==0)
                {
                    cout << "Deleted node: ";
                    display(temp->get_num());
                    next = next->next;
                }
                else
                {
                    x-=1;
                    while (temp->next != NULL && x>1)
                    {
                        x--;
                        temp = temp->next;
                    }
                    cout << "Deleted node: ";
                    display(temp->next->get_num());
                    temp->next = temp->next->next;
                }
            }
            else
            {
                cout << "Overflow/Underflow in input "<<endl;
            }
        }
};

void display_LL(LinkedList * l)
{
    Node * temp;
    temp = l->next;
    while (temp!=NULL)
    {
        display(temp->get_num());
        temp = temp->next;
    }
    cout << endl;
}

bool search_LL(LinkedList * l, const ComplexNumber comp)
{
    Node * temp;
    temp = l->next;
    bool val = false;
    int k=0;
    while (temp!=NULL && k==0)
    {
        if ((temp->get_num()).get_real() == comp.get_real() && (temp->get_num()).get_imaginary() == comp.get_imaginary())
        {
            k=1;
            val = true;
        }
        temp = temp->next;
    }
    return val;
}

int main()
{
    ComplexNumber n(1,2);
    LinkedList ll;
    ll + n;
    ll + n;
    ComplexNumber m(2,1);
    ll+m;
    ll+m;
    display_LL(&ll);
    ll<<3;
    display_LL(&ll);
    ComplexNumber k[10];
    for (int i=0; i<10; i++)
    {
        k[i] = n;
    }
    LinkedList ll0 = ll;
    ll0 = k;
    display_LL(&ll0);
    return 0;
}
