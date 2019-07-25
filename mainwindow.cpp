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
    //QLineEdit *matrix[n][n];
    QVector<QVector<QLineEdit*>> matrix;
    for(int i=0;i<n;i++){
        matrix.append(QVector<QLineEdit*>());
        for(int j=0;j<n;j++){
            matrix[i].append(new QLineEdit);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //matrix[i][j] = new QLineEdit();
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
        [this, resultLabel, n, matrix](){
            calculateDeterminant(resultLabel,n,matrix);
        }
    );

}

void MainWindow::calculateDeterminant(QLabel *label, int n, QVector<QVector<QLineEdit*>> matrix){
    Matrix m(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m.setCella(i,j,matrix[i][j]->text().toInt());
        }
    }
    int det = m.calcolaDeterminanteRicorsiva();
    label->setText(QString::number(det));

}

MainWindow::~MainWindow()
{
    delete ui;
}
