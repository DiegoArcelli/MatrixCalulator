#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QString title, int n){

    this->setWindowTitle(title);
    this->n = n;
    c1 = n;
    r1 = n;
    cp = n;
    rp = n;
    cp2 = n;
    QWidget *selectorFrame = new QWidget(this); //frame del selezionatore
    QWidget *mainFrame = new QWidget(this); //frame della parte operativa
    QGridLayout *frameLayout = new QGridLayout(); //layout della finestra
    frameLayout->cellRect(1,2); //inutile
    QWidget *central = new QWidget; //frame della finestra
    central->setLayout(frameLayout); //imposta alla finestra un grid layout
    setCentralWidget(central); //imposta il frame come princpipale
    frameLayout->addWidget(selectorFrame); //aggiunge alla finesra principale il frame del selettore
    frameLayout->addWidget(mainFrame); //aggiunge alla finestra principale il frame della parte operativa
    QHBoxLayout *selectorLayout = new QHBoxLayout; //layout del selettore
    QComboBox *comb = new QComboBox(); //selettore dell'operazione
    comb->addItem("Determinant");
    comb->addItem("Addition");
    comb->addItem("Multiplication");
    selectorLayout->addWidget(comb); //aggiunge alla finestra del selettore il menu a tendida di selezione
    selectorFrame->setLayout(selectorLayout); //imposto al frame del selettore il layoyt orizzontale
    comb->setFixedWidth(120); //larghezza combo box
    QPalette pal;
    //pal.setColor(QPalette::Background,Qt::white);
    selectorFrame->setAutoFillBackground(true);
    selectorFrame->setPalette(pal);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QStackedLayout *stackedLayout = new QStackedLayout; //layout a pila del frame operativo
    mainFrame->setLayout(mainLayout); //adda il layout al frame operativo
    QWidget *determinat = new QWidget(); //tre sottofinestre della pila
    QWidget *addition = new QWidget();
    QWidget *multiplication = new QWidget();
    stackedLayout->addWidget(determinat); //adda le tre sotto finestre al frame operativo
    stackedLayout->addWidget(addition);
    stackedLayout->addWidget(multiplication);
    QWidget *matrixFrame = new QWidget(determinat); //crea il frame della matrice
    QVBoxLayout *determinatLayout = new QVBoxLayout; //imposta
    determinat->setLayout(determinatLayout);
    determinatLayout->addWidget(matrixFrame);
    mainLayout->addLayout(stackedLayout);
    connect(comb, SIGNAL(activated(int)),stackedLayout, SLOT(setCurrentIndex(int)));
    QWidget *pulsantiera = new QWidget;
    QLabel *descr = new QLabel("Insert matrix dimension:");
    QLineEdit *dim = new QLineEdit();
    QPushButton *resize = new QPushButton("Resize");
    QPushButton *calc = new QPushButton("Calculate");
    dim->setFixedWidth(50);
    QHBoxLayout *pulsantieraLayout = new QHBoxLayout;

    pulsantiera->setLayout(pulsantieraLayout);
    pulsantieraLayout->addWidget(descr);
    pulsantieraLayout->addWidget(dim);
    pulsantieraLayout->addWidget(resize);
    pulsantieraLayout->addWidget(calc);


    QGridLayout *griglia = new QGridLayout();
    for(int i=0;i<n;i++){
        matrix.append(QVector<QLineEdit*>());
        for(int j=0;j<n;j++){
            matrix[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]->setFixedSize(30,30);
            matrix[i][j]->setText("0");
            matrix[i][j]->setAlignment(Qt::AlignCenter);
            griglia->addWidget(matrix[i][j],i,j);
        }
    }
    matrixFrame->setLayout(griglia);


    QWidget *resultFrame = new QWidget;
    QHBoxLayout *resultLayout = new QHBoxLayout;
    QLabel *resultLabel = new QLabel("");
    resultFrame->setLayout(resultLayout);
    resultLayout->addWidget(resultLabel);


    determinatLayout->addWidget(pulsantiera);
    determinatLayout->addWidget(matrixFrame);
    determinatLayout->addWidget(resultFrame);


    QVBoxLayout *additionLayout = new QVBoxLayout;
    QWidget *pulsantieraAdd = new QWidget;
    QLabel *descrAdd = new QLabel("Insert matrices dimensions:");
    QLineEdit *dimAdd1 = new QLineEdit();
    QLineEdit *dimAdd2 = new QLineEdit();
    QPushButton *resizeAdd = new QPushButton("Resize");
    QPushButton *calcAdd = new QPushButton("Calculate");
    dimAdd1->setFixedWidth(50);
    dimAdd2->setFixedWidth(50);
    QLabel *per = new QLabel("x");
    QHBoxLayout *pulsantieraLayoutAdd = new QHBoxLayout;

    pulsantieraAdd->setLayout(pulsantieraLayoutAdd);
    pulsantieraLayoutAdd->addWidget(descrAdd);
    pulsantieraLayoutAdd->addWidget(dimAdd1);
    pulsantieraLayoutAdd->addWidget(per);
    pulsantieraLayoutAdd->addWidget(dimAdd2);
    pulsantieraLayoutAdd->addWidget(resizeAdd);
    pulsantieraLayoutAdd->addWidget(calcAdd);

    additionLayout->addWidget(pulsantieraAdd);
    addition->setLayout(additionLayout);

    QWidget *addMatrixFrame = new QWidget;
    QWidget *matrix1 = new QWidget;
    QWidget *matrix2 = new QWidget;
    QWidget *matrix3 = new QWidget;
    QLabel *plus = new QLabel("+");
    QLabel *equal = new QLabel("=");
    QHBoxLayout *matriciesAdd = new QHBoxLayout;

    QGridLayout *grigliaAdd1 = new QGridLayout();
    QGridLayout *grigliaAdd2 = new QGridLayout();
    QGridLayout *grigliaAdd3 = new QGridLayout();
    for(int i=0;i<r1;i++){
        add1.append(QVector<QLineEdit*>());
        add2.append(QVector<QLineEdit*>());
        resAdd.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            add1[i].append(new QLineEdit);
            add2[i].append(new QLineEdit);
            resAdd[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            add1[i][j]->setFixedSize(30,30);
            add1[i][j]->setText("0");
            add1[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd1->addWidget(add1[i][j],i,j);
            add2[i][j]->setFixedSize(30,30);
            add2[i][j]->setText("0");
            add2[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd2->addWidget(add2[i][j],i,j);
            resAdd[i][j]->setFixedSize(30,30);
            resAdd[i][j]->setText("0");
            resAdd[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd3->addWidget(resAdd[i][j],i,j);
        }
    }
    matriciesAdd->addWidget(matrix1);
    matriciesAdd->addWidget(plus);
    matriciesAdd->addWidget(matrix2);
    matriciesAdd->addWidget(equal);
    matriciesAdd->addWidget(matrix3);
    matrix1->setLayout(grigliaAdd1);
    matrix2->setLayout(grigliaAdd2);
    matrix3 ->setLayout(grigliaAdd3);
    addMatrixFrame->setLayout(matriciesAdd);
    additionLayout->addWidget(addMatrixFrame);


    //mutiliplcaaaa

    QVBoxLayout *mulLayout = new QVBoxLayout;
    QWidget *pulsantieraMul = new QWidget;
    QLabel *descrMul = new QLabel("Insert matrices dimensions:");
    QLineEdit *dimMul1 = new QLineEdit();
    QLineEdit *dimMul2 = new QLineEdit();
    QLineEdit *dimMul3 = new QLineEdit();
    QPushButton *resizeMul = new QPushButton("Resize");
    QPushButton *calcMul = new QPushButton("Calculate");
    dimMul1->setFixedWidth(50);
    dimMul2->setFixedWidth(50);
    dimMul3->setFixedWidth(50);
    QHBoxLayout *pulsantieraLayoutMul = new QHBoxLayout;

    pulsantieraMul->setLayout(pulsantieraLayoutMul);
    pulsantieraLayoutMul->addWidget(descrMul);
    pulsantieraLayoutMul->addWidget(dimMul1);
    pulsantieraLayoutMul->addWidget(dimMul2);
    pulsantieraLayoutMul->addWidget(dimMul3);
    pulsantieraLayoutMul->addWidget(resizeMul);
    pulsantieraLayoutMul->addWidget(calcMul);

    mulLayout->addWidget(pulsantieraMul);
    multiplication->setLayout(mulLayout);

    QWidget *mulMatrixFrame = new QWidget;
    QWidget *matrix1mul = new QWidget;
    QWidget *matrix2mul = new QWidget;
    QWidget *matrix3mul = new QWidget;
    QLabel *prod = new QLabel("x");
    QHBoxLayout *matriciesMul = new QHBoxLayout;

    QGridLayout *grigliaMul1 = new QGridLayout();
    QGridLayout *grigliaMul2 = new QGridLayout();
    QGridLayout *grigliaMul3 = new QGridLayout();
    for(int i=0;i<rp;i++){
        mul1.append(QVector<QLineEdit*>());
        mul2.append(QVector<QLineEdit*>());
        resMul.append(QVector<QLineEdit*>());
        for(int j=0;j<cp;j++){
            mul1[i].append(new QLineEdit);
            mul2[i].append(new QLineEdit);
            resMul[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp;j++){
            mul1[i][j]->setFixedSize(30,30);
            mul1[i][j]->setText("0");
            mul1[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul1->addWidget(mul1[i][j],i,j);
            mul2[i][j]->setFixedSize(30,30);
            mul2[i][j]->setText("0");
            mul2[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul2->addWidget(mul2[i][j],i,j);
            resMul[i][j]->setFixedSize(30,30);
            resMul[i][j]->setText("0");
            resMul[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul3->addWidget(resMul[i][j],i,j);
        }
    }
    matriciesMul->addWidget(matrix1mul);
    matriciesMul->addWidget(prod);
    matriciesMul->addWidget(matrix2mul);
    matriciesMul->addWidget(equal);
    matriciesMul->addWidget(matrix3mul);
    matrix1mul->setLayout(grigliaMul1);
    matrix2mul->setLayout(grigliaMul2);
    matrix3mul->setLayout(grigliaMul3);
    mulMatrixFrame->setLayout(matriciesMul);
    mulLayout->addWidget(mulMatrixFrame);


    this->connect(calc,&QPushButton::clicked,
        [this, resultLabel](){
            calculateDeterminant(resultLabel);
        }
    );

    this->connect(resize,&QPushButton::clicked,
        [this,griglia,dim,matrixFrame](){
            resizeDeterminantMatrix(griglia,dim,matrixFrame);
        }
    );

    this->connect(resizeAdd,&QPushButton::clicked,
        [this,grigliaAdd1,grigliaAdd2,grigliaAdd3,dimAdd1,dimAdd2,matrix1,matrix2,matrix3](){
            resizeAdditionMatrix(grigliaAdd1,grigliaAdd2,grigliaAdd3,dimAdd1,dimAdd2,matrix1,matrix2,matrix3);
        }
    );

    this->connect(resizeMul,&QPushButton::clicked,
        [this,grigliaMul1,grigliaMul2,grigliaMul3,dimMul1,dimMul2,dimMul3,matrix1mul,matrix2mul,matrix3mul](){
            resizeMultiplicationMatrix(grigliaMul1,grigliaMul2,grigliaMul3,dimMul1,dimMul2,dimMul3,matrix1mul,matrix2mul,matrix3mul);
        }
    );

    this->connect(calcAdd,&QPushButton::clicked,
        [this](){
            calculateAddition();
        }
    );


    this->connect(calcMul,&QPushButton::clicked,
        [this](){
            calculateProduct();
        }
    );

}

void MainWindow::calculateDeterminant(QLabel *label){
    Matrix m(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x = matrix.at(i).at(j)->text().toInt();
            m.setCella(i,j,x);
        }
    }
    int det = m.calcolaDeterminanteRicorsiva();
    label->setText("Determinat: " + QString::number(det));
    label->setAlignment(Qt::AlignCenter);

}

void MainWindow::calculateAddition(){
    Matrix m1(r1,c1);
    Matrix m2(r1,c1);
    Matrix res(r1,c1);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            m1.setCella(i,j,add1.at(i).at(j)->text().toInt());
            m2.setCella(i,j,add2.at(i).at(j)->text().toInt());
        }
    }
    res = Matrix::somma(m1,m2);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            resAdd.at(i).at(j)->setText(QString::number(res.getCella(i,j)));
        }
    }
}

void MainWindow::calculateProduct(){
    Matrix m1(rp,cp);
    Matrix m2(cp,cp2);
    Matrix res(rp,cp2);
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp;j++){
            m1.setCella(i,j,mul1.at(i).at(j)->text().toInt());
        }
    }
    for(int i=0;i<cp;i++){
        for(int j=0;j<cp2;j++){
            m2.setCella(i,j,mul2.at(i).at(j)->text().toInt());
        }
    }
    res = Matrix::prodotto(m1,m2);
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp2;j++){
            resMul.at(i).at(j)->setText(QString::number(res.getCella(i,j)));
        }
    }
}

void MainWindow::resizeDeterminantMatrix(QGridLayout *griglia, QLineEdit* dim, QWidget *matrixFrame){
    int x = dim->text().toInt();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            delete matrix[i][j];
        }
    }
    matrix.clear();
    n = x;
    delete griglia;
    griglia = new QGridLayout();
    for(int i=0;i<n;i++){
        matrix.append(QVector<QLineEdit*>());
        for(int j=0;j<n;j++){
            matrix[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]->setFixedSize(30,30);
            matrix[i][j]->setText("0");
            matrix[i][j]->setAlignment(Qt::AlignCenter);
            griglia->addWidget(matrix[i][j],i,j);
        }
    }
    matrixFrame->setLayout(griglia);
    griglia->update();
    matrixFrame->update();
}

void MainWindow::resizeAdditionMatrix(QGridLayout *grigliaAdd1, QGridLayout *grigliaAdd2, QGridLayout *grigliaAdd3, QLineEdit *dimAdd1, QLineEdit *dimAdd2, QWidget *matrix1, QWidget *matrix2, QWidget *matrix3){
    int x1 = dimAdd1->text().toInt();
    int x2 = dimAdd2->text().toInt();
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            delete add1[i][j];
        }
    }
    add1.clear();
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            delete add2[i][j];
        }
    }
    add2.clear();
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            delete resAdd[i][j];
        }
    }
    resAdd.clear();
    c1 = x2;
    r1 = x1;
    delete grigliaAdd1;
    grigliaAdd1 = new QGridLayout();
    for(int i=0;i<r1;i++){
        add1.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            add1[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            add1[i][j]->setFixedSize(30,30);
            add1[i][j]->setText("0");
            add1[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd1->addWidget(add1[i][j],i,j);
        }
    }
    matrix1->setLayout(grigliaAdd1);
    grigliaAdd1->update();
    matrix1->update();

    delete grigliaAdd2;
    grigliaAdd2 = new QGridLayout();
    for(int i=0;i<r1;i++){
        add2.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            add2[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            add2[i][j]->setFixedSize(30,30);
            add2[i][j]->setText("0");
            add2[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd2->addWidget(add2[i][j],i,j);
        }
    }
    matrix2->setLayout(grigliaAdd2);
    grigliaAdd2->update();
    matrix2->update();

    delete grigliaAdd3;
    grigliaAdd3 = new QGridLayout();
    for(int i=0;i<r1;i++){
        resAdd.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            resAdd[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            resAdd[i][j]->setFixedSize(30,30);
            resAdd[i][j]->setText("0");
            resAdd[i][j]->setAlignment(Qt::AlignCenter);
            grigliaAdd3->addWidget(resAdd[i][j],i,j);
        }
    }
    matrix3->setLayout(grigliaAdd3);
    grigliaAdd3->update();
    matrix3->update();
}

void MainWindow::resizeMultiplicationMatrix(QGridLayout *grigliaMul1, QGridLayout *grigliaMul2, QGridLayout *grigliaMul3, QLineEdit *dimMul1, QLineEdit *dimMul2, QLineEdit *dimMul3, QWidget *matrix1, QWidget *matrix2, QWidget *matrix3){
    int x1 = dimMul1->text().toInt();
    int x2 = dimMul2->text().toInt();
    int x3 = dimMul3->text().toInt();
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp;j++){
            delete mul1[i][j];
        }
    }
    mul1.clear();
    for(int i=0;i<cp;i++){
        for(int j=0;j<cp2;j++){
            delete mul2[i][j];
        }
    }
    mul2.clear();
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp2;j++){
            delete resMul[i][j];
        }
    }
    resMul.clear();
    rp = x1;
    cp = x2;
    cp2 = x3;
    delete grigliaMul1;
    grigliaMul1 = new QGridLayout();
    for(int i=0;i<rp;i++){
        mul1.append(QVector<QLineEdit*>());
        for(int j=0;j<cp;j++){
            mul1[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp;j++){
            mul1[i][j]->setFixedSize(30,30);
            mul1[i][j]->setText("0");
            mul1[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul1->addWidget(mul1[i][j],i,j);
        }
    }
    matrix1->setLayout(grigliaMul1);
    grigliaMul1->update();
    matrix1->update();

    delete grigliaMul2;
    grigliaMul2 = new QGridLayout();
    for(int i=0;i<cp;i++){
        mul2.append(QVector<QLineEdit*>());
        for(int j=0;j<cp2;j++){
            mul2[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<cp;i++){
        for(int j=0;j<cp2;j++){
            mul2[i][j]->setFixedSize(30,30);
            mul2[i][j]->setText("0");
            mul2[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul2->addWidget(mul2[i][j],i,j);
        }
    }
    matrix2->setLayout(grigliaMul2);
    grigliaMul2->update();
    matrix2->update();

    delete grigliaMul3;
    grigliaMul2 = new QGridLayout();
    for(int i=0;i<rp;i++){
        resMul.append(QVector<QLineEdit*>());
        for(int j=0;j<cp2;j++){
            resMul[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<rp;i++){
        for(int j=0;j<cp2;j++){
            resMul[i][j]->setFixedSize(30,30);
            resMul[i][j]->setText("0");
            resMul[i][j]->setAlignment(Qt::AlignCenter);
            grigliaMul3->addWidget(resMul[i][j],i,j);
        }
    }
    matrix3->setLayout(grigliaMul3);
    grigliaMul3->update();
    matrix3->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
