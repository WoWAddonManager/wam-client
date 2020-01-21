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
    explicit MainWindow(QWidget *parent, SettingsManager *settings);
    void fill_in_settings(const SettingsManager &settings);
    ~MainWindow();
    void swap_addon_list(const QString &version);
private:
    Ui::MainWindow *ui;
    SettingsManager *settings;
};

#endif // MAINWINDOW_H
