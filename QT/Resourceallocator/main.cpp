#include <QApplication>
#include "resourceallocator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ResourceAllocator window;
    window.show();
    return app.exec();
}
