#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include <QDataStream>
#include <QFile>
class FileManager
{
public:
    FileManager();
    QFile* file;
    void openFile(QString type, QString direccion);
    void writeOnFile(QByteArray arr);
     QByteArray readOnFile();
};

#endif // FILEMANAGER_H
