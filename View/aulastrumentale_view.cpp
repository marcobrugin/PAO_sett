#include "aulastrumentale_view.h"

aulaStrumentale_view::aulaStrumentale_view(const QSize& s, View* parent) : Aula_View(s,parent), table(new QTableWidget(this)){
    vbox=new QVBoxLayout(this);
}


void aulaStrumentale_view::createTable(const QStringList& headers){
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(headers);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    table->setColumnWidth(4,25);
    vbox->addWidget(table);
}
void aulaStrumentale_view::carica_view(const contenitore<aula*>& au){
    int i=0;
    for(auto j: au){
        table->insertRow(i);
        aulaStrumentale* as= static_cast<aulaStrumentale*>(j);
        QLabel* pianoLabel = new QLabel(QString::number(as->getPiano()), this);
        table->setCellWidget(i, 0, pianoLabel);
        QLabel* numeroLabel = new QLabel(QString::number(as->getNumero()), this);
        table->setCellWidget(i, 1, numeroLabel);
        QLabel* sedeLabel = new QLabel(QString::fromStdString(as->getSede()), this);
        table->setCellWidget(i, 2, sedeLabel);
        QLabel* persLabel = new QLabel(QString::number(as->getMaxPersone()), this);
        table->setCellWidget(i, 3, persLabel);
        QLabel* strumentoLabel = new QLabel(QString::fromStdString(as->getStrumento()), this);
        table->setCellWidget(i, 4, strumentoLabel);

        i++;
    }

    table->insertRow(i);
    _piano = new QLineEdit(this);
    validator = new QRegularExpressionValidator(QRegularExpression("[0-9]+"), _piano);
    _piano->setValidator(validator);
    table->setCellWidget(i,0,_piano);

    _numero = new QLineEdit(this);
    validator = new QRegularExpressionValidator(QRegularExpression("[0-9]+"), _numero);
    _numero->setValidator(validator);
    table->setCellWidget(i,1,_numero);

    _sede = new QTextEdit(this);
    table->setCellWidget(i,2,_sede);

    _pers = new QLineEdit(this);
    validator = new QRegularExpressionValidator(QRegularExpression("[0-9]+"), _pers);
    _pers->setValidator(validator);
    table->setCellWidget(i,3,_pers);

    _strumento = new QTextEdit(this);
    table->setCellWidget(i,4,_strumento);

    aggiungi = new QPushButton ("+", this);
    table->setCellWidget(i,5,aggiungi);
    table->resizeColumnsToContents();

    // Connessione del pulsante
    connect(aggiungi, SIGNAL(clicked()), this, SIGNAL (ButtonClicked()));
    connect(this,SIGNAL(ButtonClicked()),this,SLOT(aggiungi_pren()));
}
void aulaStrumentale_view::addToView(aula* b) {
    aulaStrumentale* a= static_cast<aulaStrumentale*>(b);
    table->insertRow(table->rowCount()-1);
    table->setCellWidget(table->rowCount()-2,0,new QLabel(QString::number(a->getPiano()),this));
    table->setCellWidget(table->rowCount()-2,1,new QLabel(QString::number(a->getNumero()),this));
    table->setCellWidget(table->rowCount()-2,2,new QLabel(QString::fromStdString(a->getSede()),this));
    table->setCellWidget(table->rowCount()-2,3,new QLabel(QString::number(a->getMaxPersone()),this));
    table->setCellWidget(table->rowCount()-2,4,new QLabel(QString::fromStdString(a->getStrumento()),this));

    QPushButton* remove=new QPushButton("-",this);
    table->setCellWidget(table->rowCount()-2,6,remove);
    connect(remove, &QPushButton::clicked,[this,remove](){
        unsigned int riga = table->indexAt(remove->pos()).row();
        emit rimuovi_signal_str(riga);
    });
}
void aulaStrumentale_view::rimuovi_aula(uint i){
    table->removeRow(i);
    emit rimuovi_signal_strumentale(i);
}

void aulaStrumentale_view::closeEvent(QCloseEvent *event) {
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}

