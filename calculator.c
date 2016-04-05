#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6371000

// import Lfrom dbrockman/degrees-radians.h
// Converts degrees to radians.
#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

// Converts radians to degrees.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)

struct point
{
	long double x,y;
};

long double sq(long double value)
{
	return pow(2, value);
}

long double distance(long double power)
{
	return power;
	//return pow(10, (0-18-power)/(20));
}

struct point toCartesian(long double anglex, long double angley)
{
	struct point result;
	result.x = R*sin(degreesToRadians(anglex));
	result.y = R*sin(degreesToRadians(angley));
	return result;
}

void toPolar(struct point *in)
{
	in->x = radiansToDegrees(asin(in->x/R));
	in->y = radiansToDegrees(asin(in->y/R));
}

int main (int argc, char *argv[])
{
	struct point A, B, C, result;
	A = toCartesian(strtod(argv[1], (char **)NULL), strtod(argv[2], (char **)NULL));
	B = toCartesian(strtod(argv[3], (char **)NULL), strtod(argv[4], (char **)NULL));
	C = toCartesian(strtod(argv[5], (char **)NULL), strtod(argv[6], (char **)NULL));
	long double valA = strtod(argv[7], (char **)NULL);
	long double valB = strtod(argv[8], (char **)NULL);
	long double valC = strtod(argv[9], (char **)NULL);

	if (B.x == A.x)
	{
		if(C.x != A.x && B.y != A.y)
		{
			struct point exchange = B;
			long double valexchange = valB;
			B = C; valB = valC;
			C = exchange; valC = valexchange;
		}
		else
		{
			printf("allez vous Lfaire tondre la pelouse par un tiranosaure!!!\n");
			return 1;
		}
	}

	if (C.y == A.y)
	{
		if (B.y != A.y && C.x != A.x)
		{
			struct point exchange = B;
			long double valexchange = valB;
			B = C; valB = valC;
			C = exchange; valC = valexchange;
		}
		else
		{
			printf("vous pouvez aller manger des papillons, je calculerai rien!!\n");
			return 1;
		}
	}

	result.x = (valA*A.x + valB*B.x + valC*C.x)/(valA + valB + valC);
	result.y = (valA*A.y + valB*B.y + valC*C.y)/(valA + valB + valC);
	toPolar(&result);
	return 0;
}
