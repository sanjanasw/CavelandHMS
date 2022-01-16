#ifndef LOGIN_H
#define LOGIN_H

#include "dbconnection.h"

#include <QString>

class Login
{
public:
    Login();
    static QString* UserLogin(QString UserName, QString Password);
};

#endif // LOGIN_H
