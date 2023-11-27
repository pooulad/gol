#include <stdio.h>
#include <stdlib.h>

void draw(void *u, int w, int h)
{
    char(*world)[w] = u;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf(world[i][j] ? "+" : ".");
        }
        printf("\n");
    }
}
void envolution(void *u, int w, int h)
{
}

int main()
{
    int h = 30;
    int w = 30;
    char world[w][h];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            world[i][j] = rand() < RAND_MAX / 10 ? 1 : 0;
        }
    }

    draw(world, w, h);
    return 0;
}