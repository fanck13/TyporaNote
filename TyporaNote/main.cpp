#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QScreen>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Rich Text");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(a);

    MainWindow mw;

    const QRect availableGeometry = mw.screen()->availableGeometry();

    mw.resize(availableGeometry.width() / 2, (availableGeometry.height() * 2) / 3);
    mw.move((availableGeometry.width() - mw.width()) / 2,
            (availableGeometry.height() - mw.height()) / 2);

    mw.show();
    return a.exec();
}
