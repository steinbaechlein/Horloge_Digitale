#include "ihmhorloge.h"
#include "horlogedigitale.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QKeySequence>

const int PERIODE = 1000; // Définition de la constante PERIODE

IHMHorloge::IHMHorloge(QWidget *parent) : QWidget(parent) {
    // Les widgets
    horloge = new HorlogeDigitale(this);
    editionHeure = new QTimeEdit(QTime::currentTime(), this);
    editionHeure->setDisplayFormat("HH:mm");
    boutonReglage = new QPushButton("Régler");
    boutonReglage->setDefault(true);
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setShortcut(QKeySequence(QKeySequence::Quit)); // Ctrl+Q
    addAction(actionQuitter); // Ajout de l'action à la fenêtre

    // Le positionnement
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(horloge);
    layoutPrincipal->addWidget(editionHeure);
    layoutPrincipal->addWidget(boutonReglage);
    setLayout(layoutPrincipal);

    // Les signaux/slots
    connect(this, SIGNAL(depart(int)), horloge, SLOT(demarrer(int)));
    connect(this, SIGNAL(arret()), horloge, SLOT(arreter()));
    connect(boutonReglage, SIGNAL(clicked()), this, SLOT(regler()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));

    // La fenêtre
    setWindowTitle("Horloge digitale");
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    // Initialisation
    horloge->fixer(editionHeure->time().hour(), editionHeure->time().minute());
    emit depart(PERIODE); // Démarrage de l’horloge avec la constante PERIODE
}

IHMHorloge::~IHMHorloge() {
    qDebug() << "~IHMHorloge()";
    // Arrêt de l’horloge
    emit arret();
}

void IHMHorloge::regler() {
    // Arrêt de l’horloge
    emit arret();
    // Paramétrage de l’horloge
    int minutes = editionHeure->time().minute();
    int heures = editionHeure->time().hour();
    horloge->fixer(heures, minutes);
    // Redémarrage de l’horloge
    emit depart(PERIODE);
}

void IHMHorloge::quitter() {
    // Fermeture de la fenêtre
    close();
}

