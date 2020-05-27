#include <QFileDialog>
#include "addon.h"
#include "upload_addon_dialog.h"

upload_addon_dialog::upload_addon_dialog(QWidget *parent) : QDialog(parent), dialog(new Ui::upload_addon_dialog) {
    dialog->setupUi(this);
    dialog->wow_version->addItem("Retail");
    dialog->wow_version->addItem("Classic");
    dialog->wow_version->addItem("PTR");

    connect(dialog->browse_addon_folder_button, &QPushButton::clicked, [&]() {
        auto folder_path = QFileDialog::getExistingDirectory();
        dialog->addon_path->setText(folder_path);
        std::cout << folder_path.toStdString() << std::endl;
    });

    connect(dialog->upload_addon, &QPushButton::clicked, [&]() {
        auto path = dialog->addon_path->text().toStdString();
        auto addon_name = dialog->addon_name->text().toStdString();
        auto addon_version = dialog->addon_version->text().toStdString();
        auto addon_description = dialog->addon_description_textbox->document()->toPlainText().toStdString();
        auto wow_version = dialog->wow_version->itemData(dialog->wow_version->currentIndex()).toString().toStdString();
        if (!path.empty() && !addon_name.empty() && !addon_version.empty() && !addon_description.empty()) {
            Addon addon{};
            addon.m_addonName = addon_name;
            addon.m_addon_version = addon_version;;
            addon.m_wow_version = Addon::wow_version_to_enum(wow_version);
            addon.m_description = addon_description;
            addon.make_wam(path);
            std::cout << addon;
        }
    });
}

upload_addon_dialog::~upload_addon_dialog() = default;

