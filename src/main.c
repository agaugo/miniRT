#include "../inc/minirt.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Incorrect Number of Args Given\n");
    return (1);
  }
  is_rt(argv[1]);

}
