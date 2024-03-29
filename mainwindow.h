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
#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
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
   void calculateProduct();
   void resizeDeterminantMatrix(QLineEdit* dim, QWidget *matrixFrame);
   void resizeAdditionMatrix(QLineEdit *dimAdd1, QLineEdit *dimAdd2, QWidget *matrix1, QWidget *matrix2, QWidget *matrix3);
   void resizeMultiplicationMatrix(QLineEdit *dimMul1, QLineEdit *dimMul2, QLineEdit *dimMul3, QLineEdit *dimMulAuto, QWidget *matrix1, QWidget *matrix2, QWidget *matrix3);
private:
    Ui::MainWindow *ui;
    QWidget *central;
    QVector<QVector<QLineEdit*>> matrix;
    QVector<QVector<QLineEdit*>> add1;
    QVector<QVector<QLineEdit*>> add2;
    QVector<QVector<QLineEdit*>> resAdd;
    QVector<QVector<QLineEdit*>> mul1;
    QVector<QVector<QLineEdit*>> mul2;
    QVector<QVector<QLineEdit*>> resMul;
    QGridLayout *griglia;
    QGridLayout *grigliaAdd1;
    QGridLayout *grigliaAdd2;
    QGridLayout *grigliaAdd3;
    QGridLayout *grigliaMul1;
    QGridLayout *grigliaMul2;
    QGridLayout *grigliaMul3;
    int n;
    int r1;
    int c1;
    int rp;
    int cp;
    int cp2;
};

#endif // MAINWINDOW_H
