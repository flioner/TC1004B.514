#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int val = 1;

void hola(int signalNum)
{
    printf("Recibi la segnal %d ", signalNum);
}

void terminarwhile(int sgnlNum)
{
    printf("Terminando while");
    val = 0;
}

int main()
{
    signal(12, terminarwhile);
    signal(2, hola);

    while (val == 1)
    {
        printf("trabajando \n");
        sleep(1);
    }

    printf("Aqui nunca llega \n");
    return 0;
}