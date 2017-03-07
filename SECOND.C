#include <stdio.h>
#include <math.h>

typedef struct{
	int iX, iY;
}POINT;

typedef struct{
	double dRadius;
	POINT center;
}CIRCLE;

void fnReadPoint(POINT*);
void fnReadCircle(CIRCLE*);
void fnCheckPoint(CIRCLE, POINT);
void fnCheckCircle(CIRCLE, CIRCLE);

int main(void)
{
	CIRCLE c1,c2;
	POINT p1;

	printf("\nEnter Circle Details\n");
	fnReadCircle(&c1);
	
	printf("\nEnter Coordinates of the point\n");
	fnReadPoint(&p1);
	
	fnCheckPoint(c1,p1);
	
	printf("\nEnter Circle1 Details\n");
	fnReadCircle(&c1);

	printf("\nEnter Circle2 Details\n");
	fnReadCircle(&c2);

	fnCheckCircle(c1,c2);
	
	return 0;	
}

void fnReadPoint(POINT *p)
{
	printf("\nX-coordinate : ");
	scanf("%d", &p->iX);
	printf("\nY-coordinate : ");
	scanf("%d", &p->iY);
}
void fnReadCircle(CIRCLE *c)
{
	printf("\nRadius : ");
	scanf("%lf", &c->dRadius);
	printf("\nEnter coordinates of the center\n");
	fnReadPoint(&c->center);
}

void fnCheckPoint(CIRCLE c, POINT p)
{
	if(pow((p.iX-c.center.iX),2) + pow((p.iY-c.center.iY),2) == pow(c.dRadius,2))
	{
		printf("\nGiven Point is on the circle\n");
	}
	else if(pow((p.iX-c.center.iX),2) + pow((p.iY-c.center.iY),2) < pow(c.dRadius,2))
	{
		printf("\nGiven Point is inside the circle\n");
	}
	else
	{
		printf("\nGiven Point is outside the circle\n");
	}	
}

void fnCheckCircle(CIRCLE c1, CIRCLE c2)
{
	double dDist;
	
	dDist = sqrt(pow((c1.center.iX - c2.center.iX),2) + pow((c1.center.iY - c2.center.iY),2));
	
	if(dDist == c1.dRadius + c2.dRadius)
		printf("\nTwo Circles touch one another\n");
	else if(dDist < c1.dRadius + c2.dRadius)
		printf("\nTwo Circles intersect\n");
	else
		printf("\nTwo Circles are disjoint\n");

}
