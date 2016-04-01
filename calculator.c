#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
	int x,y,z;
};

double sq(double value)
{
	return pow(2, value);
}

double distance(double power)
{
	return power;
	//return pow(10, (0-18-power)/(20));
}

int main (int argc, char *argv[])
{
	struct point A, B, C;
	A.x = strtod(argv[1], (char **)NULL); A.y = strtod(argv[2], (char **)NULL); A.z = strtod(argv[3], (char **)NULL);
	B.x = strtod(argv[4], (char **)NULL); B.y = strtod(argv[5], (char **)NULL); B.z = strtod(argv[6], (char **)NULL);
	C.x = strtod(argv[7], (char **)NULL); C.y = strtod(argv[8], (char **)NULL); C.z = strtod(argv[9], (char **)NULL);
	double valA = distance(strtod(argv[10], (char **)NULL));
	double valB = distance(strtod(argv[11], (char **)NULL));
	double valC = distance(strtod(argv[12], (char **)NULL));

	if (B.x == A.x)
	{
		if(C.x != A.x && B.y != A.y)
		{
			struct point exchange = B;
			double valexchange = valB;
			B = C; valB = valC;
			C = exchange; valC = valexchange;
		}
		else
		{
			printf("allez vous faire tondre la pelouse par un tranosaure!!!\n");
			return 1;
		}
	}

	if (C.y == A.y)
	{
		if (B.y != A.y && C.x != A.x)
		{
			struct point exchange = B;
			double valexchange = valB;
			B = C; valB = valC;
			C = exchange; valC = valexchange;
		}
		else
		{
			printf("vous pouvez aller manger des papillons, je calculerai rien!!\n");
			return 1;
		}
	}

	double x, y, z;
	x = (sq(valA) - sq(valB) + sq(abs(B.x-A.x)))/(2*abs(B.x-A.x));
	y = (sq(valA) - sq(valC) + sq(abs(C.x-A.x)) + sq(abs(C.y-A.y)))/(2*abs(C.y-A.y)) - (abs(C.x-A.x)/abs(C.y-A.y))*x;
	z = sqrt(abs(sq(valA) - sq(x) - sq(y)));

	printf("%f %f %f\n", x, y, z);

	return 0;
}
