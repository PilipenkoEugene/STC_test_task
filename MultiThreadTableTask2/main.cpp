#include "MultiThreadTableTask2.h"
#include <QtWidgets/QApplication>
//-----------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MultiThreadTableTask2 window;
    window.setMinimumSize(400, 400);
    window.show();
    return app.exec();
}
//-----------------------------------------------------------------------------------------
