// mealplanner.h
#ifndef MEALPLANNER_H
#define MEALPLANNER_H

#include "interfaces.h"
#include "canteen.h"

QStringList generateRecommendedMeals(const UserProfile &user, const QVector<Dish> &dishes);

#endif // MEALPLANNER_H
