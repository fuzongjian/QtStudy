#include "domxml.h"
#include <QFile>
#include <QDomDocument>// 文件
#include <QDomProcessingInstruction>// 格式头部
#include <QDomElement>// 元素
#include <QDebug>
#include <QTextStream>// 文本流
#include <QDateTime>
#include <QDomNodeList>
#define count qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
DomXML::DomXML()
{

}

void DomXML::createXML(QString filePath){
    QFile file(filePath);//关联文件名字
    if(file.exists() == true){//如果存在就不创建
        count<<"文件已经存在";
        return;
    }else{
        // 只写方式打开文件
        bool isOk = file.open(QIODevice::WriteOnly);
        if(isOk == true){//如果打开成功
            // 创建XML文档对象
            QDomDocument doc;
            // 创建格式头
            QDomProcessingInstruction ins;
            ins = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'utf-8\'");
            // 追加节点
            doc.appendChild(ins);
            // 根节点元素
            QDomElement root = doc.createElement("日销售清单");
            doc.appendChild(root);
            // 保存
            QTextStream stream (&file);// 文本流关联文件
            doc.save(stream,4);// 4 代表缩进字符
            file.close();// 关闭文件
        }else{
            count<<"writeOnly error";
            return;
        }
    }

}
void DomXML::appendXML(QString filePath, QStringList list){
    QFile file(filePath);
    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk == true){//  打开成功
        // file和xml文档对象关联
        QDomDocument doc;
        isOk = doc.setContent(&file);
        if(isOk == true){// 如果关联成功，内容已经读取，可以关闭文件
            file.close();//关闭文件
            // 获取根节点元素
            QDomElement root = doc.documentElement();//默认获取根节点元素
            // 获取当前时间
            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yyyy-MM-dd");
            // 判断根节点下有没有子节点
            if(root.hasChildNodes() == true){// 如果有子节点
                // 查找最后一个子节点
                QDomElement lastEmt = root.lastChildElement();
                if(lastEmt.attribute("date") == dateStr){// 有没有当天日期
                    //写入有效数据
                    writeXML(doc,lastEmt,list);
                }else{// 如果没有
                    // 创建日期子节点元素
                    QDomElement dateEmt = doc.createElement("日期");
                    // 创建date属性
                    QDomAttr dateAttr = doc.createAttribute("date");
                    // 设置属性的值
                    dateAttr.setNodeValue(dateStr);
                    // 节点和属性关联
                    dateEmt.setAttributeNode(dateAttr);
                    // 把日期节点追加到根节点
                    root.appendChild(dateEmt);

                    //写入有效数据
                    writeXML(doc,dateEmt,list);
                }

            }else{// 没有子节点
                // 创建日期子节点元素
                QDomElement dateEmt = doc.createElement("日期");
                // 创建date属性
                QDomAttr dateAttr = doc.createAttribute("date");
                // 设置属性的值
                dateAttr.setNodeValue(dateStr);
                // 节点和属性关联
                dateEmt.setAttributeNode(dateAttr);
                // 把日期节点追加到根节点
                root.appendChild(dateEmt);

                //写入有效数据
                writeXML(doc,dateEmt,list);
            }

            // 保存文件
            isOk = file.open(QIODevice::WriteOnly);
            if(isOk == true){
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
            }

        }else{
            count<<"setContent error";
            return;
        }
    }else{
        count<<"readOnly error";
    }
}
void DomXML::writeXML(QDomDocument &doc, QDomElement &root, QStringList &list){
    // 当前时间
    QDateTime date = QDateTime::currentDateTime();
    QString timeStr = date.toString("hh-mm-ss");
    // 创建时间元素节点
    QDomElement timeEmt = doc.createElement("时间");
    // 创建属性
    QDomAttr timeAttr = doc.createAttribute("time");
    // 给属性设置值
    timeAttr.setNodeValue(timeStr);
    // 时间节点元素和属性关联
    timeEmt.setAttributeNode(timeAttr);
    // 把时间节点追加到日期节点后
    root.appendChild(timeEmt);



    QDomElement factory = doc.createElement("厂家");
    QDomElement brand = doc.createElement("品牌");
    QDomElement price = doc.createElement("报价");
    QDomElement num = doc.createElement("数量");
    QDomElement total = doc.createElement("金额");

    QDomText text = doc.createTextNode(list.at(0));
    factory.appendChild(text);
    text = doc.createTextNode(list.at(1));
    brand.appendChild(text);
    text = doc.createTextNode(list.at(2));
    price.appendChild(text);
    text = doc.createTextNode(list.at(3));
    num.appendChild(text);
    text = doc.createTextNode(list.at(4));
    total.appendChild(text);

    timeEmt.appendChild(factory);
    timeEmt.appendChild(brand);
    timeEmt.appendChild(price);
    timeEmt.appendChild(num);
    timeEmt.appendChild(total);
}

void DomXML::readXML(QString filePath, QStringList &fList, QStringList &bList, QStringList &pList, QStringList &nList, QStringList &tList){
    QFile file(filePath);
    bool isOk = file.open(QIODevice::ReadOnly);
    if(isOk == true){//  打开成功
        // file和xml文档对象关联
        QDomDocument doc;
        isOk = doc.setContent(&file);
        if(isOk == true){// 如果关联成功，内容已经读取，可以关闭文件
            file.close();
            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yyyy-MM-dd");
            // 获取根节点
            QDomElement root = doc.documentElement();

            if(root.hasChildNodes()){
                //找到最后一个节点
                QDomElement lastEmt = root.lastChildElement();
                if(lastEmt.attribute("date") == dateStr){// 判断有没有当天日期
                    // 找出当前日期下所有时间子节点
                    QDomNodeList list = lastEmt.childNodes();
                    for(int i = 0; i < list.size(); i ++){
                        // 转化成元素 找到时间节点下的所有子节点
                       QDomNodeList subList = list.at(i).toElement().childNodes();
                       // 厂家
                       QString factory = subList.at(0).toElement().text();
                       fList.append(factory);

                       QString brand = subList.at(1).toElement().text();
                       bList.append(brand);

                       QString price = subList.at(2).toElement().text();
                       pList.append(price);

                       QString num = subList.at(3).toElement().text();
                       nList.append(num);

                       QString total = subList.at(4).toElement().text();
                       tList.append(total);
                    }
                }else{
                    count<<"没有当天日期";
                    return;
                }
            }else{
                count<<"没有子节点";
                return;
            }

        }else{
            count<<"setContent error";
            return;
        }
    }else{
        count<<"ReadOnly error";
        return;
    }
}



