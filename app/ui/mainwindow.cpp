#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hashes/hashesmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->hashesTableWidget->setColumnCount(2);
    ui->hashesTableWidget->setRowCount(0);

    ui->hashesTableWidget->setColumnWidth(0, 120);
    ui->hashesTableWidget->setColumnWidth(1, 480);

    ui->valTextEdit->setPlaceholderText("Insert contents here...");

    clearTableWidget();
}

void MainWindow::setTableWidgetHeader()
{
    QStringList headerLabels;
    headerLabels << "Hash Family" << "Value";
    ui->hashesTableWidget->setHorizontalHeaderLabels(headerLabels);
}

void MainWindow::clearTableWidget()
{
    ui->hashesTableWidget->clear();
    while(ui->hashesTableWidget->rowCount() > 0) {
        ui->hashesTableWidget->removeRow(0);
    }
    setTableWidgetHeader();
}

void MainWindow::on_valTextEdit_textChanged()
{
    std::string testStr = ui->valTextEdit->toPlainText().toStdString();
    clearTableWidget();

    if(testStr.size() > 0) {
        std::map<std::string, std::string> hashesMap = HashesManager::computeAllHashes((const unsigned char*)testStr.data(), testStr.size());
        int rowNum = 0;
        for (auto& hm : hashesMap) {
            ui->hashesTableWidget->insertRow(rowNum);
            ui->hashesTableWidget->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(hm.first)));
            ui->hashesTableWidget->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(hm.second)));
        }
    }
}
