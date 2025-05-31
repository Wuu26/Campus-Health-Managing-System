//食堂菜单类的实现文件，用于实现具体的食堂菜单结构和显示逻辑。
#include "cafeteriamenu.h"

CafeteriaMenu::CafeteriaMenu()
{
    menu << "红烧肉" << "炒青菜" << "西红柿炒蛋" << "鱼香肉丝";
}

QStringList CafeteriaMenu::getMenu()
{
    return menu;
}
