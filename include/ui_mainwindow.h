/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *addon_tab;
    QGridLayout *gridLayout;
    QTableWidget *classic_table;
    QComboBox *wow_version_combo_box;
    QLabel *wow_version_label;
    QTableWidget *retail_table;
    QWidget *settings_tab;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QPushButton *set_wow_path_btn;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(813, 650);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        addon_tab = new QWidget();
        addon_tab->setObjectName(QString::fromUtf8("addon_tab"));
        gridLayout = new QGridLayout(addon_tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        classic_table = new QTableWidget(addon_tab);
        if (classic_table->columnCount() < 5)
            classic_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        classic_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        classic_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        classic_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        classic_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        classic_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        classic_table->setObjectName(QString::fromUtf8("classic_table"));
        classic_table->setEnabled(true);

        gridLayout->addWidget(classic_table, 6, 0, 1, 3);

        wow_version_combo_box = new QComboBox(addon_tab);
        wow_version_combo_box->setObjectName(QString::fromUtf8("wow_version_combo_box"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wow_version_combo_box->sizePolicy().hasHeightForWidth());
        wow_version_combo_box->setSizePolicy(sizePolicy);
        wow_version_combo_box->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(wow_version_combo_box, 0, 0, 1, 1);

        wow_version_label = new QLabel(addon_tab);
        wow_version_label->setObjectName(QString::fromUtf8("wow_version_label"));

        gridLayout->addWidget(wow_version_label, 0, 1, 1, 1);

        retail_table = new QTableWidget(addon_tab);
        if (retail_table->columnCount() < 5)
            retail_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        retail_table->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        retail_table->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        retail_table->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        retail_table->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        retail_table->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        retail_table->setObjectName(QString::fromUtf8("retail_table"));

        gridLayout->addWidget(retail_table, 7, 0, 1, 3);

        tabWidget->addTab(addon_tab, QString());
        settings_tab = new QWidget();
        settings_tab->setObjectName(QString::fromUtf8("settings_tab"));
        gridLayout_2 = new QGridLayout(settings_tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(settings_tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);

        set_wow_path_btn = new QPushButton(settings_tab);
        set_wow_path_btn->setObjectName(QString::fromUtf8("set_wow_path_btn"));
        set_wow_path_btn->setFlat(false);

        gridLayout_2->addWidget(set_wow_path_btn, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        label = new QLabel(settings_tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(settings_tab, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 813, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WAM: WoW Addon Manager", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = classic_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = classic_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = classic_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Peers", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = classic_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        wow_version_combo_box->setCurrentText(QString());
        wow_version_label->setText(QCoreApplication::translate("MainWindow", "WoW Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = retail_table->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = retail_table->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = retail_table->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Peers", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = retail_table->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addon_tab), QCoreApplication::translate("MainWindow", "Addons", nullptr));
        set_wow_path_btn->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "WoW Folder Path", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settings_tab), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
