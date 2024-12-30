#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct Equation
{
  int a;
  int n;
}SE;

void getting_input(int equation_number);
int gcd(int a, int b);
bool are_relativly_prime(SE equations[], int equation_number);
SE crt_evolved(SE* E1, SE* E2);
int crt_complete(SE equations[] ,int equation_number);
//create a struct a1 n1, thats it
int main(void)
{
  printf("This program solves a1 mod n1 ... an mod n\n");
  bool flag =true;
  while(flag)
  {
    char equation_number=0;
    do
    { 
      printf("Equation number should be greater or equal to 2\n");
      printf("'n's has to be relativly prime!\n");
      printf("Enter the number of equations: ");
      scanf("%d",&equation_number);
    }while(equation_number < 2);
    SE equations[equation_number];
    for(int i=0;i<equation_number;i++)
    {
      printf("Enter the a%d: ",i+1);
      scanf("%d",&equations[i].a);
      printf("Enter the n%d: ",i+1);
      scanf("%d",&equations[i].n);
      equations[i].a = equations[i].a % equations[i].n;
    }  
    if(are_relativly_prime(equations, equation_number))
    {
      printf("X = %d\n" , crt_complete(equations, equation_number));
      flag = false;
    }
    else
    {
      printf("The numbers are not relativly prime!!!\n");
    }
  }
  return 0;
}

int gcd(int a,int b)
{
  if(b==0)
  {
    return a;
  }
  return gcd(b, a %b);
}

bool are_relativly_prime(SE equations[], int equation_number)
{
  for(int i=0; i< equation_number; i++)
  {
    for(int j=i+1; j< equation_number; j++)
    {
      if(gcd(equations[i].n,equations[j].n)>1)
      {
        return 0;
      }
    }
  }
  return 1;
}

int crt_complete(SE equations[] ,int equation_number)
{
  for(int i=1; equation_number > i; i++)
  {
    equations[0] = crt_evolved(&equations[0], &equations[i]);
  }
  return equations[0].a;
}

// Convert to struct. It will be better.
SE crt_evolved(SE* E1, SE* E2)
{
  int temp =0;
  if(E1->n < E2->n)
  {
    SE* temp = E1;
    E1 = E2;
    E2 = temp; 
  }

  int x =0;
  int i =0;
  while(true)
  {
    x = E1->n * i + E1->a;
    if(x % E2->n == E2->a)
    {
      E1->a = x;
      E1->n = E1->n * E2->n;
      return *E1; 
    }
    i++;
  } 
}

