//1. W.A.P to Create the machine for Memory Reference Instructions with addressing mode I=0 (AND,ADD,LDA)
#include <stdio.h>
#include <conio.h>
int program[] = {0x0096, 0x11C8, 0x28F2};
int choice = 0;
int fetch()
{
    printf("\n 1 for AND");
    printf("\n 2 for ADD");
    printf("\n 3 for LDA");
    printf("\n Enter your choice");
    scanf("%d", &choice);
    return program[--choice];
}
int instrnum = 0;
int acc = 0xA937;
int mar = 0;
int instr1 = 0;
void decode(int instr)
{
    instr1 = instr;
    instrnum = (instr1 & 0xF000) >> 12;
    switch (instrnum)
    {
    case 1:
        printf("\n AND");
        mar = (instr & 0x0FFF);
        acc = acc & mar;
        printf("\n %x", acc);
        break;
    case 2:
        printf("\n ADD");
        mar = (instr & 0x0FFF);
        acc = acc + mar;
        printf("\n %x", acc);
        break;
    case 3:
        printf("\n LDA");
        mar = (instr & 0x0FFF);
        acc = mar;
        printf("\n %x", acc);
    }
}
void run()
{
    printf("\n Program for direct addressing, I=0");
    int instr = fetch();
    printf("\n Instr is %x", instr);
    decode(instr);
}
int main()
{
    
    run();
    return 0;
}