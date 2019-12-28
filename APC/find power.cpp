#include <stdio.h>
int findPower(int base, int power)
{
    if (power != 0)
        return (base*findPower(base, power-1));
    else
        return 1;
}
int main()
{
    int base, power, result;
    printf("Enter base number : ");
    scanf("%d",&base);
    printf("Enter power number : ");
    scanf("%d",&power);
    result = findPower(base, power);
    printf("%d^%d = %d", base, power, result);
    return 0;
}
