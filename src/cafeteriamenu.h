//食堂菜单类的头文件，用于声明食堂菜单的结构和显示函数。
#ifndef CAFETERIAMENU_H
#define CAFETERIAMENU_H

#include <QStringList>

class CafeteriaMenu
{
public:
    CafeteriaMenu();
    QStringList getMenu();
private:
    QStringList menu;
};

#endif // CAFETERIAMENU_H
