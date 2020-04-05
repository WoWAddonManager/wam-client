/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *email;
    QLineEdit *password;

    void setupUi(QDialog *login_dialog)
    {
        if (login_dialog->objectName().isEmpty())
            login_dialog->setObjectName(QString::fromUtf8("login_dialog"));
        login_dialog->resize(400, 152);
        login_dialog->setFocusPolicy(Qt::StrongFocus);
        gridLayout = new QGridLayout(login_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(login_dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);

        label = new QLabel(login_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::StrongFocus);
        label->setOpenExternalLinks(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(login_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        email = new QLineEdit(login_dialog);
        email->setObjectName(QString::fromUtf8("email"));

        gridLayout->addWidget(email, 1, 0, 1, 1);

        password = new QLineEdit(login_dialog);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout->addWidget(password, 3, 0, 1, 1);


        retranslateUi(login_dialog);

        QMetaObject::connectSlotsByName(login_dialog);
    } // setupUi

    void retranslateUi(QDialog *login_dialog)
    {
        login_dialog->setWindowTitle(QCoreApplication::translate("login_dialog", "Login", nullptr));
        pushButton->setText(QCoreApplication::translate("login_dialog", "Login", nullptr));
        label->setText(QCoreApplication::translate("login_dialog", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("login_dialog", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_dialog: public Ui_login_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
