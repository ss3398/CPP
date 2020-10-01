#include "Hw3.h"

using namespace std;

int main()
{
  char buff[1024]; /* buffer for reading */
  FILE * inpipe = popen("gawk --version", "r");

  if(inpipe == NULL)
    {
      cout << "Error creating pipe stream ";
      return -1;
    }

  /* read from pipe till EOF */
  while(fgets(buff, 1024, inpipe))
    {
      cout << buff;
    }

  /* Close the pipe stream */
  pclose(inpipe);

  /* Open pipe stream again */
  inpipe = popen("gawk -f gawk.code numbers.txt", "r");

  if(inpipe == NULL)
    {
      cout << "Error creating pipe stream ";
      return -1;
    }

  if(fgets(buff, 1024, inpipe) == NULL)
    {
      cout << "Error receiving data on pipe ";
      pclose(inpipe);
      return -3;
    }

  /* Output data is present in buff, can close the pipe */
  pclose(inpipe);

  /* Parse the output */
  /* Init string stream with the data */
  istringstream istream(buff);

  /* Declare variables and extract from stream */
  int sum1, sum4;
  istream >> sum1 >> sum4;

  /* print separate numbers followed by sum */
  cout<<"The sum of Column 1 is:" << sum1 << "\n";
  cout<<"The sum of column 2 is:" << sum4 << "\n";

  sum1 = sum1 + sum4;
  cout<<"The Sum of the two numbers is:" << sum1 << "\n";

  return 0;
}
