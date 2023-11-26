/**************************************************************************
 *  Author          : Gurpal Kundi
 *  Assignment      : 11
 *  Class           : CS003A
 *  Section         : MTWR: 7:30a-9:30a
 *  Due Date        : 12/07/2017
 *************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**************************************************************************
* Constructor MainWindow(QWidget *parent):
*   QMainWindow (parent),
*   ui(new Ui::MainWindow):                 class MainWindow
*__________________________________________________________________________
*   Constructs default class object. Formats MainWindow Q objects.
*
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   One paramter:
*       QWidget *parent         //IN - QWidget class object pointer
*
* POSTCONDITIONS:
*   Returns nothing
*   Creates class object
**************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //PROC - setup MainWindow class object
    ui->setupUi(this);

    //PROC - deletes QTableWidget default item
    delete ui->tableWidget->item(0, 0);

    //IN & PROC - fixes QTextBrowser height and width
    ui->displayOutput->setFixedHeight(600);
    ui->displayOutput->setFixedWidth(500);

    //IN & PROC - sets QTableWidget headers, 1 = not visible, 0 = visible
    ui->tableWidget->verticalHeader()->setHidden(1);
    ui->tableWidget->horizontalHeader()->setHidden(0);

    //IN & PROC - fixes QTableWidget height and width
    ui->tableWidget->setFixedHeight(600);
    ui->tableWidget->setFixedWidth(800);

    //IN & PROC - sets QTableWidget column width
    ui->tableWidget->setColumnWidth(3, 30);

    //IN & PROC - initialize member variable vectors element counts to zero
    intCount = 0;
    stringCount = 0;
    doubleCount = 0;
}

/**************************************************************************
* Destructor ~MainWindow(): class MainWindow
*__________________________________________________________________________
*   Virtual destructor. De-allocates memory pointer to by member variable
*       ui.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   Called automatically
*
* POSTCONDITIONS:
*   De-allocates all dynamic memory
**************************************************************************/
MainWindow::~MainWindow()
{
    //PROC - delete dynamic memory
    delete ui;
    delete ui->centralWidget;
    delete ui->copyList;
    delete ui->createList;
    delete ui->display;
    delete ui->displayOutput;
    delete ui->doubleButton;
    delete ui->enterValue;
    delete ui->groupBox;
    delete ui->intButton;
    delete ui->label;
    delete ui->label_2;
    delete ui->selectSort;
    delete ui->popFront;
    delete ui->pushBack;
    delete ui->mainToolBar;
    delete ui->menuBar;
    delete ui->statusBar;
    delete ui->removeDuplicates;
    delete ui->pushFront;
    delete ui->stringButton;
    delete ui->tableWidget;

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            delete ui->tableWidget->item(i, j);
        }
    }
}

/**************************************************************************
* Method void displayHandler() const: class MainWindow
*__________________________________________________________________________
*   Private slot. Called upon display PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked and LinkedList class isEmpty()
*       method within try block. Throws exception if no QTableWidget item
*       is checked or if LinkedList class object is empty list. Displays
*       exception error message using private accesor method
*       display(QString). If no exception generated calls
*       display(display_list());
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::displayHandler()
{
    //PROC - clears QTextBrowser
    ui->displayOutput->clear();

    //PROC - try block
    try
    {
        //PROC - function call, can throw exception with int = 0 if no
        //       item checked
        isItemChecked();

        //PROC - checks column selected and uses indicated member variable
        //       vector LinkedList
        //       calls isEmpty LinkedList class method
        //       throws exception with int = 1 if list is empty
        if(indexCol == 0)
        {
            if(L1[indexRow].isEmpty())
                throw(1);
        }
        else if(indexCol == 1)
        {
            if(L2[indexRow].isEmpty())
                throw(1);
        }
        else if(indexCol == 2)
        {
            if(L3[indexRow].isEmpty())
                throw(1);
        }

        //PROC - if no exception displays list
        display(display_list());
    }
    //PROC - if exception generated, handles and outputs message
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");
        else if (x == 1)
            display("Empty List");
    }
}

/**************************************************************************
* Method void create_listHandler() const: class MainWindow
*__________________________________________________________________________
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
*       minus one, new row is inserted
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::create_listHandler()
{
    //PROC - clears QTextBrowser
    ui->displayOutput->clear();

    //PROC - checks which radio button is checked
    if (ui->intButton->isChecked())
    {
        //data table
        LinkedList<int> temp;    //IN - LinkedList of int type
        QString tempQString;     //IN - temp QString
        string tempString;       //IN - temp string

        //PROC - pushes back temp LinkedList object into member variable
        L1.push_back(temp);

        //PROC - creates QString
        tempString = "IntList " + to_string(intCount + 1);
        tempQString = QString::fromStdString(tempString);

        //PROC - creates new QTableWidgeitem
        QTableWidgetItem *intItem = new QTableWidgetItem;

        //PROC - sets text and formats QTableWidgetItem
        intItem->setText(tempQString);
        intItem->setTextAlignment(Qt::Alignment(5));

        //PROC - sets item in QTableWidget
        ui->tableWidget->setItem(intCount, 0, intItem);

        //PROC - increments intCount
        intCount++;

        //PROC - inserts new row if intCount exceeds row count minus one
        if(intCount > (ui->tableWidget->rowCount() - 1))
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }

    else if (ui->stringButton->isChecked())
    {
        //data table
        LinkedList<string> temp;     //IN - LinkedList of string type
        QString tempQString;         //IN - temp QString
        string tempString;           //IN - temp string

        //PROC - pushes back temp LinkedList object into member variable
        L2.push_back(temp);

        //PROC - creates QString
        tempString = "StringList " + to_string(stringCount + 1);
        tempQString = QString::fromStdString(tempString);

        //PROC - creates new QTableWidgeitem
        QTableWidgetItem *stringItem = new QTableWidgetItem;

        //PROC - sets text and formats QTableWidgetItem
        stringItem->setText(tempQString);
        stringItem->setTextAlignment(Qt::Alignment(5));

        //PROC - sets item in QTableWidget
        ui->tableWidget->setItem(stringCount, 1, stringItem);

        //PROC - increments stringCount
        stringCount++;

        //PROC - inserts new row if stringCount exceeds row count minus one
        if(stringCount > (ui->tableWidget->rowCount() - 1))
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }

    else if (ui->doubleButton->isChecked())
    {
        //data table
        LinkedList<double> temp;     //IN - LinkedList of double type
        QString tempQString;         //IN - temp QString
        string tempString;           //IN - temp string

        //PROC - pushes back temp LinkedList object into member variable
        L3.push_back(temp);

        //PROC - creates QString
        tempString = "DoubleList " + to_string(doubleCount + 1);
        tempQString = QString::fromStdString(tempString);

        //PROC - creates new QTableWidgeitem
        QTableWidgetItem *doubleItem = new QTableWidgetItem;

        //PROC - sets text and formats QTableWidgetItem
        doubleItem->setText(tempQString);
        doubleItem->setTextAlignment(Qt::Alignment(5));

        //PROC - sets item in QTableWidget
        ui->tableWidget->setItem(doubleCount, 2, doubleItem);

        //PROC - increments doubleCount
        doubleCount++;

        //PROC - inserts new row if stringCount exceeds row count minus one
        if(doubleCount > (ui->tableWidget->rowCount() - 1))
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }
}

/**************************************************************************
* Method void create_listHandler(LinkedList<int> temp) const:
*   class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   One parameter:
*       LinkedList<int> temp        //IN - LinkedList object of type int
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::create_listHandler
    (LinkedList<int> temp)          //IN - LinkedList object of type int
{
    //data table
    QString tempQString;     //IN - temp QString
    string tempString;       //IN - temp string

    //PROC - pushes back temp LinkedList object into member variable
    L1.push_back(temp);

    //PROC - creates QString
    tempString = "IntList " + to_string(intCount + 1);
    tempQString = QString::fromStdString(tempString);

    //PROC - creates new QTableWidgeitem
    QTableWidgetItem *intItem = new QTableWidgetItem;

    //PROC - sets text and formats QTableWidgetItem
    intItem->setText(tempQString);
    intItem->setTextAlignment(Qt::Alignment(5));

    //PROC - sets item in QTableWidget
    ui->tableWidget->setItem(intCount, 0, intItem);

    //PROC - increments intCount
    intCount++;

    //PROC - inserts new row if intCount exceeds row count minus one
    if(intCount > (ui->tableWidget->rowCount() - 1))
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

/**************************************************************************
* Method void create_listHandler(LinkedList<string> temp) const:
*   class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   One parameter:
*       LinkedList<string> temp     //IN - LinkedList object of type string
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::create_listHandler
    (LinkedList<string> temp)       //IN - LinkedList object of type string
{
    //data table
    QString tempQString;         //IN - temp QString
    string tempString;           //IN - temp string

    //PROC - pushes back temp LinkedList object into member variable
    L2.push_back(temp);

    //PROC - creates QString
    tempString = "StringList " + to_string(stringCount + 1);
    tempQString = QString::fromStdString(tempString);

    //PROC - creates new QTableWidgeitem
    QTableWidgetItem *stringItem = new QTableWidgetItem;

    //PROC - sets text and formats QTableWidgetItem
    stringItem->setText(tempQString);
    stringItem->setTextAlignment(Qt::Alignment(5));

    //PROC - sets item in QTableWidget
    ui->tableWidget->setItem(stringCount, 1, stringItem);

    //PROC - increments stringCount
    stringCount++;

    //PROC - inserts new row if stringCount exceeds row count minus one
    if(stringCount > (ui->tableWidget->rowCount() - 1))
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

/**************************************************************************
* Method void create_listHandler(LinkedList<double> temp) const:
*   class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   One parameter:
*       LinkedList<double> temp     //IN - LinkedList object of type double
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::create_listHandler
    (LinkedList<double> temp)       //IN - LinkedList object of type double
{
    //data table
    QString tempQString;         //IN - temp QString
    string tempString;           //IN - temp string

    //PROC - pushes back temp LinkedList object into member variable
    L3.push_back(temp);

    //PROC - creates QString
    tempString = "DoubleList " + to_string(doubleCount + 1);
    tempQString = QString::fromStdString(tempString);

    //PROC - creates new QTableWidgeitem
    QTableWidgetItem *doubleItem = new QTableWidgetItem;

    //PROC - sets text and formats QTableWidgetItem
    doubleItem->setText(tempQString);
    doubleItem->setTextAlignment(Qt::Alignment(5));

    //PROC - sets item in QTableWidget
    ui->tableWidget->setItem(doubleCount, 2, doubleItem);

    //PROC - increments doubleCount
    doubleCount++;

    //PROC - inserts new row if stringCount exceeds row count minus one
    if(doubleCount > (ui->tableWidget->rowCount() - 1))
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

/**************************************************************************
* Method void push_backHandler() const: class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::push_backHandler()
{
    //PROC - clears QTextBrowser
    ui->displayOutput->clear();

    //PROC - try block
    try
    {
        //PROC - function call, throws int = 0 if no item checked
        isItemChecked();

        //PROC - throws int = 1 if no value entered
        if(ui->enterValue->text() == "")
            throw(1);

        //PROC- determines data type by evaluating column
        //      parses entered value to data type
        //      pushes back parsed value into corresponding member variable
        //      at proper element position
        if(indexCol == 0)
        {
            intValue = ui->enterValue->text().toInt();
            L1[indexRow].push_back(intValue);
        }
        else if(indexCol == 1)
        {
            stringValue = ui->enterValue->text().toStdString();
            L2[indexRow].push_back(stringValue);
        }
        else if(indexCol == 2)
        {
            doubleValue = ui->enterValue->text().toDouble();
            L3[indexRow].push_back(doubleValue);
        }

        //PROC - clears QLineEdit
        ui->enterValue->clear();

        //PROC - displays LinkedList
        display(display_list());
    }

    //PROC - displays appropriate message if exception generated
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");

        else if (x == 1)
            display("Error. No Value Input.");

        //PROC - clears QLineEdit
        ui->enterValue->clear();
    }
}

/**************************************************************************
* Method void push_frontHandler() const: class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::push_frontHandler()
{
    //PROC - clears QLineEdit
    ui->displayOutput->clear();

    try
    {
        //PROC - function call, throws exception with int = 0 if no item
        //       selected
        isItemChecked();

        //PROC - throws exception with int = 1 if no value entered
        if(ui->enterValue->text() == "")
            throw(1);

        //PROC- determines data type by evaluating column
        //      parses entered value to data type
        //      push fronts parsed value into corresponding member variable
        //      at proper element position
        if(indexCol == 0)
        {
            intValue = ui->enterValue->text().toInt();
            L1[indexRow].push_front(intValue);
        }
        else if(indexCol == 1)
        {
            stringValue = ui->enterValue->text().toStdString();
            L2[indexRow].push_front(stringValue);
        }
        else if(indexCol == 2)
        {
            doubleValue = ui->enterValue->text().toDouble();
            L3[indexRow].push_front(doubleValue);
        }

        //PROC - clears QLineEdit
        ui->enterValue->clear();

        //PROC - displays LinkedList
        display(display_list());
    }

    //PROC - displays appropriate message if exception generated
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");

        else if (x == 1)
            display("Error. No Value Input.");

        //PROC - clears QLineEdit
        ui->enterValue->clear();
    }
}

/**************************************************************************
* Method void pop_frontHandler() const: class MainWindow
*__________________________________________________________________________
*   Private slot. Called upon popFront PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       pop_front method of LinkedList class of corresponding data type and
*       vector member variable element position.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::pop_frontHandler()
{
    //PROC - clears QLineEdit and QTextBrowser
    ui->displayOutput->clear();
    ui->enterValue->clear();

    try
    {
        //PROC - function call, throws exception with int = 0 if no item
        //       selected
        isItemChecked();

        //PROC- determines data type by evaluating column
        //      pop fronts corresponding member variable at proper element
        //      position
        //      pop_front() method throws exception with int = 1 if list
        //      is empty
        if(indexCol == 0)
        {
            L1[indexRow].pop_front();
        }
        else if(indexCol == 1)
        {
            L2[indexRow].pop_front();
        }
        else if(indexCol == 2)
        {
            L3[indexRow].pop_front();
        }

        //PROC - displays list
        display(display_list());
    }

    //PROC - displays appropriate message if exception generated
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");
        else if (x == 1)
            display("Empty List");
    }
}


/**************************************************************************
* Method void select_sortHandler() const: class MainWindow
*__________________________________________________________________________
*   Private slot. Called on selectSort PushButton clicked() signal. Clears
*       QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       select_sort method of LinkedList class of corresponding data type
*       and vector member variable element position.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::select_sortHandler()
{
    //PROC - clears QLineEdit and QTextBrowser
    ui->displayOutput->clear();
    ui->enterValue->clear();

    try
    {
        //PROC - function call, throws exception with int = 0 if no item
        //       selected
        isItemChecked();

        //PROC- determines data type by evaluating column
        //      select sorts corresponding member variable at proper
        //      element position
        //      select_sort() method throws exception with int = 1 if list
        //      is empty
        if(indexCol == 0)
        {
            L1[indexRow].select_sort();
        }
        else if(indexCol == 1)
        {
            L2[indexRow].select_sort();
        }
        else if(indexCol == 2)
        {
            L3[indexRow].select_sort();
        }

        //PROC - displays list
        display(display_list());
    }

    //PROC - displays appropriate message if exception generated
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");
        else if (x == 1)
            display("Empty List");
    }
}

/**************************************************************************
* Method void remove_duplicatesHandler() const: class MainWindow
*__________________________________________________________________________
*   Private slot. Called on removeDuplicates PushButton clicked() signal.
*       Clears QTextBrowser. Calls isItemChecked within try block. Throws
*       exception if no QTableWidget item is checked or if LinkedList
*       is empty list. Displays exception error message using private
*       accesor method display(QString). If no exception generated calls
*       remove_duplicates method of LinkedList class of corresponding data
*       type and vector member variable element position.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::remove_duplicatesHandler()
{
    //PROC - clears QLineEdit and QTextBrowser
    ui->displayOutput->clear();
    ui->enterValue->clear();

    try
    {
        //PROC - function call, throws exception with int = 0 if no item
        //       selected
        isItemChecked();

        //PROC- determines data type by evaluating column
        //      removes duplicates of corresponding member variable at
        //      proper element position
        //      remove_duplictes() method throws exception with int = 1 if
        //      list is empty
        if(indexCol == 0)
        {
            L1[indexRow].remove_duplicates();
        }
        else if(indexCol == 1)
        {
            L2[indexRow].remove_duplicates();
        }
        else if(indexCol == 2)
        {
            L3[indexRow].remove_duplicates();
        }

        //PROC - displays list
        display(display_list());
    }

    //PROC - displays appropriate message if exception generated
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");
        else if (x == 1)
            display("Empty List");
    }
}

/**************************************************************************
* Method void copy_listHandler() const: class MainWindow
*__________________________________________________________________________
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
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::copy_listHandler()
{
    //PROC - clears QLineEdit and QTextBrowser
    ui->displayOutput->clear();
    ui->enterValue->clear();

    try
    {
        //PROC - function call, throws exception with int = 0 if no item
        //       selected
        isItemChecked();

        //PROC- determines data type by evaluating column
        //      creates temp LinkedList of data type using copy
        //      constructor of LinkedList class.
        //      LinkedList to be copied is selected item in QTableWidget
        //      calls overloaded create_listHandler() for proper data type
        if(indexCol == 0)
        {
            LinkedList<int> temp(L1[indexRow]);
            create_listHandler(temp);
        }
        else if(indexCol == 1)
        {
            LinkedList<string> temp(L2[indexRow]);
            create_listHandler(temp);
        }
        else if(indexCol == 2)
        {
            LinkedList<double> temp(L3[indexRow]);
            create_listHandler(temp);
        }

        //PROC - displays list
        display(display_list());
    }

    //PROC - function call, throws exception with int = 0 if no item
    //       selected
    catch(int x)
    {
        if (x == 0)
            display("Error. No List Selected.");
    }
}

/**************************************************************************
* Method void display_list() const: class MainWindow
*__________________________________________________________________________
*   Private member function. Creates a temp string and Qstring var.
*       Evaluates which item in QTableWidget is selected using indexCol and
*       indexRow member variables. Calls LinkedList class toString() to
*       set temp string to data within LinkedList object. Converts temp
*       string to QString. Returns temp QString.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
QString MainWindow::display_list()
{
    //data table
    string tempString;      //IN - temp string to hold data from LinkedList
        //     object
    QString tempQString;    //IN - QString to return converted tempString

    //PROC - evaluates which item in QTableWidget is selected using
    //       indexCol and indexRow member variables
    //       calls LinkedList class toString() to set temp string to data
    //       within LinkedList object
    //       converts temp string to QString
    if(indexCol == 0)
    {
        tempString = L1[indexRow].toString();
        tempQString = QString::fromStdString(tempString);
    }
    else if(indexCol == 1)
    {
        tempString = L2[indexRow].toString();
        tempQString = QString::fromStdString(tempString);
    }
    else if(indexCol == 2)
    {
        tempString = L3[indexRow].toString();
        tempQString = QString::fromStdString(tempString);
    }

    //PROC - returns temp QString
    return tempQString;
}

/**************************************************************************
* Method void isItemChecked() const: class MainWindow
*__________________________________________________________________________
*   Private member function. Sets indexRow and indexCol member variables to
*       negative one. Uses double nested for loop to evaluate each item
*       in QTableWidget with isItemSelected() member function of
*       QTableWidge class. If item is found to be selected indexRow and
*       indexCol are set to index values of for-loop and for-loop is
*       broken. If no item is selected then function throws int of
*       value = 0.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   No parameters
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::isItemChecked()
{
    //PROC - set member variables to negative one
    indexRow = -1;
    indexCol = -1;

    //PROC - double nested for-loop to look for selected Widget item
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            //PROC - create temp Widget item pointer to evaluate
            QTableWidgetItem *tempItem = ui->tableWidget->item(i, j);

            //PROC - evaluate if item is selected and if so set member vars
            if(tempItem && tempItem->isSelected())
            {
                indexRow = i;
                indexCol = j;
                break;
            }
        }
    }

    //PROC - if no item selected throw int = 0
    if((indexRow == -1) && (indexCol == -1))
        throw(0);
}

/**************************************************************************
* Method void display() const: class MainWindow
*__________________________________________________________________________
*   Private member function. Accepts by const ref a QString variable. Sets
*       text of QTextBrowser to QString passed in.
*__________________________________________________________________________
* PRECONDITIONS:
*   Must include mainwindow.h
*   One parameter:
*       const QString &output       //IN - QString to set text
*
* POSTCONDITIONS:
*   Returns nothing
**************************************************************************/
void MainWindow::display
    (const QString &output)         //IN - QString to set text
{
    //PROC - sets text of QTextBrowser
    ui->displayOutput->setText(output);
}


