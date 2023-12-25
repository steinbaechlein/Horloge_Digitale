#ifndef HORLOGEDIGITALE_H
#define HORLOGEDIGITALE_H

#include <QLCDNumber>
#include <QTimer>

class HorlogeDigitale : public QLCDNumber {
    Q_OBJECT

public:
    explicit HorlogeDigitale(QWidget *parent = nullptr);
    ~HorlogeDigitale();

    long getMinute();
    long getHeure();
    void fixer(int h, int m);
    void update();

public slots:
    void tic();
    void demarrer(int top = PERIODE);
    void arreter();

private:
    int m_valeur;
    QTimer *m_timer;
    static const int PERIODE = 1000; // Période par défaut pour l'horloge
};

#endif // HORLOGEDIGITALE_H
