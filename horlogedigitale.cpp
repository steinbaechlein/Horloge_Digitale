#include "horlogedigitale.h"
#include <QTimer>
#include <QString>
#include <QDebug>

HorlogeDigitale::HorlogeDigitale(QWidget *parent) : QLCDNumber(parent) {
    m_valeur = 0;
    setDigitCount(5); // Utilisez setDigitCount au lieu de setNumDigits
    setSegmentStyle(QLCDNumber::Flat); // Utilisation de QLCDNumber::Flat pour le style
    setFixedSize(this->width() * 1.5, this->height() * 1.5); // Ajustez si nécessaire

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tic()));
    update(); // Mettre à jour l'affichage initial
}

HorlogeDigitale::~HorlogeDigitale() {
    qDebug() << "~HorlogeDigitale()";
}

long HorlogeDigitale::getMinute() {
    return (m_valeur % 36000) / 600;
}

long HorlogeDigitale::getHeure() {
    return m_valeur / 36000;
}

void HorlogeDigitale::fixer(int h, int m) {
    m_valeur = h * 36000 + m * 600;
    update(); // Mettre à jour l'affichage lors du réglage de l'heure
}

void HorlogeDigitale::update() {
    QString heure = QString::number(getHeure()).rightJustified(2, '0');
    QString minute = QString::number(getMinute()).rightJustified(2, '0');
    QString text = heure + ":" + minute;
    display(text);
}

void HorlogeDigitale::tic() {
    m_valeur++;
    update();
}

void HorlogeDigitale::demarrer(int top /* = PERIODE */) {
    qDebug() << "HorlogeDigitale::demarrer()";
    m_timer->start(top);
}

void HorlogeDigitale::arreter() {
    m_timer->stop();
    qDebug() << "HorlogeDigitale::arreter()";
}
