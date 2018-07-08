#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_valTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    void init();
    void setTableWidgetHeader();
    void clearTableWidget();
};

#endif // MAINWINDOW_H
