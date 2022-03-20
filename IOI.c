// 6 Create a machine for the Input Output instructions INP, OUT, SKI, SKO, ION and IOF
#include <stdio.h>
#include <conio.h>
int choice = 0;
int fetch()
{
    printf("\n Enter your choice");
    printf("\n 1 for INP");
    printf("\n 2 for OUT");
    printf("\n 3 for SKI");
    printf("\n 4 for SKO");
    printf("\n 5 for ION");
    printf("\n 6 for IOF");
    printf("\n Enter your choice");
    scanf("%d", &choice);
    return choice;
}
int acc = 0xA937;
int INPR = 0xB8F2;
int PC = 0x022;
int FGI = 1;
int FGO = 1;
int OUTR = 0;
int IEN = 0;
void decode(int instrcode)
{
    switch (instrcode)
    {
    case 1:
        printf("\n (INP)Input Character");
        if (FGI == 1)
        {
            acc = INPR;
            FGI = 0;
        }
        printf("\n The new content of accumulator will be %x ", acc);
        break;
    case 2:
        printf("\n (OUT)Output Character");
        if (FGO == 1)
        {
            OUTR = acc;
            FGO = 0;
        }
        printf("\n The new content of output register (OUTR) will be %x", OUTR);
        break;
    case 3:
        printf("\n (SKI) Skip on Input Flag");
        if (FGI == 1)
        {
            PC = PC + 1;
        }
        printf("\n The new value of PC will be %x", PC);
        break;
    case 4:
        printf("\n (SKO) Skip on Output Flag");
        if (FGO == 1)
        {
            PC = PC + 1;
        }
        printf("\n The new value of PC will be %x", PC);
        break;
    case 5:
        printf("\n (ION) Interrupt On");
        IEN = 1;
        printf("\n The value of Interrupt now is ON an the value of IEN is %d", IEN);
        break;
    case 6:
        printf("\n (IOF) Interrupt Off");
        IEN = 0;
        printf("\n The value of Interrupt now is OFF an the value of IEN is %d", IEN);
        break;
    }
}
void run()
{
    printf("\n Program to create a machine for the Input Output instructions INP, OUT, SKI, SKO, ION and IOF");
    int instrcode = fetch();
    decode(instrcode);
}
void main()
{
    run();
}