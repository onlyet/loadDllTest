#include "loadDll.h"
#include <EnumOfficeFilePluginInterface.h>
#include <QPluginLoader>
#include <QDebug>

loadDll::loadDll(QWidget *parent)
    : QWidget(parent)
{
    QString dllPath = "D:/dev/loadDll/device/enumOffileFile.dll";

    QPluginLoader loader(dllPath);
    if (!loader.load())
    {
        qDebug() << loader.errorString();
        return;
    }

    QObject *obj = loader.instance();
    if (obj)
    {
        EnumOfficeFilePluginInterface *enumOfficeFile = qobject_cast<EnumOfficeFilePluginInterface *>(obj);
        if (!enumOfficeFile)
        {
            qDebug() << "ERROR";
            return;
        }

        QStringList pathList = enumOfficeFile->enumOfficeFilePath("ppt");

    }
}
