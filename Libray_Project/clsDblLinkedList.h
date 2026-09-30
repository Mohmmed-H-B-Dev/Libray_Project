#pragma once
#include <iostream>

using namespace std;

template <class T>
class  clsDblLinkedList
{

    int _size = 0;

public:
    class Node
    {
    public:
        T value;
        string PayMethed;
        Node* next;
        Node* prev;
    };


    Node* head = NULL;

    bool IsEmpty() {

        return (_size == 0 ? true : false);
    }


    void InsertAtBeginning(T value, string PayMethed) {


        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */
        if (value == NULL)return;
        Node* newNode = new Node();
        newNode->value = value;
        newNode->PayMethed = PayMethed;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _size++;
    }
    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value,string PayMethed) {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */
        if (current == NULL)return;
        Node* newNode = new Node();
        newNode->value = value;
        newNode->PayMethed = PayMethed;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _size++;

    }

    void InsertAtEnd(T value,string PayMethed) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->PayMethed = PayMethed;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;

        }
        _size++;
    }



    void DeleteNode(Node*& NodeToDelete) {


        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        _size--;
        delete NodeToDelete;
    }

    void DeleteFirstNode() {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _size--;
    }


    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _size--;
    }

    void Clear() {

        while (_size > 0) {
            DeleteFirstNode();
        }
    }
    int Size() {

        return  _size;
    }
    void PrintNodeDetails(Node* Current)
    {
        if (Current->prev != NULL)
            cout << Current->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << Current->value << " <--> ";

        if (Current->next != NULL)
            cout << Current->next->value << "\n";
        else
            cout << "NULL";

    }

    // Print the linked list
    void PrintListDetails()

    {
        Node* Current = head;
        cout << "\n\n";
        while (Current != NULL) {
            PrintNodeDetails(Current);
            Current = Current->next;
        }
    }

    Node* GetNode(int index)
    {

        int Counter = 0;
        if (index > _size - 1 || index < 0)return NULL;

        Node* Current = head;
        while (Current != NULL && (Current->next != NULL)) {
            if (Counter == index)
                break;
            Current = Current->next;
            Counter++;

        }
        return Current;
    }

    T GetItem(int index) {
        Node* ItemNode = GetNode(index);
        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;
    }
    bool UdateItem(int Index, T NewValue,string NewPayMethed) {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL) {
            ItemNode->value = NewValue;
            ItemNode.PayMethed = NewPayMethed;

            return true;
        }
        else
            return false;


    }
    bool InsertAfter(int Index, T value,string PayMethed) {

        Node* current = GetNode(Index);
        if (current != NULL)
        {
            InsertAfter(current, value, PayMethed);
            return true;
        }
        else
            return false;
        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */


    }

    void PrintList()
    {
        Node* Current = head;
        cout << "NULL <--> ";
        while (Current != NULL) {
            cout << Current->PayMethed <<"  :  "<< Current->value << " <--> ";
            Current = Current->next;
        }
        cout << "NULL";

    }

    void Reverse() {

        Node* Current = head;

        Node* temp = nullptr;
        while (Current != NULL) {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }
        if (temp != nullptr) {

            head = temp->prev;
        }
    }

};

