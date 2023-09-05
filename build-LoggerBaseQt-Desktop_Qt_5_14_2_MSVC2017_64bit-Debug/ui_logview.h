/********************************************************************************
** Form generated from reading UI file 'logview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEW_H
#define UI_LOGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogView
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LogView)
    {
        if (LogView->objectName().isEmpty())
            LogView->setObjectName(QString::fromUtf8("LogView"));
        LogView->resize(800, 600);
        centralwidget = new QWidget(LogView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        LogView->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LogView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LogView->setStatusBar(statusbar);

        retranslateUi(LogView);

        QMetaObject::connectSlotsByName(LogView);
    } // setupUi

    void retranslateUi(QMainWindow *LogView)
    {
        LogView->setWindowTitle(QCoreApplication::translate("LogView", "Widget Logger", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("LogView", "Debug", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("LogView", "Info", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("LogView", "Warning", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("LogView", "Critical", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("LogView", "Fatal", nullptr));

        lineEdit->setText(QCoreApplication::translate("LogView", "Widget\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
        pushButton->setText(QCoreApplication::translate("LogView", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogView: public Ui_LogView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEW_H
