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
    c1 = n;
    r1 = n;
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
    for(int i=0;i<c1;i++){
        matrix.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            matrix[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<c1;i++){
        for(int j=0;j<c1;j++){
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



    //addition



    QVBoxLayout *additionLayout = new QVBoxLayout;
    QWidget *pulsantieraAdd = new QWidget;
    QLabel *descrAdd = new QLabel("Insert matrices dimensions:");
    QLineEdit *dimAdd1 = new QLineEdit();
    QLineEdit *dimAdd2 = new QLineEdit();
    QPushButton *resizeAdd = new QPushButton("Resize");
    QPushButton *calcAdd = new QPushButton("Calculate");
    dimAdd1->setFixedWidth(50);
    dimAdd2->setFixedWidth(50);
    QHBoxLayout *pulsantieraLayoutAdd = new QHBoxLayout;

    pulsantieraAdd->setLayout(pulsantieraLayoutAdd);
    pulsantieraLayoutAdd->addWidget(descrAdd);
    pulsantieraLayoutAdd->addWidget(dimAdd1);
    pulsantieraLayoutAdd->addWidget(dimAdd2);
    pulsantieraLayoutAdd->addWidget(resizeAdd);
    pulsantieraLayoutAdd->addWidget(calcAdd);

    additionLayout->addWidget(pulsantieraAdd);
    addition->setLayout(additionLayout);

    QWidget *addMatrixFrame = new QWidget;
    QWidget *matrix1 = new QWidget;
    QWidget *matrix2 = new QWidget;
    QWidget *matrix3 = new QWidget;
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
    matriciesAdd->addWidget(matrix2);
    matriciesAdd->addWidget(matrix3);
    matrix1->setLayout(grigliaAdd1);
    matrix2->setLayout(grigliaAdd2);
    matrix3->setLayout(grigliaAdd3);
    addMatrixFrame->setLayout(matriciesAdd);
    additionLayout->addWidget(addMatrixFrame);



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

}

void MainWindow::calculateDeterminant(QLabel *label){
    Matrix m(c1);
    for(int i=0;i<c1;i++){
        for(int j=0;j<c1;j++){
            int x = matrix.at(i).at(j)->text().toInt();
            m.setCella(i,j,x);
        }
    }
    int det = m.calcolaDeterminanteRicorsiva();
    label->setText("Determinat: " + QString::number(det));
    label->setAlignment(Qt::AlignCenter);

}

void MainWindow::resizeDeterminantMatrix(QGridLayout *griglia, QLineEdit* dim, QWidget *matrixFrame){
    int x = dim->text().toInt();
    for(int i=0;i<c1;i++){
        for(int j=0;j<c1;j++){
            delete matrix[i][j];
        }
    }
    matrix.clear();
    c1 = x;
    r1 = x;
    delete griglia;
    griglia = new QGridLayout();
    for(int i=0;i<c1;i++){
        matrix.append(QVector<QLineEdit*>());
        for(int j=0;j<c1;j++){
            matrix[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<c1;i++){
        for(int j=0;j<c1;j++){
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

MainWindow::~MainWindow()
{
    delete ui;
}
