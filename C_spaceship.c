#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_spaceship(char *space)
{
    int X_axis = 0;
    int Y_axis = 0;
    int cord = 0;
    int shipLength = strlen(space); // this will check the length of the parameter
    char *direction = "up";         // for str OR char direction = 'up' for character

    char *mem = (char *)malloc(sizeof(char) * 500);

    while (cord < shipLength)
    {

        char ship = space[cord]; // to avoid using the index of the parameter i.e space[c] in the first if statements as it gives a warning
        if (ship == 'L')
        {

            if (strcmp(direction, "right") == 0)
            {
                direction = "up";
            }
            else if (strcmp(direction, "down") == 0)
            {
                direction = "right";
            }

            else if (strcmp(direction, "up") == 0)
            {
                direction = "left";
            }

            else
            {
                direction = "down";
            }
        };

        if (ship == 'R')
        {

            if (strcmp(direction, "down") == 0)
            {

                direction = "left";
            }
            else if (strcmp(direction, "left") == 0)
            {
                direction = "up";
            }

            else if (strcmp(direction, "up") == 0)
            {
                direction = "right";
            }

            else
            {
                direction = "down";
            }
        };

        if (ship == 'A')
        {

            if (strcmp(direction, "up") == 0)
            {
                Y_axis--;
            }

            else if (strcmp(direction, "down") == 0)
            {
                Y_axis++;
            }

            else if (strcmp(direction, "left") == 0)
            {
                X_axis--;
            }

            else
            {
                X_axis++;
            }
        }

        cord++;
    }

    sprintf(mem, "{x: %d, y: %d, direction: '%s'}", X_axis, Y_axis, direction); // Storing values in a string variable
    return mem;
}
