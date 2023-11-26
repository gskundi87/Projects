/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushBack;
    QLineEdit *enterValue;
    QTextBrowser *displayOutput;
    QGroupBox *groupBox;
    QRadioButton *intButton;
    QRadioButton *stringButton;
    QRadioButton *doubleButton;
    QPushButton *createList;
    QTableWidget *tableWidget;
    QPushButton *display;
    QPushButton *popFront;
    QLabel *label;
    QPushButton *pushFront;
    QPushButton *selectSort;
    QPushButton *removeDuplicates;
    QPushButton *copyList;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2000, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        pushBack = new QPushButton(centralWidget);
        pushBack->setObjectName("pushBack");
        pushBack->setGeometry(QRect(510, 100, 191, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushBack->sizePolicy().hasHeightForWidth());
        pushBack->setSizePolicy(sizePolicy1);
        enterValue = new QLineEdit(centralWidget);
        enterValue->setObjectName("enterValue");
        enterValue->setGeometry(QRect(30, 120, 331, 51));
        displayOutput = new QTextBrowser(centralWidget);
        displayOutput->setObjectName("displayOutput");
        displayOutput->setGeometry(QRect(1400, 300, 431, 181));
        sizePolicy.setHeightForWidth(displayOutput->sizePolicy().hasHeightForWidth());
        displayOutput->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 220, 331, 300));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setCheckable(false);
        intButton = new QRadioButton(groupBox);
        intButton->setObjectName("intButton");
        intButton->setGeometry(QRect(20, 75, 161, 40));
        sizePolicy.setHeightForWidth(intButton->sizePolicy().hasHeightForWidth());
        intButton->setSizePolicy(sizePolicy);
        intButton->setChecked(true);
        stringButton = new QRadioButton(groupBox);
        stringButton->setObjectName("stringButton");
        stringButton->setGeometry(QRect(20, 150, 161, 40));
        sizePolicy.setHeightForWidth(stringButton->sizePolicy().hasHeightForWidth());
        stringButton->setSizePolicy(sizePolicy);
        doubleButton = new QRadioButton(groupBox);
        doubleButton->setObjectName("doubleButton");
        doubleButton->setGeometry(QRect(20, 225, 161, 40));
        sizePolicy.setHeightForWidth(doubleButton->sizePolicy().hasHeightForWidth());
        doubleButton->setSizePolicy(sizePolicy);
        createList = new QPushButton(centralWidget);
        createList->setObjectName("createList");
        createList->setGeometry(QRect(30, 550, 191, 61));
        sizePolicy.setHeightForWidth(createList->sizePolicy().hasHeightForWidth());
        createList->setSizePolicy(sizePolicy);
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(500, 300, 291, 200));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setHighlightSections(false);
        display = new QPushButton(centralWidget);
        display->setObjectName("display");
        display->setGeometry(QRect(30, 710, 191, 61));
        popFront = new QPushButton(centralWidget);
        popFront->setObjectName("popFront");
        popFront->setGeometry(QRect(750, 100, 191, 61));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 191, 31));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        label->setFont(font);
        pushFront = new QPushButton(centralWidget);
        pushFront->setObjectName("pushFront");
        pushFront->setGeometry(QRect(510, 190, 191, 61));
        selectSort = new QPushButton(centralWidget);
        selectSort->setObjectName("selectSort");
        selectSort->setGeometry(QRect(990, 100, 250, 61));
        removeDuplicates = new QPushButton(centralWidget);
        removeDuplicates->setObjectName("removeDuplicates");
        removeDuplicates->setGeometry(QRect(990, 190, 250, 61));
        copyList = new QPushButton(centralWidget);
        copyList->setObjectName("copyList");
        copyList->setGeometry(QRect(30, 630, 191, 61));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1400, 250, 131, 31));
        QFont font1;
        font1.setBold(true);
        label_2->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 2000, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushBack, SIGNAL(clicked()), MainWindow, SLOT(push_backHandler()));
        QObject::connect(display, SIGNAL(clicked()), MainWindow, SLOT(displayHandler()));
        QObject::connect(tableWidget, &QTableWidget::currentItemChanged, displayOutput, qOverload<>(&QTextBrowser::clear));
        QObject::connect(popFront, SIGNAL(clicked()), MainWindow, SLOT(pop_frontHandler()));
        QObject::connect(pushFront, SIGNAL(clicked()), MainWindow, SLOT(push_frontHandler()));
        QObject::connect(selectSort, SIGNAL(clicked()), MainWindow, SLOT(select_sortHandler()));
        QObject::connect(removeDuplicates, SIGNAL(clicked()), MainWindow, SLOT(remove_duplicatesHandler()));
        QObject::connect(copyList, SIGNAL(clicked()), MainWindow, SLOT(copy_listHandler()));
        QObject::connect(createList, SIGNAL(clicked()), MainWindow, SLOT(create_listHandler()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Final Project", nullptr));
        pushBack->setText(QCoreApplication::translate("MainWindow", "push back", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Select Data Type", nullptr));
        intButton->setText(QCoreApplication::translate("MainWindow", "Integer", nullptr));
        stringButton->setText(QCoreApplication::translate("MainWindow", "String", nullptr));
        doubleButton->setText(QCoreApplication::translate("MainWindow", "Double", nullptr));
        createList->setText(QCoreApplication::translate("MainWindow", "create list", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Integer List", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "String List", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Double List", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        display->setText(QCoreApplication::translate("MainWindow", "display list", nullptr));
        popFront->setText(QCoreApplication::translate("MainWindow", "pop front", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Value:", nullptr));
        pushFront->setText(QCoreApplication::translate("MainWindow", "push front", nullptr));
        selectSort->setText(QCoreApplication::translate("MainWindow", "select sort", nullptr));
        removeDuplicates->setText(QCoreApplication::translate("MainWindow", "remove duplicates", nullptr));
        copyList->setText(QCoreApplication::translate("MainWindow", "copy list", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Display:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
