#include<stdio.h>
#include<string.h>

#define SHIFT 3
#define MASK 0x7


void set_bit();
void clear_bit();
void asign_bit();
int test_bit();

int main()
{
	char *array;

	return 0;
}

void set_bit(char bit_array[], unsigned bit_number)
{
	bit_array[bit_number >> SHIFT] &= (1 << ~(bit_number & MASK));
}

void clear_bit(char bit_array[], unsigned bit_number);
{
	bit_array[num >> SHIFT] &= ~(1 << (num & MASK));
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	bit_array= (char *)malloc(value/8 +1);
	memset(bit_array, 0, (value/8 +1));
	bit_array[num >> SHIFT] &= ~(1 <<(num & MASK));
}


int test_bit(char bit_array[], unsigned bit_number)
{

}
