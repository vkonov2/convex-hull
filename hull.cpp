#include<iostream>
#include "class_point.h"
#include "functions.h"
using namespace std;



int main(int argc, char* argv[]){
	
	int n, i;

	double eps = 1.0;

    while( 1.0 + eps > 1.0 )
    {
        eps = eps / 2.0;
    }
	
	FILE * f = fopen("points.txt", "w");

	if (f == NULL) 
    {
       printf ("Can't open file\n");
       exit(1);
    }

    if( !( sscanf(argv[1], "%d", &n) == 1 && n >= 0 ) )
	{
		printf("Bad n was entered\n");
		return 1; 
	}

	Point * points = new Point[n];

    if( argc == 2 )	for( i = 0; i < n; i++ ) points[i].keyboard_put();

    if(argc == 3)
    {
    	double coeff;

    	if( !( sscanf(argv[2], "%lf", &coeff) == 1 ) )
		{
			printf("Bad coefficient was entered\n");
			return 1; 
		}

    	getData(points, n, f, coeff);
		
		fclose(f);
    }
	
    quick_Sort_by_x(points, 0, n-1);	
    /*std::cout<<"After X_sort "<<endl;
    for (int i = 0; i < n; ++i) 
	{
    	points[i].print();
    }
    std::cout<<endl;*/
    
    int count = 0;

    for (i = 1; i < n; ++i) 
	{
		if(count == n-1 ) quick_Sort_by_y(points, 0, n-1);

    	if( (points[i-1].x - points[i].x) <= eps ) 
    	{
    		count++;

    		if(i == n - 1) quick_Sort_by_y(points, i-count, i);
		}
    	else
    	{
    		quick_Sort_by_y(points, i-1-count, i-1);

    		count = 0;
		}
    }
    
    /*std::cout<<"After Y_sort "<<endl;

    for (i = 0; i < n; ++i) 
	{
    	points[i].print();
    }
    std::cout<<endl; */
       
    list < Point > L_upper;
    L_upper.push_front(points[0]);
    L_upper.push_back(points[1]);
    list <Point> :: iterator t = L_upper.end();

    for(i = 2; i < n; i++)
    {
    	L_upper.push_back(points[i]);

    	while ( L_upper.size() > 2 && right_turn(L_upper) != 1 )
    	{
    		t = L_upper.end();
    		advance(t, -2);
    		L_upper.erase(t);
		}
		
	}
	
	list < Point > L_lower;

    L_lower.push_front(points[n-1]);
    L_lower.push_back(points[n-2]);
    t = L_lower.end();

    for(i = n-3; i >= 0; i--)
    {
    	L_lower.push_back(points[i]);

    	while ( L_lower.size() > 2 && right_turn(L_lower) != 1 )
    	{
    		t = L_lower.end();
    		advance(t, -2);
    		L_lower.erase(t);
		}
		
	}
	if( L_lower.size() != 0)
	{
		t = L_lower.begin();
        L_lower.erase(t);	
	}
	if( L_lower.size() != 0)
	{
		t = L_lower.end();
		advance(t, -1);
        L_lower.erase(t);
	}
	
	f = fopen("hull.txt", "w");

	if (f == NULL) 
    {
       printf ("Can't open file\n");
       exit(1);
    }
	
	std::cout<<"Final list:"<<endl;
	for (t = L_upper.begin(); t != L_upper.end(); t++)
	{
		fprintf( f, "%1.2lf %1.2lf ", (*t).x, (*t).y );

		(*t).print();
	} 

	if( L_lower.size() == 0) return 0;

    for (t = L_lower.begin(); t != L_lower.end(); ++t) 
    {
    	L_upper.push_back(points[1]);

    	fprintf( f, "%1.2lf %1.2lf ", (*t).x, (*t).y );

    	(*t).print();
	}

    L_lower.clear();

    delete [] points;

    fclose(f);
    
   
    return 0;
}
