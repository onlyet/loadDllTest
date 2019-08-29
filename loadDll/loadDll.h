#pragma once

#include <QtWidgets/QWidget>
#include "ui_my.h"

class loadDll : public QWidget
{
    Q_OBJECT

public:
    loadDll(QWidget *parent = Q_NULLPTR);

private:
    Ui::TESTUI ui;
};
