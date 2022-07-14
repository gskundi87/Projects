#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QRadioButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <vector>
#include "linkedlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/

    explicit MainWindow
        (QWidget *parent = 0);      //IN - QWidget initialized to zero
    ~MainWindow();

private slots:

    /*************
    ** MUTATORS **
    *************/

    void displayHandler();
    void create_listHandler();
    void create_listHandler
        (LinkedList<int>);          //IN - LinkedList type to copy
    void create_listHandler
        (LinkedList<std::string>);       //IN - LinkedList type to copy
    void create_listHandler
        (LinkedList<double>);       //IN - LinkedList type to copy
    void push_backHandler();
    void push_frontHandler();
    void pop_frontHandler();
    void select_sortHandler();
    void remove_duplicatesHandler();
    void copy_listHandler();

private:

    //ATTRIBUTES
    Ui::MainWindow *ui;             //IN - pointer to MainWindow object
    vector <LinkedList<int>> L1;    //IN - vector of LinkedList int types
    vector <LinkedList<string>> L2; //IN - vector of LinkedList str types
    vector <LinkedList<double>> L3; //IN - vector of LinkedList dbl types

    int intValue;               //IN - int value to push into LinkedList
    string stringValue;         //IN - string value to push into LinkedList
    double doubleValue;         //IN - double value to push into LinkedList

    int intCount;               //IN - int to count L1 vector elements
    int stringCount;            //IN - int to count L2 vector elements
    int doubleCount;            //IN - int to count L3 vector elements

    int indexRow;           //IN - int for selected QTableWidget item row
    int indexCol;           //IN - int for selected QTableWidget item col

    /**************
    ** ACCESSORS **
    **************/

    QString display_list();

    /*************
    ** MUTATORS **
    *************/

    void isItemChecked()
        noexcept(false);                 //PROC & OUT - int to throw exception
    void display(const QString &);  //IN - QString to display
};

/**************************************************************************
* Class MainWindow
*
**************************************************************************/

    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/

/**************************************************************************
* MainWindow(QWidget *parent): QMainWindow (parent), ui(new Ui::MainWindow)
*__________________________________________________________________________
*   Constructs default class object. Formats MainWindow Q objects.
*__________________________________________________________________________
*   One parameter:
*       QWidget *parent         //IN - QWidget class object pointer
*__________________________________________________________________________
*   Returns nothing
*   Creates class object
**************************************************************************/


/**************************************************************************
* ~MainWindow()
*
*   Virtual destructor. De-allocates memory pointer to by member variable
*       ui.
*__________________________________________________________________________
*   Called automatically
*__________________________________________________________________________
*   De-allocates all dynamic memory
**************************************************************************/

    /*************
    ** MUTATORS **
    *************/

/**************************************************************************
* void displayHandler() const
*
*   Private slot. Called upon display PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked and LinkedList class isEmpty()
*       method within try block. Throws exception if no QTableWidget item
*       is checked or if LinkedList class object is empty list. Displays
*       exception error message using private method display(). If no
*       exception generated calls display(display_list()).
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void create_listHandler() const
*
*   Private slot. Called upon createList PushButton clicked() signal.
*       Clears QTextBrowser displayOutput. Checks which RadioButton is
*       checked. Creates a temp default LinkedList<type> class object of
*       of type corresponding to checked RadioButton. Pushes temp object
*       into member variable vector of corresponding type. Creates a new
*       QTableWidgetItem class object and sets text of item to QString
*       corresponding to list type and list type vector element count.
*       Formats text alignment. Sets QTableWidget item corresponding to
*       column for list type, and row equal to list type vector element
*       count. If count exceeds displayed number of rows in QTableWidget
*       minus one, new row is inserted.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void create_listHandler(LinkedList<int> temp) const
*
*   Private slot. Overloaded function to accept LinkedList object as
*       parameter. Called upon createList PushButton clicked() signal.
*       Pushes LinkedList object passed in into member variable vector of
*       corresponding type. Creates a new QTableWidgetItem class object and
*       sets text of item to QString corresponding to list type and list
*       type vector element count. Formats text alignment. Sets
*       QTableWidget item corresponding to column for list type, and row
*       equal to list type vector element count. If count exceeds displayed
*       number of rows in QTableWidget minus one, new row is inserted.
*__________________________________________________________________________
*   One parameter:
*       LinkedList<int> temp        //IN - LinkedList object of type int
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void create_listHandler(LinkedList<string> temp) const
*
*   Private slot. Overloaded function to accept LinkedList object as
*       parameter. Called upon createList PushButton clicked() signal.
*       Pushes LinkedList object passed in into member variable vector of
*       corresponding type. Creates a new QTableWidgetItem class object and
*       sets text of item to QString corresponding to list type and list
*       type vector element count. Formats text alignment. Sets
*       QTableWidget item corresponding to column for list type, and row
*       equal to list type vector element count. If count exceeds displayed
*       number of rows in QTableWidget minus one, new row is inserted.
*__________________________________________________________________________
*   One parameter:
*       LinkedList<string> temp     //IN - LinkedList object of type string
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void create_listHandler(LinkedList<double> temp) const
*
*   Private slot. Overloaded function to accept LinkedList object as
*       parameter. Called upon createList PushButton clicked() signal.
*       Pushes LinkedList object passed in into member variable vector of
*       corresponding type. Creates a new QTableWidgetItem class object and
*       sets text of item to QString corresponding to list type and list
*       type vector element count. Formats text alignment. Sets
*       QTableWidget item corresponding to column for list type, and row
*       equal to list type vector element count. If count exceeds displayed
*       number of rows in QTableWidget minus one, new row is inserted.
*__________________________________________________________________________
*   One parameter:
*       LinkedList<double> temp     //IN - LinkedList object of type double
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void push_backHandler() const
*
*   Private slot. Called upon pushBack PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if no value entered
*       in QLineEdit. Displays exception error message using private
*       accesor method display(QString). If no exception generated converts
*       value entered in QLineEdit enterValue to corresponding data type
*       determined by checking column selected. Calls push_back method of
*       LinkedList class to push back converted value into LinkedList
*       of corresponding data type and vector member variable element
*       position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void push_frontHandler() const
*
*   Private slot. Called upon pushFront PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if no value entered
*       in QLineEdit. Displays exception error message using private
*       accesor method display(QString). If no exception generated converts
*       value entered in QLineEdit enterValue to corresponding data type
*       determined by checking column selected. Calls push_front method of
*       LinkedList class to push front converted value into LinkedList
*       of corresponding data type and vector member variable element
*       position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void pop_frontHandler() const
*
*   Private slot. Called upon popFront PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       pop_front method of LinkedList class of corresponding data type and
*       vector member variable element position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void select_sortHandler() const
*
*   Private slot. Called on selectSort PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       select_sort method of LinkedList class of corresponding data type
*       and vector member variable element position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void remove_duplicatesHandler() const
*
*   Private slot. Called on removeDuplicates PushButton clicked() signal.
*       Clears QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       remove_duplicates method of LinkedList class of corresponding data
*       type and vector member variable element position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void copy_listHandler() const
*
*   Private slot. Called on copyList PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked. Displays exception
*       error message using private accesor method display(QString). If no
*       exception generated  creates temp LinkedList object of proper data
*       type using copy constructor of LinkedList class and using
*       LinkedList object corresponding to item selected in QTableWidget as
*       LinkedList object to be copied. Calls overloaded
*       create_listHandler() method of LinkedList class of corresponding
*       data type and vector member variable element position.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/

    /**************
    ** ACCESSORS **
    **************/

/**************************************************************************
* void display_list() const
*
*   Private member function. Creates a temp string and Qstring var.
*       Evaluates which item in QTableWidget is selected using indexCol and
*       indexRow member variables. Calls LinkedList class toString() to
*       set temp string to data within LinkedList object. Converts temp
*       string to QString. Returns temp QString.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/

    /*************
    ** MUTATORS **
    *************/

/**************************************************************************
* void isItemChecked() const
*
*   Private member function. Sets indexRow and indexCol member variables to
*       negative one. Uses double nested for loop to evaluate each item
*       in QTableWidget with isItemSelected() member function of
*       QTableWidge class. If item is found to be selected indexRow and
*       indexCol are set to index values of for-loop and for-loop is
*       broken. If no item is selected then function throws int of
*       value = 0.
*__________________________________________________________________________
*   No parameters
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/


/**************************************************************************
* void display() const
*
*   Private member function. Accepts by const ref a QString variable. Sets
*       text of QTextBrowser to QString passed in.
*__________________________________________________________________________
*   One parameter:
*       const QString &output       //IN - QString to set text
*__________________________________________________________________________
*   Returns nothing
**************************************************************************/
#endif // MAINWINDOW_H
