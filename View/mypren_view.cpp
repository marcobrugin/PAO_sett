#include "mypren_view.h"

myPren_view::myPren_view(){}
QString myPren_view::getMail() const { return mail; }

myPren_view::myPren_view(const QSize& s, const QString& m, View* parent) : View(s, parent), mail(m), pren_table(new QTableWidget(this)) {
    vbox=new QVBoxLayout(this);
    hbox=new QHBoxLayout(this);
    QLabel* titolo=new QLabel("VISUALIZZAZIONE LE MIE PRENOTAZIONI ", this);
    hbox->addWidget(titolo);
    hbox->addStretch();
    indietro = new QPushButton("Torna al menu", this);
    hbox->addWidget(indietro);

    vbox->addLayout(hbox);
    connect(indietro,SIGNAL(clicked(bool)),this,SIGNAL(indietro_signal()));
}

void myPren_view::create_table(const QStringList& intestazioni){
    pren_table->setColumnCount(8);
    pren_table->setHorizontalHeaderLabels(intestazioni);
    pren_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pren_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pren_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    vbox->addWidget(pren_table);
}

void myPren_view::carica_pren(const contenitore<prenotazione*>& pren){
    int i=0;
    for(auto j: pren){
        QString pers=QString::fromStdString(j->getPersona());
        if(pers==(this->getMail())){
        pren_table->insertRow(i);
        QLabel* aulaLabel = new QLabel(QString::number(j->getAula()), this);
        pren_table->setCellWidget(i, 0, aulaLabel);
        QLabel* dataLabel = new QLabel(j->getData().toString("dd/MM/yyyy"), this);
        pren_table->setCellWidget(i, 1, dataLabel);
        QLabel* oraArrivoLabel = new QLabel(j->getOraArrivo().toString("hh:mm"), this);
        pren_table->setCellWidget(i, 2, oraArrivoLabel);
        QLabel* oraUscitaLabel = new QLabel(j->getOraUscita().toString("hh:mm"), this);
        pren_table->setCellWidget(i, 3, oraUscitaLabel);
        QLabel* causaleLabel = new QLabel(QString::fromStdString(j->getCausale()), this);
        pren_table->setCellWidget(i, 4, causaleLabel);
        QLabel* emailLabel = new QLabel(QString::fromStdString(j->getPersona()), this);
        pren_table->setCellWidget(i, 5, emailLabel);
        QPixmap pixmap(":/Images/delete.svg");
        QPushButton *rimuovi = new QPushButton(this);
        rimuovi->setIcon(QIcon(pixmap));
        pren_table->setCellWidget(i, 6, rimuovi);
        connect (rimuovi, &QPushButton::clicked,[this, rimuovi](){
            unsigned int riga = pren_table->indexAt(rimuovi->pos()).row();
            emit rimuovi_prenotazione(riga);
        });
        i++;
        }
    }

    QDate oggi = QDate::currentDate();

    int annoAccademico=oggi.year();
    if (oggi.month() > 7 || (oggi.month() == 7 && oggi.day() >= 15)) {
        annoAccademico++; // Incrementa il range di annuale disponibile se oggi>15.07
    }

    pren_table->insertRow(i);

    _aula = new QLineEdit(this);
    validator = new QRegularExpressionValidator(QRegularExpression("[0-9]+"), _aula);
    _aula->setValidator(validator);
    pren_table->setCellWidget(i,0,_aula);
    _data = new QDateEdit(this);
    _data->setCalendarPopup(true); // Abilita il calendario a comparsa
    _data->setDateRange(oggi.addDays(1), QDate(annoAccademico, 7, 15)); // Imposta il range di date
    pren_table->setCellWidget(i,1,_data);
    _oraArrivo = new QTimeEdit(this);
    _oraArrivo->setDisplayFormat("hh:mm");
    _oraArrivo->setTimeRange(QTime(9, 0), QTime(18, 30));
    pren_table->setCellWidget(i,2,_oraArrivo);
    _oraUscita = new QTimeEdit(this);
    _oraUscita->setDisplayFormat("hh:mm"); // Imposta il formato di visualizzazione senza i secondi
    _oraUscita->setTimeRange(QTime(9, 30), QTime(19, 0));
    pren_table->setCellWidget(i,3,_oraUscita);
    _causale = new QTextEdit(this);
    pren_table->setCellWidget(i,4,_causale);
    _mail = new QLabel(this->getMail(), this);
    pren_table->setCellWidget(i,5,_mail);
    QPushButton* vuoto = new QPushButton(this);
    pren_table->setCellWidget(i,6,vuoto);
    QPixmap pixmapA(":/Images/add.svg");
    aggiungi = new QPushButton(this);
    aggiungi->setIcon(QIcon(pixmapA));
    pren_table->setCellWidget(i,7,aggiungi);
    pren_table->resizeColumnsToContents();

    // Connessione del pulsante di login allo slot onLoginButtonClicked()
    connect(aggiungi, SIGNAL(clicked()), this, SLOT(aggiungi_pren()));
}

void myPren_view::addToView(prenotazione* pr){
    pren_table->insertRow(pren_table->rowCount()-1);
    pren_table->setCellWidget(pren_table->rowCount()-2,0,new QLabel(QString::number(pr->getAula()),this));
    pren_table->setCellWidget(pren_table->rowCount()-2,1,new QLabel(pr->getData().toString("dd/MM/yyyy"),this));
    pren_table->setCellWidget(pren_table->rowCount()-2,2,new QLabel(pr->getOraArrivo().toString("hh:mm"),this));
    pren_table->setCellWidget(pren_table->rowCount()-2,3,new QLabel(pr->getOraUscita().toString("hh:mm"),this));
    pren_table->setCellWidget(pren_table->rowCount()-2,4,new QLabel(QString::fromStdString(pr->getCausale()),this));
    pren_table->setCellWidget(pren_table->rowCount()-2,5,new QLabel(QString::fromStdString(pr->getPersona()),this));

    QPixmap pixmap(":/Images/delete.svg");
    QPushButton *remove = new QPushButton(this);
    remove->setIcon(QIcon(pixmap));
    pren_table->setCellWidget(pren_table->rowCount()-2,6,remove);
    connect(remove, &QPushButton::clicked,[this,remove](){
        unsigned int riga = pren_table->indexAt(remove->pos()).row();
        emit rimuovi_signal(riga);
    });

}

void myPren_view::aggiungi_pren(){
    int aula = (_aula->text()).toInt();
    QDate data = _data->date();
    QTime oraArrivo= _oraArrivo->time();
    QTime oraUscita= _oraArrivo->time();
    QString causale= _causale->toPlainText();
    QString mail= _mail->text();

    //controllo errori basilari
    if(aula==NULL || data.isNull() || oraArrivo.isNull() || oraUscita.isNull() || causale.isEmpty() || causale.isNull()){
        static_cast<View*>(this)->showError("Inserimento non valido", "I valori inseriti non sono accettati");
    }
    else{
        emit aggiungi_signal(aula, data, oraArrivo, oraUscita, causale, mail);
    }
}
void myPren_view::rimuovi_prenotazione(uint i){
    emit rimuovi_signal(i);
}

void myPren_view::chiudi(uint a){
    pren_table->removeRow(a);
}

void myPren_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}

