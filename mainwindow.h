#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QStackedLayout>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainWindow(QString title, int n);
private slots:
   void calculateDeterminant(QLabel *label, int n, QVector<QVector<QLineEdit*>> matrix);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
