/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QTabWidget *tabWidget;
    QWidget *welcomeTab1;
    QLabel *welcomeLabel;
    QPushButton *generateButton;
    QLineEdit *idInput;
    QLineEdit *nameInput;
    QLabel *nameLabel;
    QLabel *idLabel;
    QWidget *inputTab2;
    QLineEdit *ageInput;
    QLineEdit *heightInput;
    QLineEdit *weightInput;
    QComboBox *goalCombo;
    QComboBox *dietCombo;
    QListWidget *freeTimeList;
    QLabel *label;
    QPushButton *submitButton;
    QWidget *Tab3;
    QTextEdit *workoutResult;
    QTextEdit *mealResult;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        welcomeTab1 = new QWidget();
        welcomeTab1->setObjectName("welcomeTab1");
        welcomeLabel = new QLabel(welcomeTab1);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(30, 30, 175, 16));
        generateButton = new QPushButton(welcomeTab1);
        generateButton->setObjectName("generateButton");
        generateButton->setGeometry(QRect(70, 420, 105, 32));
        idInput = new QLineEdit(welcomeTab1);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(100, 290, 125, 21));
        nameInput = new QLineEdit(welcomeTab1);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(100, 210, 125, 21));
        nameLabel = new QLabel(welcomeTab1);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(40, 210, 58, 16));
        idLabel = new QLabel(welcomeTab1);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(40, 290, 58, 16));
        tabWidget->addTab(welcomeTab1, QString());
        inputTab2 = new QWidget();
        inputTab2->setObjectName("inputTab2");
        ageInput = new QLineEdit(inputTab2);
        ageInput->setObjectName("ageInput");
        ageInput->setGeometry(QRect(40, 20, 113, 21));
        heightInput = new QLineEdit(inputTab2);
        heightInput->setObjectName("heightInput");
        heightInput->setGeometry(QRect(30, 70, 125, 21));
        weightInput = new QLineEdit(inputTab2);
        weightInput->setObjectName("weightInput");
        weightInput->setGeometry(QRect(30, 130, 125, 21));
        goalCombo = new QComboBox(inputTab2);
        goalCombo->addItem(QString());
        goalCombo->addItem(QString());
        goalCombo->addItem(QString());
        goalCombo->setObjectName("goalCombo");
        goalCombo->setGeometry(QRect(40, 200, 103, 32));
        goalCombo->setDuplicatesEnabled(false);
        dietCombo = new QComboBox(inputTab2);
        dietCombo->addItem(QString());
        dietCombo->addItem(QString());
        dietCombo->setObjectName("dietCombo");
        dietCombo->setGeometry(QRect(40, 260, 103, 32));
        freeTimeList = new QListWidget(inputTab2);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        freeTimeList->setObjectName("freeTimeList");
        freeTimeList->setGeometry(QRect(0, 330, 211, 141));
        freeTimeList->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        label = new QLabel(inputTab2);
        label->setObjectName("label");
        label->setGeometry(QRect(47, 310, 111, 20));
        submitButton = new QPushButton(inputTab2);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(60, 490, 101, 32));
        tabWidget->addTab(inputTab2, QString());
        Tab3 = new QWidget();
        Tab3->setObjectName("Tab3");
        workoutResult = new QTextEdit(Tab3);
        workoutResult->setObjectName("workoutResult");
        workoutResult->setGeometry(QRect(60, 40, 104, 74));
        mealResult = new QTextEdit(Tab3);
        mealResult->setObjectName("mealResult");
        mealResult->setGeometry(QRect(60, 200, 104, 74));
        tabWidget->addTab(Tab3, QString());

        formLayout->setWidget(0, QFormLayout::ItemRole::SpanningRole, tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\346\240\241\345\233\255\345\201\245\345\272\267\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\224\237\346\210\220\350\256\241\345\210\222", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        idLabel->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(welcomeTab1), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        ageInput->setText(QCoreApplication::translate("MainWindow", "\345\271\264\351\276\204", nullptr));
        heightInput->setText(QCoreApplication::translate("MainWindow", "\350\272\253\351\253\230\357\274\210cm\357\274\211", nullptr));
        weightInput->setText(QCoreApplication::translate("MainWindow", "\344\275\223\351\207\215\357\274\210kg\357\274\211", nullptr));
        goalCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\345\207\217\350\204\202", nullptr));
        goalCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\345\242\236\350\202\214", nullptr));
        goalCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\245\345\272\267", nullptr));

#if QT_CONFIG(tooltip)
        goalCombo->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\201\245\345\272\267\347\233\256\346\240\207</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        goalCombo->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\201\245\345\272\267\347\233\256\346\240\207</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        goalCombo->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\201\245\345\272\267\347\233\256\346\240\207", nullptr));
        dietCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\350\215\244\351\243\237", nullptr));
        dietCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\347\264\240\351\243\237", nullptr));

        dietCombo->setCurrentText(QString());
        dietCombo->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\245\256\351\243\237\345\201\217\345\245\275", nullptr));

        const bool __sortingEnabled = freeTimeList->isSortingEnabled();
        freeTimeList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = freeTimeList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "1-2\350\212\202\350\257\276", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = freeTimeList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "3-4\350\212\202\350\257\276", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = freeTimeList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "5-6\350\212\202\350\257\276", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = freeTimeList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "7-8\350\212\202\350\257\276", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = freeTimeList->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "9-10\350\212\202\350\257\276", nullptr));
        freeTimeList->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(whatsthis)
        freeTimeList->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\251\272\351\227\262\346\227\266\351\227\264\357\274\210\345\217\257\345\244\232\351\200\211\357\274\211</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        freeTimeList->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("MainWindow", "\347\251\272\344\275\231\346\227\266\351\227\264\357\274\210\345\217\257\345\244\232\351\200\211\357\274\211", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\344\270\252\346\200\247\345\214\226\345\201\245\345\272\267\350\256\241\345\210\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(inputTab2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab3), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
