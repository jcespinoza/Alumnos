#include "filemanager.h"

FileManager::FileManager()
{
}
//Abre el archivo, se manda la direccion del archivo a abrir y el tipo si es de lectura o escritura
void FileManager::openFile(QString type, QString direccion){
    file =new QFile(direccion);
    if(type== "Read"){
       file->open(QIODevice::ReadOnly);
    }else{
        file->open(QIODevice::WriteOnly);
    }
}

void FileManager::writeOnFile(QByteArray arr){

    this->openFile("Write","Alumno.dat");

    file->write(arr);
    file->flush();
}


QByteArray FileManager::readOnFile(){
    this->openFile("Read","Alumno.dat");
    return file->readAll();
}

