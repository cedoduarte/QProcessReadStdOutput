/**************************************************************************
** Author: Carlos Enrique Duarte Ortiz
** Company: DuarteCorporation Tutoriales
** WebPage: https://www.youtube.com/c/duartecorporationtutoriales
**
**************************************************************************/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QProcess;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_explorarToolButton_clicked();
    void on_agregarPushButton_clicked();
    void on_ejecutarPushButton_clicked();

    void on_quitarPushButton_clicked();

    void on_actionEliminar_argumento_triggered();

private:
    Ui::Widget *ui;
    QProcess *mProcess;
};

#endif // WIDGET_H
