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
   void calculateAddition();
   void resizeDeterminantMatrix(QGridLayout *griglia, QLineEdit* dim, QWidget *matrixFrame);
   void resizeAdditionMatrix(QGridLayout *grigliaAdd1, QGridLayout *grigliaAdd2, QGridLayout *grigliaAdd3, QLineEdit *dimAdd1, QLineEdit *dimAdd2, QWidget *matrix1, QWidget *matrix2, QWidget *matrix3);
private:
    Ui::MainWindow *ui;
    QVector<QVector<QLineEdit*>> matrix;
    QVector<QVector<QLineEdit*>> add1;
    QVector<QVector<QLineEdit*>> add2;
    QVector<QVector<QLineEdit*>> resAdd;
    QVector<QVector<QLineEdit*>> mul1;
    QVector<QVector<QLineEdit*>> mul2;
    QVector<QVector<QLineEdit*>> resMul;
    int n;
    int r1;
    int c1;
    int rp;
    int cp;
};

#endif // MAINWINDOW_H
