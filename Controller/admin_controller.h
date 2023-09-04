#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "controller.h"
#include "View/admin_view.h"
#include "View/aula_view.h"
//#include "View/aulaconcerto_view.h"
#include "Model/storage.h"
#include "aule_controller.h"
#include <QFile>
#include <QDebug>

class AdminController: public Controller {
    Q_OBJECT
protected:
    explicit AdminController();
public:
    explicit AdminController(storage*, admin_view*, Controller* = nullptr);
    storage* getModel() const override;
    admin_view* getView() const override;
public slots:
    void onViewClosed() const override;
};

#endif // ADMIN_CONTROLLER_H
