#include <QCoreApplication>
#include<QFile>
#include<qDebug>
#include<QRegExp>
#include<algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<int,int>Vendor_ProductID_from_device;
    Vendor_ProductID_from_device.insert(11, 626);
    Vendor_ProductID_from_device.insert(778 , 561);
    Vendor_ProductID_from_device.insert(123, 8859);
//////////////////////////////////////////////////////////////////////
    QMap<int,int> Vendor_ProductID_from_File;

    QFile file("C:/Programming/Qt projects/FileTest/VendorID_ProductID.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Errow with read file";
    }
    QByteArray text=file.readAll();
    file.write(text);

    QString str(text);
    QString temp_str;
    qDebug()<<str;

    //QString Abcd = "123";
   // Abcd.split(" ")[0].toInt();    //convert the first part to Int
  //  Abcd.split(" ")[0].toDouble(); //convert the first part to double
    //Abcd.split(" ")[0].toFloat();

    QRegExp regexp("[0-9]");
        QString key, value;
        for (int i = 0; i < str.size(); i++)
        {
            temp_str = str[i];
            key = "";
            value = "";
            if (temp_str.contains(regexp) > 0)
            {
                while (true)
                {
                    temp_str = str[i];
                    if(temp_str.contains(regexp) <= 0||i == str.size())
                        break;
                    key += str[i];
                    i++;
                }

                while(true)
                {
                    temp_str= str[i];
                    if(temp_str.contains(regexp) > 0||i == str.size())
                    {
                        break;
                    }
                    i++;
                }
                while (true)
                {
                    temp_str = str[i];
                    if(temp_str.contains(regexp) <= 0||i == str.size())
                        break;
                    value += str[i];
                    i++;
                }
            }
            if(key.size()&&value.size())
            {
                Vendor_ProductID_from_File.insert(key.toInt(), value.toInt());
            }
        }

    file.close();
    qDebug()<<"------------------------------------\n";
    for(auto it=Vendor_ProductID_from_File.begin();it!=Vendor_ProductID_from_File.end();++it)
    {
        qDebug()<<it.key()<<"-"<<it.value();
    }

    for (auto it_device = Vendor_ProductID_from_device.begin(); it_device != Vendor_ProductID_from_device.end(); ++it_device)
        {
            for (auto it_File = Vendor_ProductID_from_File.begin(); it_File != Vendor_ProductID_from_File.end(); ++it_File)
            {
                if (it_File.key() == it_device.key() && it_File.value() == it_device.value())
                {
                    qDebug()<<"))))))))))))))";
                }
            }
    }



    return a.exec();
}
