#include <QCoreApplication>
#include <Cutelyst/WSGI/wsgi.h>
#include "serverrest.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    auto myapp = new ServerREST();
    auto wsgi = new CWSGI::WSGI;
    wsgi->setHttpSocket({
                            { QStringLiteral(":3010") },
                        });
    wsgi->setUpgradeH2c(true);
    wsgi->setBufferSize(16393);
    wsgi->exec(myapp);
}
