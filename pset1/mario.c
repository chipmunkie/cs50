#include <stdio.h>

int main(void)
{
  int i, height, empty_space, hash_counter, height_counter;
  printf("Enter height:");
  scanf("%d",&height);
  empty_space = height;
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
