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
    explicit MainWindow(QWidget *parent = nullptr, SettingsManager* settings = nullptr);
    void fill_in_settings(const SettingsManager &settings);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SettingsManager *settings;
private slots:
    void test();
    void quit();
    void swap_addon_list(const QString &version);
};

#endif // MAINWINDOW_H
