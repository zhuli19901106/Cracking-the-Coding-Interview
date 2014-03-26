// 17.1 Do a swapping in-place.
#include <cstdio>
using namespace std;

void swap1(int &x, int &y)
{
	// what if it is double?
	x ^= y ^= x ^= y;
}

void swap2(int &x, int &y)
{
	// overflow?
	x = x + y;
	y = x - y;
	x = x - y;
}

int main()
{
	int x, y;
	
	scanf("%d%d", &x, &y);
	printf("x = %d, y = %d\n", x, y);
	swap1(x, y);
	printf("x = %d, y = %d\n", x, y);
	swap2(x, y);
	printf("x = %d, y = %d\n", x, y);
	
	return 0;
}