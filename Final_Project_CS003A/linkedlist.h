/**************************************************************************
 *  Author          : Gurpal Kundi
 *  Assignment      : 11
 *  Class           : CS003A
 *  Section         : MTWR: 7:30a-9:30a
 *  Due Date        : 12/07/2017
 *************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

template<typename E>
struct Node
{
    //data table
    E data;                     //IN - E value to store
    Node *next;                 //IN - Node pointer to link nodes
    Node(E data)
       : data(data), next(0) {} //IN - struct constructor
};

template <typename E>
class LinkedList
{

private:

    //ATTRUBUTES
    Node<E> *head;              //IN - Node pointer to head node of list
    Node<E> *tail;              //IN - Node pointer to last node in list

public:

    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/

    LinkedList();
    LinkedList
        (const LinkedList<E> &); //IN - LinkedList to copy
    ~LinkedList();

    /*************
    ** ACCESSOR **
    *************/

    void display() const;
    bool isEmpty() const;
    string toString() const;

    /*************
    ** MUTATORS **
    *************/

    void push_front(E value);       //IN - value to create new Node
                                    //     struct
    void push_back(E value);        //IN - value to create new Node
                                    //     struct
    void pop_front()
        throw(int);                 //IN - int to throw

    const E & front() const
        throw(int);                 //IN - int to throw

    const E & back() const
        throw(int);                 //IN - int to throw

    void select_sort()
        throw(int);                 //IN - int to throw

    void insert_sorted(E value);    //IN - value to create new Node
                                    //     struct
    void remove_duplicates()
        throw(int);                 //IN - int to throw

    const LinkedList<E> & operator=
        (const LinkedList<E> &);    //IN - LinkedList object to be copied
};

/**************************************************************************
*  Class LinkedList
*   This class creates an object that is a linked list of Node
*       stuctures. Node structures are comprised of a data value,
*       a linking Node struct pointer, and a struct consrtuctor. Class
*       contains two private member variables, both are Node struct
*       pointers. They correspond to the pointer pointing to the head of
*       the linked list and the pointer pointing to the tail of the linked
*       list. Class contains two constructors: a default constructor and an
*       overloaded copy constructor specific for class. Class contains two
*       public accessor function: display() and isEmpty(). Class contains
*       nine mutator public member functions: push_back(), push_front(),
*       pop_front(), select_sort(), insert_sorted(), remove_duplicates,
*       front(), back(), and overloaded assignment operator.
*
**************************************************************************/

        /******************************
        ** CONSTRUCTORS & DESTRUCTOR **
        ******************************/

/**************************************************************************
* LinkedList()
*
*   Constructs default class object. Head and tail pointers are set to
*   NULL.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
*   Creates class object
**************************************************************************/


/**************************************************************************
* LinkedList(const LinkedList<E> &list)
*
*   Constructs class object. Takes in a LinkedList class object as an arg
*       by constant reference. Creates a LinkedList class object that is a
*       deep copy of the argument.
*__________________________________________________________________________
*   One parameter:
*       const LinkedList<E> &list       //IN - LinkedList object to copy
*__________________________________________________________________________
*   Returns nothing
*   Creates class object
**************************************************************************/


/**************************************************************************
* ~LinkedList()
*
*   De-allocates all dynamically allocated memory. Uses a temp Node
*       pointer to traverse linked list of Node structures. Uses head
*       as to start at the front of the linked list. Sets temp and tail
*       Node pointers to NULL.
*__________________________________________________________________________
*   Called automatically
*__________________________________________________________________________
*   De-allocates all dynamic memory
**************************************************************************/

        /**************
        ** ACCESSORS **
        **************/

/**************************************************************************
* void display() const
*
*   Public member function. Displays linked list of Node structures.
*       Uses a temp Node pointer to traverse the linked list. Starts
*       from the front
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
*   Outputs list to console
**************************************************************************/


/**************************************************************************
* isEmpty() const
*
*   Public member function. Returns bool as true if LinkedList class object
*       is an empty list;
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns bool
**************************************************************************/


/**************************************************************************
* string toString() const
*
*   Public member function. Returns string of all data values in LinkedList
*       object. Formatted with spaces in between.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns string
**************************************************************************/

        /*************
        ** MUTATORS **
        *************/

/**************************************************************************
* void push_front(E value)
*
*   Public member function. Takes in E parameter by value. Uses temp
*       Node pointer and Node struct constructor to create a new
*       Node struct with integer value of parameter stored in Node
*       struct data variable. Links new Node to front of linked list of
*       Nodes using temp, head, and next pointers. Sets tail to point to
*       new Node if necessary.
*__________________________________________________________________________
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void push_back(E value)
*
*   Public member function. Takes in integer parameter by value. Uses temp
*       Node pointer and Node struct constructor to create a new
*       Node struct with integer value of parameter stored in Node
*       struct data variable. Links new Node to back of linked list of
*       Nodes using temp, head, and next pointers. Sets tail to point to
*       new Node if necessary.
*__________________________________________________________________________
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void pop_front() throw(int)
*
*   Public member function. Deletes node pointed to by head pointer.
*       Uses temp Node pointer to allow head pointer to be re-assigned
*       to next Node struct in linked list. Does nothing if the list is
*       already empty.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* const E & front() const throw(int)
*
*   Public member function. Returns E value by const ref corresponding to
*       E value within front Node in LinkedList object. Throws exception
*       if list isEmpty.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns E value by const reference
**************************************************************************/


/**************************************************************************
* const E & back() const throw(int)
*
*   Public member function. Returns E value by const ref corresponding to
*       E value within back Node in LinkedList object. Throws exception
*       list isEmpty.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns E value by const reference
**************************************************************************/


/**************************************************************************
* void select_sort() throw(int)
*
*   Public member function. This function sorts the list into ascending
*       order using the selection sort algorithm. Two temp Node pointers
*       are created. They are set to traverse the linked list according
*       to the selection sort algorithm. Exchange of data values is done
*       using a temp int variable. Throws excpetion is list is empty.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void insert_sorted(E value)
*
*   Public member function. This function assumes the values in the list
*       are in sorted (ascending) order and inserts the data into the
*       appropriate position in the list (so that the values will still be
*       in ascending order after insertion). Function creates a temp
*       Node pointer to point to new Node containing value to insert.
*       Makes sure list is not empty. Creates two other temp Node
*       pointers to help traverse linked list. Function compares value
*       in new IntNode against Nodes in linked list until a higher
*       value is found. Then new Node is inserted into linked list
*       before the higher value Node.
*__________________________________________________________________________
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void remove_duplicates() throw(int)
*
*   Public member function. This function removes all values (actually
*       removes the nodes that contain the value) that are duplicates of a
*       value that already exists in the list. Always removes the later
*       duplicate, not the first instance of the duplicate. This function
*       does NOT assume the data is sorted. Three temp Node pointers
*       are created. temp1 pointer is set to be the head. temp2 is set
*       to cycle through the linked list. Comparison between Nodes pointed
*       to by temp1 and temp2 is made. If a duplicate is found, temp3
*       pointer is set and deleted. temp1 pointer is then incremented to
*       next Node and process repeats until end of list. Throws excpetion
*       if list is empty.
*__________________________________________________________________________
*   No parameter
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* LinkedList<E> & operator=(const LinkedList<E> &list)
*
*   Copies class object. Takes in a LinkedList class object as an argument
*       by constant reference. Creates a LinkedList class object that is a
*       deep copy of the argument.
*__________________________________________________________________________
*   One parameter:
*       const LinkedList<E> &list       //IN - LinkedList object to copy
*__________________________________________________________________________
*   Returns LinkedList object by reference
*   Creates class object
**************************************************************************/

//DEFINITIONS

/**************************************************************************
* Constructor LinkedList(): class LinkedList
*__________________________________________________________________________
*   Constructs default class object. Head and tail pointers are set to
*   NULL.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
*   Creates class object
**************************************************************************/
template <typename E>
LinkedList<E>::LinkedList()
{
    //PROC - set head and tail Node pointers to NULL
    head = NULL;
    tail = NULL;
}

/**************************************************************************
* Constructor LinkedList(const LinkedList<E> &list):
*   class LinkedList
*__________________________________________________________________________
*   Constructs class object. Takes in a LinkedList class object as an arg
*       by constant reference. Creates a LinkedList class object that is a
*       deep copy of the argument.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   One parameter:
*       const LinkedList<E> &list       //IN - LinkedList object to copy
*
* POSTCONDITIONS:
*   Returns nothing
*   Creates class object
**************************************************************************/
template <typename E>
LinkedList<E>::LinkedList
    (const LinkedList<E> &list)         //IN - LinkedList object to copy
{
    //data table
    Node<E> *temp1;         //IN & PROC - Node pointer for new object
    Node<E> *temp2;         //IN & PROC - Node pointer for object to be
                            //            copied

    //PROC - set temp2 to head of LinkedList object to be copied
    temp2 = list.head;

    //PROC - make sure LinkedList object to be copied is not empty
    //       if empty, then set head and tail to NULL
    if(list.isEmpty())
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        //PROC - create new Node struct pointed to by head that contains
        //       data value copied from Node struct pointed to be temp2
        head = new Node<E>(temp2->data);

        //PROC - set temp1 to head
        temp1 = head;

        //PROC - evaluate if setting tail is appropriate (that end of
        //       LinkedList is reached)
        if(temp2->next == NULL)
        {
            //PROC - set tail to temp1
            tail = temp1;

            //PROC - set next pointer of Node struct pointed to by temp1
            //       to NULL. Effectively terminating LinkedList
            temp1->next = NULL;
        }

            //PROC - set a while loop to traverse through LinkedList object
            //       to be copied. Evalation of temp2->next as being NULL
            //       terminates loop
        while(temp2->next != NULL)
        {
            //PROC - move temp1 and temp2 pointers down corresponding
            //       LinkedList object list of Node structs
            temp2 = temp2->next;

            //PROC - set Node struct's next pointer to point to a
            //       new Node struct with data value copied from
            //       Node struct pointed to by temp2
            temp1->next = new Node<E>(temp2->data);

            temp1 = temp1->next;

            //PROC - evaulate if setting tail is appropriate (that
            //       end of LinkedList is reached on next iteration)
            if(temp2->next == NULL)
            {
                //PROC - set tail to temp1
                tail = temp1;

                //PROC - set next pointer of Node struct pointed to
                //       by temp1 to NULL. Terminating LinkedList
                temp1->next = NULL;
            }
        }
    }
}

/**************************************************************************
* Destructor ~LinkedList(): class LinkedList
*__________________________________________________________________________
*   De-allocates all dynamically allocated memory. Uses a temp Node
*       pointer to traverse linked list of Node structures. Uses head
*       as to start at the front of the linked list. Sets temp and tail
*       Node pointers to NULL.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linked.h
*   Called automatically
*
* POSTCONDITIONS:
*   De-allocates all dynamic memory
**************************************************************************/
template <typename E>
LinkedList<E>::~LinkedList()
{
    //data table
    Node<E> *temp;    //IN & PROC - Node pointer to traverse linked list

    //PROC - sets temp pointer to head if head is pointing to NULL. If head
    //       is not pointing to NULL sets temp to head->next.
    if(!isEmpty())
        temp = head->next;
    else
        temp = head;

    //PROC - uses temp to traverse linked list. De-allocates Node
    //       pointed to by head. Re-assigns head to temp. Moves temp to
    //       point to next Node in list until temp is pointing to NULL.
    while(temp != NULL)
    {
        delete head;

        head = temp;

        temp = head->next;
    }

    //PROC - de-allocates last node
    delete head;

    //PROC - prevents dangling pointers. Sets head and tail back to NULL
    tail = NULL;
    head = NULL;
}


/**************************************************************************
* Method void display() const: class LinkedList
*__________________________________________________________________________
*   Public member function. Displays linked list of Node structures.
*       Uses a temp Node pointer to traverse the linked list. Starts
*       from the front
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
*   Outputs list to console
**************************************************************************/
template <typename E>
void LinkedList<E>::display() const
{
    //data table
    Node<E> *temp;    //IN & PROC - Node pointer to traverse linked list

    //PROC - sets temp to point to head of
    temp = head;

    //PROC & OUT - traverses and outputs data for each Node of linked
    //             list. Due to format, an initial if-statement is needed
    //             so that while-loop can insert spaces correctly
    if(!isEmpty())
    {
        cout << temp->data;

        temp = temp->next;
    }

    while(temp != NULL)
    {
        cout << " " << temp->data;

        temp = temp->next;
    }

}

/**************************************************************************
* Method bool isEmpty() const: class LinkedList
*__________________________________________________________________________
*   Public member function. Returns bool as true if LinkedList class object
*       is an empty list;
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns bool
**************************************************************************/
template <typename E>
bool LinkedList<E>::isEmpty() const
{
    //data table
    bool temp = false;      //IN - bool initialized to false

    //PROC - determines if list is empty
    if((head == NULL) && (tail == NULL))
        temp = true;

    //PROC - return bool
    return temp;
}

/**************************************************************************
* Method string toString() const: class LinkedList
*__________________________________________________________________________
*   Public member function. Returns string of all data values in LinkedList
*       object. Formatted with spaces in between.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns string
**************************************************************************/
template <typename E>
string LinkedList<E>::toString() const
{
    //data table
    stringstream tempSString;           //IN - temp ss var
    Node<E> *temp;                      //IN - temp Node pointer

    //PROC - set temp Node pointer to head of LinkedList object
    temp = head;

    //PROC - use while loop to traverse LinkedList
    while (temp != NULL)
    {
        //PROC - insert data values within LinkedList into ss var
        tempSString << temp->data << " ";
        temp = temp->next;      
    }

    //PROC - return ss var converted to string
    return tempSString.str();
}

/**************************************************************************
* Method void push_front(E value): class LinkedList
*__________________________________________________________________________
*   Public member function. Takes in E parameter by value. Uses temp
*       Node pointer and Node struct constructor to create a new
*       Node struct with integer value of parameter stored in Node
*       struct data variable. Links new Node to front of linked list of
*       Nodes using temp, head, and next pointers. Sets tail to point to
*       new Node if necessary.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linklist.h
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::push_front(E value) //IN - E value to create new
                                        //     Node struct
{
    //data table
    Node<E> *temp;     //IN & PROC - Node pointer to create new Node
                    //            struct

    //PROC - creates a new Node struct with integer value of parameter
    //       stored in Node struct data variable
    temp = new Node<E>(value);

    //PROC - sets next pointer within new Node struct to head pointer
    temp->next = head;

    //PROC - sets head pointer to temp
    head = temp;

    //PROC - sets tail pointer to temp if necessary
    if(tail == NULL)
        tail = temp;
}

/**************************************************************************
* Method void push_back(E value): class LinkedList
*__________________________________________________________________________
*   Public member function. Takes in integer parameter by value. Uses temp
*       Node pointer and Node struct constructor to create a new
*       Node struct with integer value of parameter stored in Node
*       struct data variable. Links new Node to back of linked list of
*       Nodes using temp, head, and next pointers. Sets tail to point to
*       new Node if necessary.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::push_back(E value)  //IN - E value to create new
                                        //     Node struct
{
    //data table
    Node<E> *temp;     //IN & PROC - Node pointer to create new Node
                    //            struct

    //PROC - creates a new Node struct with integer value of parameter
    //       stored in Node struct data variable
    temp = new Node<E>(value);

    //PROC - if empty list set node in list
    if(isEmpty())
    {
        //PROC - sets next pointer within new Node struct to head
        //       pointer
        temp->next = head;

        //PROC - sets head pointer to temp
        head = temp;

        //PROC - sets tail pointer to temp
        tail = temp;
    }
    else
    {
        //PROC - set new Node link pointer to NULL
        temp->next = NULL;

        //PROC - set new Node at end of list
        tail->next = temp;

        //PROC - set tail to new Node which is now last node in list
        tail = temp;
    }
}


/**************************************************************************
* Method void pop_front() throw(int): class LinkedList
*__________________________________________________________________________
*   Public member function. Deletes node pointed to by head pointer.
*       Uses temp Node pointer to allow head pointer to be re-assigned
*       to next Node struct in linked list. Does nothing if the list is
*       already empty.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::pop_front()
    throw(int)            //IN - int to throw
{
    //data table
    Node<E> *temp;  //IN & PROC - Node pointer to allow re-assignment
                    //            of head pointer

    //PROC - checks if list is empty
    if(isEmpty())
    {
        throw(1);
    }

    //PROC - sets temp pointer to next Node pointer in Node
    //       pointed to by head
    temp = head->next;

    //PROC - de-allocates memory pointed to by head pointer
    delete head;

    //PROC - re-assigns head pointer
    head = temp;

    //PROC - resets tail pointer if necessary (empty list)
    if(head == NULL)
        tail = NULL;

}

/**************************************************************************
* Method const E & front() const throw(int): class LinkedList
*__________________________________________________________________________
*   Public member function. Returns E value by const ref corresponding to
*       E value within front Node in LinkedList object. Throws exception
*       if exception generated.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns E value by const reference
**************************************************************************/
template <typename E>
const E & LinkedList<E>::front() const
    throw(int)                    //IN - int to throw
{
    if (isEmpty())
    {
        throw(1);
    }

    return head->data;
}

/**************************************************************************
* Method const E & back() const throw(int): class LinkedList
*__________________________________________________________________________
*   Public member function. Returns E value by const ref corresponding to
*       E value within back Node in LinkedList object. Throws exception
*       if exception generated.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns E value by const reference
**************************************************************************/
template <typename E>
const E & LinkedList<E>::back() const
    throw(int)                          //IN - int to throw
{
    if (isEmpty())
    {
        throw(1);
    }

    return tail->data;
}

/**************************************************************************
* Method void select_sort() throws(int): class LinkedList
*__________________________________________________________________________
*   Public member function. This function sorts the list into ascending
*       order using the selection sort algorithm. Two temp Node pointers
*       are created. They are set to traverse the linked list according
*       to the selection sort algorithm. Exchange of data values is done
*       using a temp int variable. Throws exception if list is empty.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkelist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::select_sort()
    throw(int)                      //IN - int to throw
{
    //data table
    Node<E> *temp1;                 //IN - temp Node pointer
    Node<E> *temp2;                 //IN - temp Node pointer
    E temp;                         //IN - temp E variable

    if(isEmpty())
        throw(1);

    //PROC - set temp1 to head Node pointer
    temp1 = head;

    //PROC - makes sure linked list is not empty. If not sets temp2 pointer
    //       to next node in linked list after temp1
    if((!isEmpty()) && (temp1->next != NULL))
    {
        temp2 = temp1->next;

        //PROC - double while loop. The outside one cycles temp1 pointer
        //       through linked list. The inner loop cycles temp2 pointer.
        //       Essentially like a double nested for-loop to sort an array
        while(temp2 != NULL)
        {
            while (temp2 != NULL)
            {
                if(temp2->data < temp1->data)
                {
                    //PROC - performs the selection sort algorithm exchange
                    temp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = temp;
                }

                //PROC - increments temp2 pointer
                temp2 = temp2->next;
            }

            //PROC - reset temp1 to next IntNode pointer, and temp2 pointer
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
    }
}

/**************************************************************************
* Method void insert_sorted(E value): class LinkedList
*__________________________________________________________________________
*   Public member function. This function assumes the values in the list
*       are in sorted (ascending) order and inserts the data into the
*       appropriate position in the list (so that the values will still be
*       in ascending order after insertion). Function creates a temp
*       Node pointer to point to new Node containing value to insert.
*       Makes sure list is not empty. Creates two other temp Node
*       pointers to help traverse linked list. Function compares value
*       in new IntNode against Nodes in linked list until a higher
*       value is found. Then new Node is inserted into linked list
*       before the higher value Node.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include LinkedList.h
*   One parameter:
*       E value                         //IN - E value to create new
*                                       //     Node struct
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::insert_sorted(E value)
{
    //data table
    Node<E> *temp1;             //IN - temp Node pointer to insert
                                //     new Node
    Node<E> *temp2;             //IN - temp Node pointer to help
                                //     traverse linked list
    Node<E> *temp3;             //IN - temp Node pointer to help
                                //     traverse linked list

    //PROC - create new Node containing value passed in by parameter
    temp1 = new Node<E>(value);

    //PROC - make sure list is not empty
    if ((!isEmpty()) && (head->next != NULL))
    {
        //PROC - set temp Node pointer to head of linked list
        temp2 = head;

        //PROC - while loop to traverse linked list
        while(temp2 != NULL)
        {
            //PROC - compare data values inside temp2 Node and Node
            //       to insert
            if (value < temp2->data)
            {
                //PROC - insert new Node at front if it meet critera
                if(temp2 == head)
                {
                    push_front(value);
                    break;
                }

                //PROC - insert Node in middle if it meets criteria
                temp3->next = temp1;
                temp1->next = temp2;
                break;
            }

            //PROC - increment temp Node pointer to traverse linked list
            temp3 = temp2;
            temp2 = temp2->next;
        }

        //PROC - insert new Node at back if it meets criteria
        if (temp2 == NULL)
        {
            push_back(value);
        }
    }
}

/**************************************************************************
* Method void remove_duplicates() throw(int): class LinkedList
*__________________________________________________________________________
*   Public member function. This function removes all values (actually
*       removes the nodes that contain the value) that are duplicates of a
*       value that already exists in the list. Always removes the later
*       duplicate, not the first instance of the duplicate. This function
*       does NOT assume the data is sorted. Three temp Node pointers
*       are created. temp1 pointer is set to be the head. temp2 is set
*       to cycle through the linked list. Comparison between Nodes pointed
*       to by temp1 and temp2 is made. If a duplicate is found, temp3
*       pointer is set and deleted. temp1 pointer is then incremented to
*       next Node and process repeats until end of list. Throws excpetion
*       if list is empty.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
template <typename E>
void LinkedList<E>::remove_duplicates()
    throw(int)                  //IN - int to throw
{
    //data table
    Node<E> *temp1;             //IN - temp Node pointer to help
                                //     traverse linked list
    Node<E> *temp2;             //IN - temp Node pointer to help
                                //     traverse linked list
    Node<E> *temp3;             //IN - temp Node pointer to delete Node

    if(isEmpty())
        throw(1);

    //PROC - default set to NULL
    temp3 = NULL;

    //PROC - make sure list is not empty
    if((head != NULL) && (head->next != NULL))
    {
        //PROC - set temp1
        temp1 = head;

        //PROC - double while loop. The outside one cycles temp1 pointer
        //       through linked list. The inner loop cycles temp2
        //       pointer. Essentially like a double nested for-loop to sort
        //       an array
        while(temp1 != NULL)
        {
            //PROC - set temp2
            temp2 = temp1;

            while (temp2->next != NULL)
            {
                //PROC - checks if data value of temp2 node is duplicate
                if(temp1->data == temp2->next->data)
                {
                        temp3 = temp2->next;

                        //PROC - unlink duplicate node from list
                        temp2->next = temp2->next->next;

                        //PROC - deletes node to be removed
                        delete temp3;

                        temp3 = NULL;

                        if(temp2->next == NULL)
                            tail = temp2;
                }
                else
                    temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }
    }
}

/**************************************************************************
* Method LinkedList<E> & operator=(const LinkedList<E> &list):
*   class LinkedList
*__________________________________________________________________________
*   Copies class object. Takes in a LinkedList class object as an argument
*       by constant reference. Creates a LinkedList class object that is a
*       deep copy of the argument.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include linkedlist.h
*   One parameter:
*       const LinkedList<E> &list       //IN - LinkedList object to copy
*
* POSTCONDITIONS:
*   Returns LinkedList object by reference
*   Creates class object
**************************************************************************/
template <typename E>
const LinkedList<E> & LinkedList<E>::operator=
    (const LinkedList<E> &list)         //IN - LinkedList object to copy
{
    //data table
    Node<E> *temp1;         //IN & PROC - Node pointer for new object,
                            //            and to help delete old list
    Node<E> *temp2;         //IN & PROC - Node pointer for object to be
                            //            copied;

    //PROC - uses while loop to delete old list
    while(head != NULL)
    {
        temp1 = head->next;

        delete head;

        head = temp1;
    }

    //PROC - resets tail to NULL
    tail = NULL;

    //PROC - set temp2 to head of List object to be copied
    temp2 = list.head;

    //PROC - make sure List object to be copied is not empty
    //       if empty, then set head and tail to NULL
    if(list.isEmpty())
    {
        return *this;
    }
    else
    {
        //PROC - create new Node struct pointed to by head that contains
        //       data value copied from Node struct pointed to be temp2
        head = new Node<E>(temp2->data);

        //PROC - set temp1 to head
        temp1 = head;

        //PROC - evaluate if setting tail is appropriate (that end of
        //       List is reached)
        if(temp2->next == NULL)
        {
            //PROC - set tail to temp1
            tail = temp1;

            //PROC - set next pointer of Node struct pointed to by temp1
            //       to NULL. Effectively terminating List
            temp1->next = NULL;
        }

            //PROC - set a while loop to traverse through List object
            //       to be copied. Evaluation of temp2->next as being NULL
            //       terminates loop
        while(temp2->next != NULL)
        {
            //PROC - move temp1 and temp2 pointers down corresponding
            //       LinkedList object list of Node structs
            temp2 = temp2->next;

            //PROC - set Node struct's next pointer to point to a
            //       new Node struct with data value copied from
            //       Node struct pointed to by temp2
            temp1->next = new Node<E>(temp2->data);

            temp1 = temp1->next;

            //PROC - evaulate if setting tail is appropriate (that
            //       end of LinkedList is reached on next iteration)
            if(temp2->next == NULL)
            {
                //PROC - set tail to temp1
                tail = temp1;

                //PROC - set next pointer of Node struct pointed to
                //       by temp1 to NULL. Terminating LinkedList
                temp1->next = NULL;
            }
        }
    }

    //PROC - return LinkedList object
    return *this;
}
#endif // LINKEDLIST_H
