#ifndef WAM_UPLOAD_ADDON_DIALOG_H
#define WAM_UPLOAD_ADDON_DIALOG_H

#include "ui_upload_addon_dialog.h"
#include "addon.h"

namespace Ui {
    class upload_addon_dialog;
}

class upload_addon_dialog : public QDialog {
Q_OBJECT

public:
    explicit upload_addon_dialog(QWidget *parent = nullptr);

    ~upload_addon_dialog() override;

private:
    Ui::upload_addon_dialog *dialog;
private slots:

};

#endif //WAM_UPLOAD_ADDON_DIALOG_H
