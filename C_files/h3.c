#include <stdio.h>
int main () {
/* variable definition: */
int count;
float sum, cost;
/* Initialize */
count = 0; 
sum = 0; 
cost = 0;
printf("This program adds the cost of hotel rooms used during vacation in a year.\n");
while (cost >= 0) {
	printf("Enter cost of hotel rooms (enter a negative value to stop).\n");
	scanf("%f", &cost);
	if (cost >= 0) {
		sum = sum + cost;
		count = count + 1;
	}
}
printf("Total cost is %.2f\n",sum); 
return 0;
} // end main
