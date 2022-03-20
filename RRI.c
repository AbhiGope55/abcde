// 5: Create a machine for the register reference instructions CLA, CLE, CMA, CIR, CIL and INC
#include <stdio.h>
#include <conio.h>
int program[] = {0x7800, 0x7400, 0x7200, 0x7100, 0x7080, 0x7040, 0x7020};
int choice = 0;
int fetch()
{
    printf("\n Enter your choice");
    printf("\n 1 for CLA");
    printf("\n 2 for CLE");
    printf("\n 3 for CMA");
    printf("\n 4 for CME");
    printf("\n 5 for CIR");
    printf("\n 6 for CIL");
    printf("\n 7 for INC");
    printf("\n Enter your choice");
    scanf("%d", &choice);
    return program[--choice];
}
int acc = 0xA937;
int mar = 0x0000;
int instr1 = 0;
int E = 0x0001;
void decode(int instr)
{
    instr1 = instr;
    mar = (instr1 & 0x0FFF);
    switch (mar)
    {
    case 0x800:
        printf("\n (CLA) Clear Accumulator");
        acc = 0;
        printf("\n The accumulator has been cleared and has become %x", acc);
        break;
    case 0x400:
        printf("\n (CLE) Clear E");
        E = 0;
        printf("\n The E has been cleared and has become %x", E);
        break;
    case 0x200:
        printf("\n (CMA) Complement Accumulator");
        acc = ~acc;
        printf("\n The complemented value of accumulator is %x", acc);
        break;
    case 0x100:
        printf("\n (CME) Complement E");
        E = ~E;
        printf("\n The complemented value of E is %x", E);
        break;
    case 0x80:
        printf("\n (CIR) Circulate right");
        acc = acc >> 1;
        E = acc & 0x0001;
        printf("\n The value of accumulator after circulate right is %x", acc);
        printf("\n The value of E ie. ACC(0) after circulate right is %x", E);
        break;
    case 0x40:
        printf("\n (CIL) Circulate left");
        acc = acc << 1;
        E = acc & 0x8000;
        printf("\n The value of accumulator after circulate left is %x", acc);
        printf("\n The value of E ie. ACC(15) after circulate left is %x", E);
        break;
    case 0x20:
        printf("\n (INC) Increment AC");
        acc = acc + 1;
        printf("\n The value of after increment is %x", acc);
        break;
    }
}
void run()
{
    printf("\n Program to create a machine for the register reference instructions CLA, CLE, CMA, CIR, CIL and INC");
    int instr = fetch();
    printf("\n Instr is %x", instr);
    decode(instr);
}
int main()
{
    run();
    return 0;
}