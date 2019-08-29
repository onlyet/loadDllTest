#include "loadDll.h"
#include <EnumOfficeFilePluginInterface.h>
#include <QPluginLoader>
#include <QDebug>


loadDll::loadDll(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setFixedSize(1366, 700);

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
        if (!pathList.empty())
            ui.label->setText(pathList.at(0));
        else
            ui.label->setText("no ppt");
    }
}
