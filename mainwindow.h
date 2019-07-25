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
#include <QDebug>

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
    void setR1(int n);
    void setC1(int n);
    int getC1();
    int getR2();
public slots:
   void calculateDeterminant(QLabel *label);
   void resizeDeterminantMatrix(QGridLayout *griglia, QLineEdit* dim, QWidget *matrixFrame);
private:
    Ui::MainWindow *ui;
    QVector<QVector<QLineEdit*>> matrix;
    int r1;
    int c1;
};

#endif // MAINWINDOW_H
