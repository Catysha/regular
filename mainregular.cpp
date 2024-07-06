#include "mainregular.h"
#include "ui_mainregular.h"
#include <QString>
#include <QRegExp>
MainRegular::MainRegular(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainRegular)
{
    ui->setupUi(this);
    stringInput = ui -> lineEdit;
    regularHtml = ui -> buttonBox;
    resultLabel = ui -> label_2;
    connect(stringInput, &QLineEdit::textChanged, this, &MainRegular::clearResult);
    connect(regularHtml, &QDialogButtonBox::accepted, this, &MainRegular::regularHTML);
    connect(regularHtml, &QDialogButtonBox::rejected, this, &MainRegular::handleReject);
}

MainRegular::~MainRegular()
{
    delete ui;
}
void MainRegular::regularHTML()
{
    QString line = stringInput -> text();
    QRegExp regex("^#([A-Fa-f0-9]{6})$");
    if (regex.exactMatch(line))
    {
        resultLabel->setText(QString(" %1 является правильным выражением ").arg(line));
    }
    else if (line.isEmpty())
    {
        resultLabel->setText(QString(" Введите выражение и нажмите 'Ок' "));
    }
    else
    {
        resultLabel->setText(QString(" %1 является неправильным выражением ").arg(line));
    }

}
void MainRegular::handleReject()
{
    stringInput -> clear();
     resultLabel->setText(QString(" Введите выражение и нажмите 'Ок' "));
}
void MainRegular::clearResult()
{
    resultLabel->clear();
}
