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
    QPushButton *conf = new QPushButton("Confirm"); //tasto di conferma operazioni
    selectorLayout->addWidget(comb); //aggiunge alla finestra del selettore il menu a tendida di selezione
    selectorLayout->addWidget(conf); //aggiunge alla finestra del selettore il tasto di conferma dell'operazione
    selectorFrame->setLayout(selectorLayout); //imposto al frame del selettore il layoyt orizzontale
    comb->setFixedWidth(120); //larghezza combo box
    conf->setFixedWidth(100); //larghezza tasto di conferma
    QPalette pal;
    //pal.setColor(QPalette::Background,Qt::white);
    selectorFrame->setAutoFillBackground(true);
    selectorFrame->setPalette(pal);

    QStackedLayout *stackedLayout = new QStackedLayout; //layout a pila del frame operativo
    mainFrame->setLayout(stackedLayout); //adda il layout al frame operativo
    QWidget *determinat = new QWidget(mainFrame); //tre sottofinestre della pila
    QWidget *addition = new QWidget();
    QWidget *multiplication = new QWidget();
    stackedLayout->addWidget(determinat); //adda le tre sotto finestre al frame operativo
    //stackedLayout->addWidget(addition);
    //stackedLayout->addWidget(multiplication);
    QWidget *matrixFrame = new QWidget(determinat); //crea il frame della matrice
    QVBoxLayout *determinatLayout = new QVBoxLayout; // imposta
    determinat->setLayout(determinatLayout);
    determinatLayout->addWidget(matrixFrame);


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
            qDebug() << c1;
            int x = matrix.at(i).at(j)->text().toInt();
            m.setCella(i,j,x);
        }
    }
    int det = m.calcolaDeterminanteRicorsiva();
    label->setText("Determinat: " + QString::number(det));

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
