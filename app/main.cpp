#include "ui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
#include "hashes/hashesmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion(APP_VERSION);

    std::string strData = "part 1; part two; PART THREE.";

    std::map<std::string, std::string> hashesMap = HashesManager::computeAllHashes((const unsigned char*)strData.data(), strData.size());
    for (auto& hm : hashesMap) {
        std::cout << hm.first << " -> " << hm.second << std::endl;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
