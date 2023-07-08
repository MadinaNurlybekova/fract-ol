#include "../includes/ft_fractol.h"

//  colors
int foo(int continuous_index)
{
    union colour_u     c;

    c.channels[0] = (unsigned char)(sin(0.016 * continuous_index + 4) * 250);
    c.channels[1] = (unsigned char)(sin(0.013 * continuous_index + 2) * 250);
    c.channels[2] = (unsigned char)(sin(0.01 * continuous_index + 1) * 250);
    c.channels[3] = 255; //alpha bit

    return c.number;
}