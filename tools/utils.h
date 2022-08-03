#ifndef UTILS_H
#define UTILS_H

#include <QObject>

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = nullptr);
    static Utils *getInstance(QObject *parent = nullptr);
private:
    static Utils* m_pInstance;
public:
    bool isDigital(QString number);

};

#endif // UTILS_H
