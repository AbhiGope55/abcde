//3. Create a machine for memory reference instructions AND, ADD and LDA for indirect addressing ie. I=1
#include <stdio.h>
#include <conio.h>
int program[] = {0x8064, 0x91C8, 0xA8F2};
int choice = 0;
int fetch()
{
    printf("\n Enter your choice");
    printf("\n 1 for AND");
    printf("\n 2 for ADD");
    printf("\n 3 for LDA");
    printf("\n Enter your choice");
    scanf("%d", &choice);
    return program[choice];
}
int instrnum = 0;
int dr = 0;
int mar = 0;
int acc = 0xA937;
int ar;
int operand[] = {0x78A9, 0xBE24, 0x4DCA};
int instr1 = 0;
void decode(int instr)
{
    instr1 = instr;
    instrnum = (instr1 & 0xF000) >> 12;
    switch (instrnum)
    {
    case 8:
        printf("\n AND");
        ar = (instr & 0xFFF);
        mar = operand[0];
        printf("\n Operand at address %x is %x", ar, mar);
        dr = mar;
        acc = acc & dr;
        printf("\n %x", acc);
        break;
    case 9:
        printf("\n ADD");
        ar = (instr & 0xFFF);
        mar = operand[1];
        printf("\n Operand at address %x is %x", ar, mar);
        dr = mar;
        acc = acc + dr;
        printf("\n %x", acc);
        break;
    case 10:
        printf("\n LDA");
        ar = (instr & 0xFFF);
        mar = operand[2];
        printf("\n Operand at address %x is %x", ar, mar);
        dr = mar;
        acc = dr;
        printf("\n %x", acc);
    }
}
void run()
{
    printf("\n Program for Indirect addressing, I=1");
    int instr = fetch();
    printf("\n Instr is %x", instr);
    decode(instr);
}
void main()
{
    clrscr();
    run();
    getch();
}