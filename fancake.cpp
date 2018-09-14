#include<stdio.h>
#include<string.h>

char fan[1000];
int fs;
int flipper;

void flip(int s)
{
	int x;

	for (x = 0; x < flipper; x++)
	{
		if (fan[s+x] == '+')
			fan[s+x] = '-';
		else
			fan[s+x] = '+';
	}
}

int main(void)
{
	int cnt;
	int n;
	int sol = 0;
	
	scanf("%d", &cnt);

	for (n = 0; n < cnt; n++)
	{
		int i;
		sol = 0;
		scanf("%s %d", fan, &flipper);
		fs = strlen(fan);

		for (i = 0; i < fs - flipper+1; i++)
		{
			if (fan[i] == '-') {
				flip(i);
				sol++;
			}
		}

		for (i = 0; i < fs; i++)
		{
			if (fan[i] == '-')
			{
				sol = -1;
				i = fs;
			}
		}
		
		if (sol == -1)
			printf("Case #%d: IMPOSSIBLE\n", n+1);
		else 
			printf("Case #%d: %d\n", n+1, sol);


	}

	
}
