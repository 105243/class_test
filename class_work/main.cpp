#include <QCoreApplication>
#include<iostream>
#include <QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>

using namespace std;

QString line;
QStringList spl;
QString qs;
QString message;
QFile file("table.txt");
string student_code[10];
string date[5];
string mark[5][9];




void read_text() {
    int a = 0;
    int j = 0;

    while (!file.atEnd()){
        line = file.readLine();
        spl = line.split(QRegExp("\\s+"), QString::SkipEmptyParts); //разделяет строку отбрасыввая все пробелы, сохраняет слова раздельно друг от друга
        if (a == 0){
            student_code[0] = spl.at(0).toUtf8().constData();
            for(int i=0; i<5; i++){
                date[i] = spl.at(i+1).toUtf8().constData();

            }

        }else{
            student_code[a] = spl.at(0).toUtf8().constData();
            for(int i =0; i < 5; i++){
                mark[i][j] = spl.at(i+1).toUtf8().constData();
            }
            j++;

        }
            a++;

    }
}
void print(){
    for(int i=0; i<10; i++){
        cout << student_code[i]<<"  ";
    }
    for(int i=0; i < 5; i++){
        cout << endl << "   " << date[i];
        for(int j=0; j < 9; j++){
            cout << "\t" << mark[i][j] <<"  ";
        }
    }
}

int main() {



    if (!file.exists()){
        message = "Can't find file %1 to read\n";
        message = message.arg(qs);
        qDebug() << message;
        return -1;
    }

    if(!file.open(QFile::ReadOnly | QFile::Text))  {
        message = "Can't open the file %1 for reading\n";
        message = message.arg(qs);
        qDebug() << message;
        return -1;
    }
    read_text();
    print();


}

