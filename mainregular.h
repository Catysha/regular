#ifndef MAINREGULAR_H
#define MAINREGULAR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainRegular;
}
QT_END_NAMESPACE

class MainRegular : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainRegular(QWidget *parent = nullptr);
    ~MainRegular();
private slots:
    void regularHTML();
    void handleReject();
    void clearResult();
private:
    Ui::MainRegular *ui;
    QLineEdit *stringInput;
    QDialogButtonBox *regularHtml;
    QLabel *resultLabel;
};
#endif // MAINREGULAR_H
