#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void draw(void *u, int w, int h)
{
    char(*world)[w] = u;
    printf("\33[H");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf(world[i][j] ? "⚽" : " ");
        }
        printf("\n");
    }
}
void evolution(void *u, int w, int h)
{
    char(*world)[w] = u;
    char new[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int lives = 0;
            for (int i_around = i - 1; i_around <= i + 1; i_around++)
            {
                for (int j_around = j - 1; j_around <= j + 1; j_around++)
                {
                    if (world[(i_around + h) % h][j_around + w] % w)
                    {
                        lives++;
                    }
                }
            }
            if (world[i][j])
            {
                lives--;
            }
            if (lives == 3)
            {
                new[i][j] = 1;
            }
            else if (lives == 2 && world[j][i] == 1)
            {
                new[i][j] = 1;
            }
            else
            {
                new[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            world[i][j] = new[i][j];
        }
    }
}

int main()
{
    srand(time(0));
    int w = 30;
    int h = 30;
    char world[h][w];
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
            world[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;

    while (1)
    {
        draw(world, w, h);
        evolution(world, w, h);
        usleep(200000);
    }
    return 0;
}