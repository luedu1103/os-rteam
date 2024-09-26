/* 1 in 17.14 format. */
#define F (1 << 14)  

/* n denotes integer, x and y denote FP. */
int int_to_fixed (int n); /* Convert integer n to fixed point. */
int fixed_to_int (int x); /* Convert FP to int(round down) */
int fixed_to_int_round (int x); /* Convert FP x to int(round). */
int add_fixed (int x, int y); /* FP + FP */
int sub_fixed (int x, int y); /* FP - FP */
int add_fixed_int (int x, int n); /* FP + int */
int sub_fixed_int (int x, int n); /* FP - int */
int mult_fixed (int x, int y); /* FP * FP */
int mult_fixed_int (int x, int n); /* FP * int */
int div_fixed (int x, int y); /* FP / FP */
int div_fixed_int (int x, int n); /* FP / int */

int 
int_to_fixed (int n)
{
  return n * F;
}

int
fixed_to_int (int x)
{
  return x / F;
}

int 
fixed_to_int_round (int x)
{
  return x >= 0 ? (x + F / 2) / F : (x - F / 2) / F;
}

int 
add_fixed (int x, int y) 
{
  return x + y;
}

int 
sub_fixed (int x, int y)
{
  return x - y;
}

int
add_fixed_int (int x, int n)
{
  return x + int_to_fixed (n);
}

int
sub_fixed_int (int x, int n)
{
  return x - int_to_fixed (n);
}

int
mult_fixed (int x, int y)
{
  return ((int64_t)x) * y / F;
}

int
mult_fixed_int (int x, int n)
{
  return x * n;
}

int
div_fixed (int x, int y)
{
  return ((int64_t)x) * F / y;
}

int
div_fixed_int (int x, int n)
{
  return x / n;
}