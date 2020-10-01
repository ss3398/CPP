#include <stdio.h>
int main () {
/* variable definition: */
int count;
double avg, value, weight, sum, sumw;
/* Initialize */
count = 0; 
sum = 0; 
sumw = 0; 
avg = 0.0;
// Loop through to input values
   while (count < 10) {
	printf("Enter a value and its weight: "); // use %lf for double, %f for float 
	scanf("%lf %lf", &value, &weight);
	if (weight >= 0) {
		sumw = sumw + weight;
		sum = sum + value * weight; 
		count = count + 1;
	}
	else {
         	printf("Weight must be positive\n");
      	} // end if weight ok
   } // end reading input values and weights
// Calculate avg if sumw is not 0
avg = sum / sumw;
printf("average is %lf\n " , avg ); 
return 0;
} // end main
