#include "../../inc/minirt.h"

double ft_atof(const char *str)
{
  double result;
  double sign;
  double divisor;

  result = 0.0;
  sign = 1.0;
  divisor = 10.0;

  if (*str == '-')
  {
    sign = -1.0;
    str++;
  }
  
  else if (*str == '+')
    str++;
  
  while (*str >= '0' && *str <= '9')
  {
    result = result * 10.0 + (*str - '0');
    str++;
  }

  if (*str == '.')
  {
    str++;
    while (*str >= '0' && *str <= '9')
    {
      result += (*str - '0') / divisor;
      divisor *= 10.0;
      str++;
    }
  }
  return (sign * result);
}
