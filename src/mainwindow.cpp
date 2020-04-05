#include "mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QtCore/QStringListModel>
#include <QtWidgets/QPushButton>
#include <utils.h>
#include "addon.h"
#include "settingsmanager.h"
#include "upload_addon_dialog.h"
#include "response.h"
#include <boost/optional/optional_io.hpp>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent, SettingsManager &settings) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    auto dialog = new upload_addon_dialog(this);


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

    ui->retail_table->setItem(0,0,new QTableWidgetItem("Hello World!"));
    auto addons = Addon::get_remote_addons().get_data();
    if(addons != boost::none) {
        ui->retail_table->setRowCount(addons->size());
        for (int i = 0; i < addons->size(); i++) {
            auto addon = addons->at(i);
            ui->retail_table->setItem(i, 0, new QTableWidgetItem(addon.m_addonName.c_str()));
        }
    }


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


    connect(ui->actionUploadAddon, &QAction::triggered, [&,dialog]() {
        dialog->show();
    });

    connect(ui->addon_search_field, &QLineEdit::returnPressed, [&, this]() {
        auto result = Addon::get_addon_by_name(ui->addon_search_field->text().toStdString());

        if(result.get_error_code() == 200) {
            auto addon = result.get_data();
            auto get_addons_table = ui->get_addons_table;
            get_addons_table->setRowCount(1);
            get_addons_table->setItem(0,0,new QTableWidgetItem(QString::fromStdString(addon->m_addonName)));
            get_addons_table->setItem(0,1,new QTableWidgetItem(QString::fromStdString(addon->m_addon_version)));
            get_addons_table->setItem(0,3,new QTableWidgetItem(QString::fromStdString(addon->m_description)));
            auto *widget = new QWidget();
            auto *install_button = new QPushButton();
            install_button->setText("Install");
            auto *layout = new QHBoxLayout(widget);
            layout->addWidget(install_button);
            layout->setAlignment(Qt::AlignCenter);
            layout->setContentsMargins(0,0,0,0);
            widget->setLayout(layout);
            get_addons_table->setCellWidget(0,4, widget);
            connect(install_button, &QPushButton::clicked, [&, addon](){
                std::cout << "Instaling: " << addon;
            });
        }
        else if (result.get_error_code() == 404) {
            make_message_box("No Addon found!");
        }
        else {
            make_message_box("Woah something went wrong?");
        }
    });


    fill_in_settings(settings);

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

MainWindow::~MainWindow() = default;