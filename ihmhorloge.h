#ifndef IHMHORLOGE_H
#define IHMHORLOGE_H

#include <QWidget>
#include <QPushButton>
#include <QTimeEdit>

class HorlogeDigitale;

class IHMHorloge : public QWidget
{
    Q_OBJECT

private:
    // Les widgets
    QPushButton *boutonReglage;
    HorlogeDigitale *horloge;
    QTimeEdit *editionHeure;

public:
    IHMHorloge(QWidget *parent = nullptr);
    ~IHMHorloge();

private slots:
    void regler();
    void quitter();

signals:
    void depart(int);
    void arret();
};

#endif // IHMHORLOGE_H
