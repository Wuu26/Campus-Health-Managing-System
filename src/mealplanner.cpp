// mealplanner.cpp
#include "mealplanner.h"
#include <QRandomGenerator>
#include <algorithm>

QStringList generateRecommendedMeals(const UserProfile &user, const QVector<Dish> &dishes) {
    QStringList result;
    QVector<Dish> filtered;

    // 简单筛选，未来可加入营养信息或忌口过滤
    for (const Dish &dish : dishes) {
        if (user.dietType == "素食") {
            if (dish.name.contains("肉") || dish.name.contains("鸡") || dish.name.contains("鱼"))
                continue;
        }
        filtered.append(dish);
    }

    // 随机推荐 2 个菜品
    std::shuffle(filtered.begin(), filtered.end(), QRandomGenerator::global()->generate());

    for (int i = 0; i < std::min(2, filtered.size()); ++i) {
        result << filtered[i].canteen + "：" + filtered[i].name;
    }

    return result;
}
