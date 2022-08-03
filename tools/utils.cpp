#include "utils.h"

Utils* Utils::m_pInstance = nullptr;
Utils::Utils(QObject *parent) : QObject(parent)
{

}

Utils *Utils::getInstance(QObject *parent)
{
    if(!m_pInstance){
        m_pInstance = new Utils(parent);
    }
    return m_pInstance;
}

bool Utils::isDigital(QString number)
{
    return number.contains(QRegExp("^\\d+$"));

}
