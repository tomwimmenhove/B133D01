#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	printf("pins:\n");
	for (int i = 0; i < 14; i++)
	{
		double theta = M_PI * 2.0f * (double) i / 14.0;

		double x = sin(theta) * 22.0f;
		double y = cos(theta) * 22.0f;

		printf("%d: %f %f\n", i + 1, x, -y);
	}

	printf("\nPin names:\n");
	for (int i = 0; i < 14; i++)
	{
		double theta = M_PI * 2.0f * (double) i / 14.0;

		double x = sin(theta) * 19.0f;
		double y = cos(theta) * 19.0f;

		printf("%d: %f %f -- %f deg\n", i + 1, x, -y, theta * 360.0f / M_PI / 2.0f);
	}



	printf("\npointy bit:\n");
	{
		double theta = M_PI * 2.0f / 28;

		double x = sin(theta) * 10.0f;
		double y = cos(theta) * 10.0f;

		printf("%f %f\n", x, -y);
	}

	/* Divider resistor positions / angles */
	printf("res:\n");
	{
		double x1 = 61.5f - 100.0f;
		double y1 = 100.0f - 73.0f;

		double xn = 90.9f - 100.0f;
		double yn = 100.0f - 146.8f;

		double t1 = atan2(y1, x1);
		printf("First at %f\n", t1 * 360.0f / 2.0 / M_PI);
		double tn = atan2(yn, xn) + 2.0f * M_PI;
		printf("Last at %f\n", tn * 360.0f / 2.0 / M_PI);

		double tStep = (tn - t1) / 9.0f;
		printf("tStep %f\n", tStep * 360.0f / 2.0 / M_PI);

		double d = sqrt(x1 * x1 + y1 * y1);
		printf("d: %f\n", d);

		double t = t1;

		for (int i = 0; i < 10; i++)
		{
			double x =          cos(t) * d + 100.0f;
			double y = 100.0f - sin(t) * d;
			printf("%f %f t = %f\n", x, y, t * 360.0f / 2.0 / M_PI);
			t += tStep;
		}

	}


	return 0;
}
