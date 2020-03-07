#include "upload_addon_dialog.h"
#include <QFileDialog>

upload_addon_dialog::upload_addon_dialog(QWidget *parent): QDialog(parent), dialog(new Ui::upload_addon_dialog){
    dialog->setupUi(this);
    dialog->wow_version->addItem("Retail");
    dialog->wow_version->addItem("Classic");
    dialog->wow_version->addItem("PTR");

    connect(dialog->browse_addon_folder_button, &QPushButton::clicked, [&]() {
        auto folder_path = QFileDialog::getExistingDirectory();
        dialog->addon_path->setText(folder_path);
        std::cout << folder_path.toStdString() << std::endl;
    });
}

upload_addon_dialog::~upload_addon_dialog() {
    delete(dialog);
}