#include <stdio.h> 
#include <conio.h>
void main()
{
	int n, r, i, j, k;
	 n = 5;
	 r = 4;
	int alloc[5][4] = { { 0, 0, 1,2 }, // P0 // This is Allocation Matrix 
						{ 1, 0, 0,0 }, // P1 
						{ 1, 3, 5,4 }, // P2 
						{ 0, 6, 3,2 }, // P3 
						{ 0, 0, 1,4 } }; // P4 

	int max[5][4] = { { 0, 0, 1,2 }, // P0 // MAX Matrix 
					{ 1, 7, 5,0}, // P1 
					{ 2, 3, 5,6 }, // P2 
					{ 0, 6, 5,2 }, // P3 
					{ 0, 6, 5 ,6} }; // P4 

	int avail[4] = { 1, 5, 2,0 }; // These are Available Resources 

	int f[5], vong[5], ind = 0;
	for (k = 0; k < 5; k++)
	{
		f[k] = 0;
	}
	int need[5][4];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) 
	{
		for (i = 0; i < 5; i++) 
		{
			if (f[i] == 0) 
			{

				int flag = 0;
				for (j = 0; j < r; j++) {
					if (need[i][j] > avail[j]) 
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0) 
				{
					vong[ind++] = i;
					for (y = 0; y < r; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	printf("Vong an toan: \n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", vong[i]);
	printf(" P%d", vong[n - 1]);
	return;
	getch();
}