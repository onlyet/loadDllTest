#pragma once

#include <QObject>


class Q_DECL_IMPORT EnumOfficeFile : public QObject
{
    Q_OBJECT

public:
    explicit EnumOfficeFile(QObject *parent = nullptr);
    virtual ~EnumOfficeFile() {}

    QStringList enumOfficeFilePath(const QString& suffix);

};


