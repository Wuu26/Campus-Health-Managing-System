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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QLabel *welcomeLabel;
    QPushButton *generateButton;
    QLineEdit *idInput;
    QLineEdit *nameInput;
    QLabel *nameLabel;
    QLabel *idLabel;
    QLabel *welcomeLabel_2;
    QLabel *label_2;
    QWidget *stackedWidgetPage2;
    QLineEdit *ageInput;
    QLineEdit *heightInput;
    QLineEdit *weightInput;
    QComboBox *goalCombo;
    QComboBox *dietCombo;
    QListWidget *freeTimeList;
    QLabel *label;
    QPushButton *submitButton;
    QWidget *stackedWidgetPage3;
    QTextEdit *workoutResult;
    QTextEdit *mealResult;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(857, 569);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName("stackedWidgetPage1");
        welcomeLabel = new QLabel(stackedWidgetPage1);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(220, 180, 175, 16));
        generateButton = new QPushButton(stackedWidgetPage1);
        generateButton->setObjectName("generateButton");
        generateButton->setGeometry(QRect(240, 350, 105, 32));
        generateButton->setStyleSheet(QString::fromUtf8(""));
        idInput = new QLineEdit(stackedWidgetPage1);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(280, 290, 125, 21));
        nameInput = new QLineEdit(stackedWidgetPage1);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(280, 230, 125, 21));
        nameLabel = new QLabel(stackedWidgetPage1);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(200, 230, 58, 16));
        idLabel = new QLabel(stackedWidgetPage1);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(200, 290, 58, 16));
        welcomeLabel_2 = new QLabel(stackedWidgetPage1);
        welcomeLabel_2->setObjectName("welcomeLabel_2");
        welcomeLabel_2->setGeometry(QRect(110, 40, 391, 101));
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, -60, 221, 231));
        label_2->setPixmap(QPixmap(QString::fromUtf8("resource/Unknown.jpeg")));
        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName("stackedWidgetPage2");
        ageInput = new QLineEdit(stackedWidgetPage2);
        ageInput->setObjectName("ageInput");
        ageInput->setGeometry(QRect(350, 20, 113, 21));
        heightInput = new QLineEdit(stackedWidgetPage2);
        heightInput->setObjectName("heightInput");
        heightInput->setGeometry(QRect(340, 70, 125, 21));
        weightInput = new QLineEdit(stackedWidgetPage2);
        weightInput->setObjectName("weightInput");
        weightInput->setGeometry(QRect(340, 130, 125, 21));
        goalCombo = new QComboBox(stackedWidgetPage2);
        goalCombo->addItem(QString());
        goalCombo->addItem(QString());
        goalCombo->addItem(QString());
        goalCombo->setObjectName("goalCombo");
        goalCombo->setGeometry(QRect(350, 200, 103, 32));
        goalCombo->setDuplicatesEnabled(false);
        dietCombo = new QComboBox(stackedWidgetPage2);
        dietCombo->addItem(QString());
        dietCombo->addItem(QString());
        dietCombo->setObjectName("dietCombo");
        dietCombo->setGeometry(QRect(350, 260, 103, 32));
        freeTimeList = new QListWidget(stackedWidgetPage2);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        new QListWidgetItem(freeTimeList);
        freeTimeList->setObjectName("freeTimeList");
        freeTimeList->setGeometry(QRect(310, 330, 211, 141));
        freeTimeList->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        label = new QLabel(stackedWidgetPage2);
        label->setObjectName("label");
        label->setGeometry(QRect(357, 310, 111, 20));
        submitButton = new QPushButton(stackedWidgetPage2);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(340, 490, 141, 32));
        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName("stackedWidgetPage3");
        workoutResult = new QTextEdit(stackedWidgetPage3);
        workoutResult->setObjectName("workoutResult");
        workoutResult->setGeometry(QRect(310, 110, 201, 131));
        mealResult = new QTextEdit(stackedWidgetPage3);
        mealResult->setObjectName("mealResult");
        mealResult->setGeometry(QRect(310, 310, 201, 131));
        label_3 = new QLabel(stackedWidgetPage3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 280, 111, 20));
        label_4 = new QLabel(stackedWidgetPage3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(350, 80, 111, 20));
        stackedWidget->addWidget(stackedWidgetPage3);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\350\203\275\346\240\241\345\233\255\345\201\245\345\272\267\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\224\237\346\210\220\350\256\241\345\210\222", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        idLabel->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        welcomeLabel_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700; font-style:italic;\">Weiming Coders</span></p><p align=\"center\"><span style=\" font-size:36pt; font-weight:700; font-style:italic;\">\346\231\272\350\203\275\346\240\241\345\233\255\345\201\245\345\272\267\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_2->setText(QString());
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
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\351\245\256\351\243\237\345\273\272\350\256\256</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\350\277\220\345\212\250\345\273\272\350\256\256</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
