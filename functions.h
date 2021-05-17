#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <list>
#include <cstdio>
#include "class_point.h"

bool right_turn(std::list<Point>& L);
int partition_x (Point * points, int low, int high);
void quick_Sort_by_x(Point * points, int low, int high);
int partition_y (Point * points, int low, int high);
void quick_Sort_by_y(Point * points, int low, int high);
void getData(Point * points, int n, FILE*f, double coeff);

#endif 
