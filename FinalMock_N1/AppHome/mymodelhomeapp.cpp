#include "mymodelhomeapp.h"
#include <QDir>
#include <QDebug>
#include <QRegularExpression>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>

MyModelHomeApp::MyModelHomeApp(QObject* parent)
    : QAbstractListModel(parent)
{
    setCurrentPage(1);
    loadApp();
}

MyModelHomeApp::~MyModelHomeApp()
{
    qDeleteAll(m_listAppPage1);
    qDeleteAll(m_listAppPage2);
}

void MyModelHomeApp::loadApp()
{
    QDir dir(QDir::currentPath());
    if(dir.cd("IconApp")){
        QStringList filters;
        filters << "*.png";
        dir.setNameFilters(filters);
        QFileInfoList fileInfors = dir.entryInfoList(QDir::Files);

        QRegularExpression regex(R"((\d+)_(\w+)\.png)");
        foreach(const QFileInfo& fileInfor, fileInfors){
            QString fileName = fileInfor.fileName();
            QRegularExpressionMatch match = regex.match(fileName);

            if(match.hasMatch()){
                int id = match.captured(1).toInt();
                QString nameApp, imageApp;
                QStringList currenInforApp;

                switch (id) {
                case 0:
                    nameApp = QObject::tr("Music");
                    currenInforApp.append("");
                    currenInforApp.append("");
                    break;
                case 1:
                    nameApp = QObject::tr("Video");
                    currenInforApp.append("");
                    currenInforApp.append("");
                    break;
                case 2:
                    nameApp = QObject::tr("Setting");
                    currenInforApp.append("");
                    currenInforApp.append("");
                    break;
                default:
                    break;
                }

                if(id < 2){
                    setCurrentPage(1);
                }
                else{
                    setCurrentPage(2);
                }

                imageApp = fileInfor.absoluteFilePath();

                MyHomeApp* app = new MyHomeApp(id, nameApp, imageApp, currenInforApp);
                addApp(app);
            }
        }
    }
    else {
        qDebug() << "Failed to change directory to 'IconApp'";
    }
}

void MyModelHomeApp::addApp(MyHomeApp *app)
{
    if(app){
        if(m_currentPage == 1){
            beginInsertRows(QModelIndex(), m_listAppPage1.size(), m_listAppPage1.size());
            m_listAppPage1.append(app);
            endInsertRows();
        }
        else if(m_currentPage == 2){
            beginInsertRows(QModelIndex(), m_listAppPage2.size(), m_listAppPage2.size());
            m_listAppPage2.append(app);
            endInsertRows();
        }
    }
}

int MyModelHomeApp::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if(parent.isValid())
        return 0;
    if(m_currentPage == 1){
        return m_listAppPage1.size();
    }
    else if(m_currentPage == 2){
        return m_listAppPage2.size();
    }
    return 0;
}

QVariant MyModelHomeApp::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const QList<MyHomeApp*>* list = (m_currentPage == 1) ? &m_listAppPage1 : &m_listAppPage2;

    if (index.row() >= list->size())
        return QVariant();

    MyHomeApp* app = list->at(index.row());
    switch (role) {
    case IDRole:
        return app->Id();
    case NameAppRole:
        return app->nameApp();
    case ImagePathRole:
        return app->imagePath();
    case CurrentInfor:
        return app->currentInfor();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> MyModelHomeApp::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IDRole] = "theIDApp";
    roles[NameAppRole] = "theNameApp";
    roles[ImagePathRole] = "theImagePathApp";
    roles[CurrentInfor] = "theCurrentInfor";

    return roles;
}

QList<MyHomeApp *> MyModelHomeApp::listAppPage1() const
{
    return m_listAppPage1;
}

QList<MyHomeApp *> MyModelHomeApp::listAppPage2() const
{
    return m_listAppPage2;
}

int MyModelHomeApp::currentPage() const
{
    return m_currentPage;
}

void MyModelHomeApp::setCurrentPage(int newCurrentPage)
{
    if(newCurrentPage != m_currentPage){
        beginResetModel();
        m_currentPage = newCurrentPage;
        qDebug() << m_currentPage;
        endResetModel();
        emit currentPageChanged();
    }
}

void MyModelHomeApp::changeInforVideo(const QString& inforVideo)
{
    for(MyHomeApp* app : m_listAppPage1){
        if(app->Id() == 1){
            app->setCurrentInfor({inforVideo, ""});
        }
    }
}

void MyModelHomeApp::changeInforMusic(const QString &inforMusic)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(inforMusic.toUtf8());
    QString msgID = jsonDoc.object().value("msg").toString();
    QJsonObject jsonObj = jsonDoc.object().value("data").toObject();
    if(msgID == "MusicInfo"){
        QString titleName = jsonObj.value("Title").toString();

        QString artistName = jsonObj.value("Artist").toString();
        QString status = jsonObj.value("Status").toString();
        QString coverArt = jsonObj.value("CoverArt").toString();

        for(MyHomeApp* app : m_listAppPage1){
            if(app->Id() == 0){
                app->setCurrentInfor({titleName, artistName});
                qDebug() << "title" << titleName;
                app->setImagePath(coverArt);
            }
        }
    }
}
