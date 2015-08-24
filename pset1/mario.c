#include <stdio.h>

int ReadHeight()
{
  int retry_counter = 5;
  int height;
  char buffer[5];
  do
  {
    printf("\nEnter height:");
    sscanf(buffer,"%d",&height);
    if (height < 0 || height > 23)
    {
      retry_counter--;
      printf("\nFailed, try again\n");
      printf("Number of retries left: %d \n", retry_counter);
    }
  } while ((height < 0 || height > 23) && retry_counter > 0);
  if (height > 0 && height < 24)
  {
    return height;
  }
  else 
  {
    return 0;
  }
}

int main(void)
{
  int i, height, empty_space;
  int hash_counter = 2;
  int height_counter;
  height = ReadHeight();
  empty_space = height - 1;
  hash_counter = 2;
  height_counter = 0;
  while (height_counter < height)
  {
    for(i=0;i<empty_space;i++)
    {
      printf(" ");
    }
    for(i=0;i<hash_counter;i++)
    {
      printf("#");
    }
    printf("\n");
    empty_space = empty_space - 1;
    hash_counter++;
    height_counter++;
  }

}
