#include "mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QtCore/QStringListModel>
#include <QtWidgets/QPushButton>
#include "addon.h"
#include "settingsmanager.h"
#include "upload_addon_dialog.h"
MainWindow::MainWindow(QWidget *parent, SettingsManager &settings) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    auto dialog = std::make_shared<upload_addon_dialog>(this);



    ui->setupUi(this);
    ui->classic_table->hide();
    ui->ptr_table->hide();
    //ui->retail_table->horizontalHeader()->setStretchLastSection(true);
    for(int i = 0; i < 4;  i++){
        ui->retail_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        ui->classic_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        ui->ptr_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    ui->retail_table->setColumnWidth(4, 80);
    ui->classic_table->setColumnWidth(4, 80);
    ui->ptr_table->setColumnWidth(4, 80);

    ui->tabWidget->setCurrentIndex(0);

    connect(ui->set_wow_path_btn, &QPushButton::clicked, [&]() {
        QString file_path = QFileDialog::getExistingDirectory(this, "Select WoW Folder");
        settings.set_base_wow_path(file_path.toStdString());
        settings.set_wow_folder_paths();
        ui->lineEdit->setText(QString::fromStdString(settings.get_base_wow_path()));
    });

    connect(ui->wow_version_combo_box,  static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged), [this](const QString& tab) {
        swap_addon_list(tab);
    });
    connect(ui->actionQuit, &QAction::triggered, [&]() {
        exit(0);
    });
    connect(ui->actionUploadAddon, &QAction::triggered, [dialog]() {
        dialog->show();
    });


    fill_in_settings(settings);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::swap_addon_list(const QString &version){
    if(version == "Retail"){
        ui->classic_table->hide();
        ui->ptr_table->hide();
        ui->retail_table->show();
    }
    else if(version == "Classic"){
        ui->retail_table->hide();
        ui->ptr_table->hide();
        ui->classic_table->show();
    }
    else  {
        ui->retail_table->hide();
        ui->classic_table->hide();
        ui->ptr_table->show();
    }
}

void MainWindow::fill_in_settings(const SettingsManager &p_settings) {
    ui->lineEdit->setText(QString::fromStdString(p_settings.get_base_wow_path()));
}
