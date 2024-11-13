/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *number1LineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *number2LineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addButton;
    QPushButton *subtractButton;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *sinButton;
    QPushButton *cosButton;
    QPushButton *tanButton;
    QPushButton *cotButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *asinButton;
    QPushButton *acosButton;
    QPushButton *atanButton;
    QPushButton *acotButton;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioButton_rad;
    QRadioButton *radioButton_grad;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *resultLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        number1LineEdit = new QLineEdit(centralwidget);
        number1LineEdit->setObjectName(QString::fromUtf8("number1LineEdit"));

        horizontalLayout->addWidget(number1LineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        number2LineEdit = new QLineEdit(centralwidget);
        number2LineEdit->setObjectName(QString::fromUtf8("number2LineEdit"));

        horizontalLayout_2->addWidget(number2LineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout_4->addWidget(addButton);

        subtractButton = new QPushButton(centralwidget);
        subtractButton->setObjectName(QString::fromUtf8("subtractButton"));

        horizontalLayout_4->addWidget(subtractButton);

        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));

        horizontalLayout_4->addWidget(multiplyButton);

        divideButton = new QPushButton(centralwidget);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));

        horizontalLayout_4->addWidget(divideButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sinButton = new QPushButton(centralwidget);
        sinButton->setObjectName(QString::fromUtf8("sinButton"));

        horizontalLayout_5->addWidget(sinButton);

        cosButton = new QPushButton(centralwidget);
        cosButton->setObjectName(QString::fromUtf8("cosButton"));

        horizontalLayout_5->addWidget(cosButton);

        tanButton = new QPushButton(centralwidget);
        tanButton->setObjectName(QString::fromUtf8("tanButton"));

        horizontalLayout_5->addWidget(tanButton);

        cotButton = new QPushButton(centralwidget);
        cotButton->setObjectName(QString::fromUtf8("cotButton"));

        horizontalLayout_5->addWidget(cotButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        asinButton = new QPushButton(centralwidget);
        asinButton->setObjectName(QString::fromUtf8("asinButton"));

        horizontalLayout_6->addWidget(asinButton);

        acosButton = new QPushButton(centralwidget);
        acosButton->setObjectName(QString::fromUtf8("acosButton"));

        horizontalLayout_6->addWidget(acosButton);

        atanButton = new QPushButton(centralwidget);
        atanButton->setObjectName(QString::fromUtf8("atanButton"));

        horizontalLayout_6->addWidget(atanButton);

        acotButton = new QPushButton(centralwidget);
        acotButton->setObjectName(QString::fromUtf8("acotButton"));

        horizontalLayout_6->addWidget(acotButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioButton_rad = new QRadioButton(centralwidget);
        radioButton_rad->setObjectName(QString::fromUtf8("radioButton_rad"));
        radioButton_rad->setChecked(true);

        horizontalLayout_7->addWidget(radioButton_rad);

        radioButton_grad = new QRadioButton(centralwidget);
        radioButton_grad->setObjectName(QString::fromUtf8("radioButton_grad"));

        horizontalLayout_7->addWidget(radioButton_grad);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));

        horizontalLayout_3->addWidget(resultLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 1:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 2:", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        subtractButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        multiplyButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        divideButton->setText(QApplication::translate("MainWindow", "/", nullptr));
        sinButton->setText(QApplication::translate("MainWindow", "sin", nullptr));
        cosButton->setText(QApplication::translate("MainWindow", "cos", nullptr));
        tanButton->setText(QApplication::translate("MainWindow", "tan", nullptr));
        cotButton->setText(QApplication::translate("MainWindow", "cot", nullptr));
        asinButton->setText(QApplication::translate("MainWindow", "asin", nullptr));
        acosButton->setText(QApplication::translate("MainWindow", "acos", nullptr));
        atanButton->setText(QApplication::translate("MainWindow", "atan", nullptr));
        acotButton->setText(QApplication::translate("MainWindow", "acot", nullptr));
        radioButton_rad->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\320\260\320\275\321\213", nullptr));
        radioButton_grad->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
