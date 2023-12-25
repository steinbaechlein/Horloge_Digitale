#include <QApplication>
#include "ihmhorloge.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // La gestion de l'encodage des caractères n'est plus nécessaire dans les versions récentes de Qt

    IHMHorloge w;
    w.show();

    return a.exec();
}
