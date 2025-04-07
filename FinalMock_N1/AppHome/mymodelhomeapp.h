#ifndef MYMODELHOMEAPP_H
#define MYMODELHOMEAPP_H

#include <QAbstractListModel>
#include <QObject>
#include "myhomeapp.h"

class MyModelHomeApp : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int currentPage READ currentPage WRITE setCurrentPage NOTIFY currentPageChanged FINAL)

public:

    enum AppRole{
        IDRole = Qt::UserRole + 1,
        NameAppRole,
        ImagePathRole,
        CurrentInfor
    };

    MyModelHomeApp(QObject* parent = nullptr);
    ~MyModelHomeApp();

    void loadApp();

    void addApp(MyHomeApp* app);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    int currentPage() const;
    void setCurrentPage(int newCurrentPage);

    void changeInforVideo(const QString& inforVideo);
    void changeInforMusic(const QString& inforMusic);


    QList<MyHomeApp *> listAppPage1() const;
    QList<MyHomeApp *> listAppPage2() const;

signals:
    void currentPageChanged();

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<MyHomeApp* > m_listAppPage1;
    QList<MyHomeApp* > m_listAppPage2;
    int m_currentPage;
};

#endif // MYMODELHOMEAPP_H
