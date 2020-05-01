/********************************************************************************
** Form generated from reading UI file 'signup_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_DIALOG_H
#define UI_SIGNUP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signup_dialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *password_label;
    QLabel *password_error_label;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout;
    QLabel *username_label;
    QLabel *username_error_label;
    QLineEdit *email;
    QHBoxLayout *horizontalLayout_4;
    QLabel *confirm_password_label;
    QLabel *confirm_password_error_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_label;
    QLabel *email_error_label;
    QLineEdit *password;
    QLineEdit *password_confirmation;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *signup_button;
    QPushButton *login_button;

    void setupUi(QDialog *signup_dialog)
    {
        if (signup_dialog->objectName().isEmpty())
            signup_dialog->setObjectName(QString::fromUtf8("signup_dialog"));
        signup_dialog->resize(439, 270);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(signup_dialog->sizePolicy().hasHeightForWidth());
        signup_dialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(signup_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        password_label = new QLabel(signup_dialog);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(password_label->sizePolicy().hasHeightForWidth());
        password_label->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(password_label);

        password_error_label = new QLabel(signup_dialog);
        password_error_label->setObjectName(QString::fromUtf8("password_error_label"));
        password_error_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0)"));

        horizontalLayout_3->addWidget(password_error_label);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        username = new QLineEdit(signup_dialog);
        username->setObjectName(QString::fromUtf8("username"));

        gridLayout->addWidget(username, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        username_label = new QLabel(signup_dialog);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        sizePolicy1.setHeightForWidth(username_label->sizePolicy().hasHeightForWidth());
        username_label->setSizePolicy(sizePolicy1);
        username_label->setFocusPolicy(Qt::StrongFocus);
        username_label->setOpenExternalLinks(false);

        horizontalLayout->addWidget(username_label);

        username_error_label = new QLabel(signup_dialog);
        username_error_label->setObjectName(QString::fromUtf8("username_error_label"));
        username_error_label->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(username_error_label->sizePolicy().hasHeightForWidth());
        username_error_label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        username_error_label->setFont(font);
        username_error_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0)"));

        horizontalLayout->addWidget(username_error_label);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        email = new QLineEdit(signup_dialog);
        email->setObjectName(QString::fromUtf8("email"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(email, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        confirm_password_label = new QLabel(signup_dialog);
        confirm_password_label->setObjectName(QString::fromUtf8("confirm_password_label"));
        sizePolicy1.setHeightForWidth(confirm_password_label->sizePolicy().hasHeightForWidth());
        confirm_password_label->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(confirm_password_label);

        confirm_password_error_label = new QLabel(signup_dialog);
        confirm_password_error_label->setObjectName(QString::fromUtf8("confirm_password_error_label"));
        confirm_password_error_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0)"));

        horizontalLayout_4->addWidget(confirm_password_error_label);


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        email_label = new QLabel(signup_dialog);
        email_label->setObjectName(QString::fromUtf8("email_label"));
        sizePolicy1.setHeightForWidth(email_label->sizePolicy().hasHeightForWidth());
        email_label->setSizePolicy(sizePolicy1);
        email_label->setFocusPolicy(Qt::StrongFocus);
        email_label->setOpenExternalLinks(false);

        horizontalLayout_2->addWidget(email_label);

        email_error_label = new QLabel(signup_dialog);
        email_error_label->setObjectName(QString::fromUtf8("email_error_label"));
        email_error_label->setEnabled(true);
        email_error_label->setFont(font);
        email_error_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0)"));

        horizontalLayout_2->addWidget(email_error_label);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        password = new QLineEdit(signup_dialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 5, 0, 1, 1);

        password_confirmation = new QLineEdit(signup_dialog);
        password_confirmation->setObjectName(QString::fromUtf8("password_confirmation"));
        password_confirmation->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password_confirmation, 7, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 250, -1);
        signup_button = new QPushButton(signup_dialog);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        sizePolicy.setHeightForWidth(signup_button->sizePolicy().hasHeightForWidth());
        signup_button->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(signup_button);

        login_button = new QPushButton(signup_dialog);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        sizePolicy.setHeightForWidth(login_button->sizePolicy().hasHeightForWidth());
        login_button->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(login_button);


        gridLayout->addLayout(horizontalLayout_5, 8, 0, 1, 1);

        password->raise();
        username->raise();
        password_confirmation->raise();
        email->raise();
        QWidget::setTabOrder(username, email);
        QWidget::setTabOrder(email, password);
        QWidget::setTabOrder(password, password_confirmation);

        retranslateUi(signup_dialog);

        QMetaObject::connectSlotsByName(signup_dialog);
    } // setupUi

    void retranslateUi(QDialog *signup_dialog)
    {
        signup_dialog->setWindowTitle(QCoreApplication::translate("signup_dialog", "Dialog", nullptr));
        password_label->setText(QCoreApplication::translate("signup_dialog", "Password", nullptr));
        password_error_label->setText(QString());
        username_label->setText(QCoreApplication::translate("signup_dialog", "Username", nullptr));
        username_error_label->setText(QString());
        confirm_password_label->setText(QCoreApplication::translate("signup_dialog", "Confirm Password", nullptr));
        confirm_password_error_label->setText(QString());
        email_label->setText(QCoreApplication::translate("signup_dialog", "Email", nullptr));
        email_error_label->setText(QString());
        password->setInputMask(QString());
        password->setText(QString());
        password_confirmation->setInputMask(QString());
        password_confirmation->setText(QString());
        signup_button->setText(QCoreApplication::translate("signup_dialog", "Sign Up", nullptr));
        login_button->setText(QCoreApplication::translate("signup_dialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup_dialog: public Ui_signup_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_DIALOG_H
