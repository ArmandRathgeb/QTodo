#include <QApplication>

#include "qMainWindow.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    ui::qMainWindow main;
    main.show();
    return QApplication::exec();
}
