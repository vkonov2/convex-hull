#include "functions.h"
#include "class_point.h"
#include <iostream> 
#include <math.h>
#include <list>


using namespace std;


void getData(Point * points, int n, FILE*f, double coeff)
{
  for (int i = 0; i<n; i++) 
  {
    points[i].x = (double)i;
    points[i].y = 8*(double)i - 3 + ((rand()%100)-50)*coeff;
    
    fprintf( f, "%1.2lf %1.2lf ", points[i].x, points[i].y );
  }
}

bool right_turn(std::list<Point>& L)
{
    double eps = 1.0;

    while( 1.0 + eps > 1.0 )
    {
        eps = eps / 2.0;
    }

	Point * p = new Point[3];  // points_for_determinant                                            
	list <Point> :: iterator t = L.end();
	advance(t, -1);
	p[2] = *t;
	advance(t, -2);
	p[0] = *t;
	advance(t, 1);
	p[1] = (*t);
	double det = p[1].x * p[2].y - p[1].y * p[2].x - p[0].x * p[2].y + p[0].y * p[2].x + p[0].x * p[1].y - p[0].y * p[1].x;
	delete [] p;
	if(   (det / fabs(det) + 1) <= eps  ) return 1;
	else return 0;
}


int partition_x (Point * points, int low, int high)
{
    Point * points_reserve = new Point[2];
    points_reserve[0] = points[high];
 
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        if (points[j].x < points_reserve[0].x)
        {
            i++;   
            points_reserve[1] = points[i];
            points[i] = points[j];
            points[j] = points_reserve[1];
        }
    }
    points_reserve[1] = points[i + 1];
    points[i + 1] = points[high];
    points[high] = points_reserve[1];
    delete [] points_reserve;
    return (i + 1);
}


void quick_Sort_by_x(Point * points, int low, int high)
{
    if (low < high)
    {
        int pi = partition_x(points, low, high);

        quick_Sort_by_x(points, low, pi - 1);  
        quick_Sort_by_x(points, pi + 1, high); 
    }
} 


int partition_y (Point * points, int low, int high)
{
    Point * points_reserve = new Point[2];
    points_reserve[0] = points[high];
 
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        if (points[j].y < points_reserve[0].y)
        {
            i++;   
            points_reserve[1] = points[i];
            points[i] = points[j];
            points[j] = points_reserve[1];
        }
    }
    points_reserve[1] = points[i + 1];
    points[i + 1] = points[high];
    points[high] = points_reserve[1];
    delete [] points_reserve;
    return (i + 1);
}


void quick_Sort_by_y(Point * points, int low, int high)
{
    if (low < high)
    {
        int pi = partition_y(points, low, high);

        quick_Sort_by_y(points, low, pi - 1);  
        quick_Sort_by_y(points, pi + 1, high); 
    }
}



