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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *email;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *login_dialog)
    {
        if (login_dialog->objectName().isEmpty())
            login_dialog->setObjectName(QString::fromUtf8("login_dialog"));
        login_dialog->resize(400, 154);
        login_dialog->setFocusPolicy(Qt::StrongFocus);
        gridLayout = new QGridLayout(login_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(login_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        label = new QLabel(login_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::StrongFocus);
        label->setOpenExternalLinks(false);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        email = new QLineEdit(login_dialog);
        email->setObjectName(QString::fromUtf8("email"));

        gridLayout->addWidget(email, 1, 0, 1, 2);

        password = new QLineEdit(login_dialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 3, 0, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(login_dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(login_dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);


        retranslateUi(login_dialog);

        QMetaObject::connectSlotsByName(login_dialog);
    } // setupUi

    void retranslateUi(QDialog *login_dialog)
    {
        login_dialog->setWindowTitle(QCoreApplication::translate("login_dialog", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("login_dialog", "Password", nullptr));
        label->setText(QCoreApplication::translate("login_dialog", "Email", nullptr));
        pushButton->setText(QCoreApplication::translate("login_dialog", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("login_dialog", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_dialog: public Ui_login_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
