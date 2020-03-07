#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "settingsmanager.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent, SettingsManager &settings);
    void fill_in_settings(const SettingsManager &settings);
    ~MainWindow() override;

private:
    void swap_addon_list(const QString &version);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
