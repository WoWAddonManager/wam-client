/********************************************************************************
** Form generated from reading UI file 'upload_addon_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOAD_ADDON_DIALOG_H
#define UI_UPLOAD_ADDON_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_upload_addon_dialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *wow_version;
    QTextEdit *addon_description_textbox;
    QLabel *label_4;
    QLineEdit *addon_name;
    QLineEdit *lineEdit;
    QLineEdit *addon_path;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QPushButton *browse_addon_folder_button;
    QLabel *label_6;
    QLineEdit *addon_version;
    QPushButton *upload_addon;

    void setupUi(QDialog *upload_addon_dialog)
    {
        if (upload_addon_dialog->objectName().isEmpty())
            upload_addon_dialog->setObjectName(QString::fromUtf8("upload_addon_dialog"));
        upload_addon_dialog->setWindowModality(Qt::NonModal);
        upload_addon_dialog->resize(735, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upload_addon_dialog->sizePolicy().hasHeightForWidth());
        upload_addon_dialog->setSizePolicy(sizePolicy);
        upload_addon_dialog->setLayoutDirection(Qt::LeftToRight);
        upload_addon_dialog->setAutoFillBackground(false);
        upload_addon_dialog->setModal(false);
        gridLayout = new QGridLayout(upload_addon_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wow_version = new QComboBox(upload_addon_dialog);
        wow_version->setObjectName(QString::fromUtf8("wow_version"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wow_version->sizePolicy().hasHeightForWidth());
        wow_version->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        wow_version->setFont(font);

        gridLayout->addWidget(wow_version, 1, 7, 1, 2);

        addon_description_textbox = new QTextEdit(upload_addon_dialog);
        addon_description_textbox->setObjectName(QString::fromUtf8("addon_description_textbox"));
        addon_description_textbox->setFont(font);

        gridLayout->addWidget(addon_description_textbox, 3, 0, 1, 9);

        label_4 = new QLabel(upload_addon_dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 6, 1, 1);

        addon_name = new QLineEdit(upload_addon_dialog);
        addon_name->setObjectName(QString::fromUtf8("addon_name"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addon_name->sizePolicy().hasHeightForWidth());
        addon_name->setSizePolicy(sizePolicy3);
        addon_name->setFont(font);

        gridLayout->addWidget(addon_name, 1, 1, 1, 1);

        lineEdit = new QLineEdit(upload_addon_dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        addon_path = new QLineEdit(upload_addon_dialog);
        addon_path->setObjectName(QString::fromUtf8("addon_path"));
        addon_path->setFont(font);

        gridLayout->addWidget(addon_path, 0, 1, 1, 7);

        label_5 = new QLabel(upload_addon_dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_2 = new QLabel(upload_addon_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(upload_addon_dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 4, 1, 1);

        label = new QLabel(upload_addon_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        browse_addon_folder_button = new QPushButton(upload_addon_dialog);
        browse_addon_folder_button->setObjectName(QString::fromUtf8("browse_addon_folder_button"));
        browse_addon_folder_button->setFont(font);

        gridLayout->addWidget(browse_addon_folder_button, 0, 8, 1, 1);

        label_6 = new QLabel(upload_addon_dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        addon_version = new QLineEdit(upload_addon_dialog);
        addon_version->setObjectName(QString::fromUtf8("addon_version"));
        sizePolicy3.setHeightForWidth(addon_version->sizePolicy().hasHeightForWidth());
        addon_version->setSizePolicy(sizePolicy3);
        addon_version->setFont(font);

        gridLayout->addWidget(addon_version, 1, 5, 1, 1);

        upload_addon = new QPushButton(upload_addon_dialog);
        upload_addon->setObjectName(QString::fromUtf8("upload_addon"));

        gridLayout->addWidget(upload_addon, 4, 8, 1, 1);


        retranslateUi(upload_addon_dialog);

        QMetaObject::connectSlotsByName(upload_addon_dialog);
    } // setupUi

    void retranslateUi(QDialog *upload_addon_dialog)
    {
        upload_addon_dialog->setWindowTitle(QCoreApplication::translate("upload_addon_dialog", "Upload Addon", nullptr));
        label_4->setText(QCoreApplication::translate("upload_addon_dialog", "WoW Version", nullptr));
        label_5->setText(QCoreApplication::translate("upload_addon_dialog", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("upload_addon_dialog", "Addon Name", nullptr));
        label_3->setText(QCoreApplication::translate("upload_addon_dialog", "WoW Patch", nullptr));
        label->setText(QCoreApplication::translate("upload_addon_dialog", "Addon Path", nullptr));
        browse_addon_folder_button->setText(QCoreApplication::translate("upload_addon_dialog", "Browse", nullptr));
        label_6->setText(QCoreApplication::translate("upload_addon_dialog", "Version", nullptr));
        addon_version->setText(QString());
        upload_addon->setText(QCoreApplication::translate("upload_addon_dialog", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class upload_addon_dialog: public Ui_upload_addon_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOAD_ADDON_DIALOG_H
