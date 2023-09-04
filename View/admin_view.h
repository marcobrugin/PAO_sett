#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "view.h"
#include "Model/storage.h"
#include "WidgetLookup.h"
#include "View/aulastudio_view.h"
#include "View/aulastrumentale_view.h"
#include "View/aulaconcerto_view.h"
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QScrollArea>
#include <QTableWidget>

class admin_view: public View {
    Q_OBJECT
private:
    aulaStudio_view * studio;
    QGridLayout* mainLayout;
    QTableWidget* ConcertoTable;
    QTableWidget* StudioTable;
    QTableWidget* StrumTable;
    QPushButton* saveButton;

protected:
    explicit admin_view();

public:
    explicit admin_view(const QSize& s, View *parent = nullptr);
    //void setViewTitle (const QString &title) override;
    void closeEvent(QCloseEvent *event) override;
signals:
    void viewClosed() const;

};

#endif // ADMIN_VIEW_H
