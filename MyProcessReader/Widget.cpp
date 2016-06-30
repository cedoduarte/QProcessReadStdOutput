/**************************************************************************
** Author: Carlos Enrique Duarte Ortiz
** Company: DuarteCorporation Tutoriales
** WebPage: https://www.youtube.com/c/duartecorporationtutoriales
**
**************************************************************************/
#include "Widget.h"
#include "ui_Widget.h"
#include <QProcess>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mProcess = new QProcess(this);

    ui->argsListWidget->addActions({ ui->actionEliminar_argumento });

    connect(mProcess, &QProcess::readyReadStandardOutput, [&]()
    {
        auto data = mProcess->readAllStandardOutput();
        ui->plainTextEdit->appendPlainText(data);
    });

    connect(mProcess, &QProcess::readyReadStandardError, [&]()
    {
        auto data = mProcess->readAllStandardError();
        ui->plainTextEdit->appendPlainText(data);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_explorarToolButton_clicked()
{
    auto filename = QFileDialog::getOpenFileName(this,
            "Abrir ejecutable", "/", "EXE files (*.exe)");
    if (filename.isEmpty()) {
        return;
    }
    ui->programaLineEdit->setText(filename);
}

void Widget::on_agregarPushButton_clicked()
{
    auto arg = ui->argumentoLineEdit->text();
    if (arg.isEmpty()) {
        return;
    }
    ui->argsListWidget->addItem(arg);
}

void Widget::on_ejecutarPushButton_clicked()
{
    auto program = ui->programaLineEdit->text();
    if (program.isEmpty()) {
        return;
    }
    QStringList args;
    const int count = ui->argsListWidget->count();
    for (int x = 0; x < count; ++x) {
        args << ui->argsListWidget->item(x)->text();
    }
    mProcess->setArguments(args);
    mProcess->setProgram(program);
    mProcess->start();
}

void Widget::on_quitarPushButton_clicked()
{
    close();
}

void Widget::on_actionEliminar_argumento_triggered()
{
    delete ui->argsListWidget->currentItem();
}
