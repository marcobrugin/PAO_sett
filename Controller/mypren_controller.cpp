#include "mypren_controller.h"

MyPrenController::MyPrenController(){}

MyPrenController::MyPrenController(storage* s, myPren_view * a, Controller* c) : Controller(s, a, c){
    view->setTitolo("VISUALIZZAZIONE LE MIE PRENOTAZIONI");
    getView()->create_table({"Numero Aula","Data","Ora Arrivo", "Ora Uscita", "Causale", "Email utente","Rimuovi","Aggiungi"});
    getView()->carica_pren(s->getContPren());

    connect(view,SIGNAL(rimuovi_signal(uint)),this,SLOT(rimuovi_enter(uint)));
    connect(view,SIGNAL(aggiugi_signal(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&)),this,SLOT(aggiungi_enter(const int&, const QDate&, const QTime&, const QTime&, const QString&, const QString&)));
    connect(view,SIGNAL(indietro_signal()),this,SLOT(indietro_enter()));
}

storage* MyPrenController::getModel()const {
    return static_cast<storage*>(mod);
}

myPren_view* MyPrenController::getView() const{
    return static_cast<myPren_view*>(view) ;
}

void MyPrenController::aggiungi_enter(const int& _aula, const QDate& data, const QTime& oraArrivo, const QTime& oraUscita, const QString& causale, const QString& mail) const {
    string _causale=causale.toStdString();
    //string _mail=mail.toStdString();
    string ut;
    int au;
    for(auto i : getModel()->getContPren()){
        if(i->getAula() == _aula && i->getData()==data ){
            QTime arrivo= i->getOraArrivo();
            QTime uscita= i->getOraUscita();
            if((oraArrivo>=arrivo && oraArrivo<uscita) || (oraUscita>arrivo && oraUscita<=uscita) || (oraArrivo<= arrivo && oraUscita>=uscita)){
                view->showError("Prenotazione errata","L'aula è già occupata nell'ora/data selezionata");
            }
            return;
        }
        ut=i->getPersona();
        au=i->getAula();

        //PROVA DI CONTROLLO DELL'ESISTENZA DEL NUMERO DELL'AULA
        /*bool trovato=false;
            for(auto j: getModel()->getContAula1()){
            if(j->getNumero==au)
                trovato=true;
        }*/
    }
    prenotazione* nuova = new prenotazione(ut,data,oraArrivo,oraUscita,_causale,_aula);
    getModel()->addPrenotazione(nuova);
    getView()->addToView(nuova);
}

void MyPrenController::rimuovi_enter(uint i){
    getModel()->removePrenotazione(i);
    getView()->chiudi(i);
}

void MyPrenController::indietro_enter() {
    static_cast<const MenuController*>(this->parent())->show();
    this->hide();
}

void MyPrenController::onViewClosed() const {
    delete this;
}
