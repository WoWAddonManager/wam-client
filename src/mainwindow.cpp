#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QtCore/QStringListModel>
#include <QtWidgets/QPushButton>
#include "addon.h"
#include "settingsmanager.h"

void MainWindow::test() {
    auto addons = Addon::get_all_adddons(this->settings->get_retail_addons_path());
    auto size = addons->size();
    ui->retail_table->setRowCount(size-1);
    int i = 0;
    std::for_each(addons->begin(), addons->end(), [&](const Addon &addon){
        ui->retail_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(addon.m_addonName)));
        ui->retail_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(addon.m_addon_version)));
        ui->retail_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(addon.m_interface_version)));
        ui->retail_table->setItem(i++, 3, new QTableWidgetItem(QString::fromStdString(addon.m_note)));
    });

}

void MainWindow::swap_addon_list(const QString &version){
    if(version == "Retail"){
        ui->classic_table->hide();
        ui->retail_table->show();
    }
    else {
        ui->retail_table->hide();
        ui->classic_table->show();
    }
}


void MainWindow::quit() {
    exit(0);
}

MainWindow::MainWindow(QWidget *parent, SettingsManager *settings) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    this->settings = settings;
    ui->setupUi(this);
    ui->classic_table->hide();
    //ui->retail_table->horizontalHeader()->setStretchLastSection(true);
    for(int i = 0; i < 3;  i++){
        ui->retail_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        ui->classic_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    ui->retail_table->setColumnWidth(4, 80);
    ui->classic_table->setColumnWidth(4, 80);

    ui->tabWidget->setCurrentIndex(0);

    // Add items to combo box
    ui->wow_version_combo_box->addItem(QString("Retail"));
    ui->wow_version_combo_box->addItem(QString("Classic"));
    ui->wow_version_combo_box->addItem(QString("PTR"));

    connect(ui->set_wow_path_btn, &QPushButton::clicked, [=]() {
        QString file_path = QFileDialog::getExistingDirectory(this, "Select WoW Folder");
        settings->set_base_wow_path(file_path.toStdString());
        settings->set_wow_folder_paths();
        ui->lineEdit->setText(QString::fromStdString(settings->get_base_wow_path()));
    });

    connect(ui->wow_version_combo_box, SIGNAL(currentIndexChanged(QString)), this, SLOT(swap_addon_list(QString)));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));


    fill_in_settings(*settings);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::fill_in_settings(const SettingsManager &settings) {
    ui->lineEdit->setText(QString::fromStdString(settings.get_base_wow_path()));
}
