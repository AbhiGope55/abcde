//2. W A P to Create the machine for Memory Reference Instructions with addressing mode I=0 (STA,BUN,BSA,ISZ)
#include <stdio.h>
#include <conio.h>
void main()
{
    printf("\n Program for direct addressing, I=0");
    printf("\n Enter 4xxx for STA");
    printf("\n Enter 5xxx for BUN");
    printf("\n Enter 6xxx for BSA");
    printf("\n Enter 7xxx for ISZ");
    printf("\nEnter choice : ");
    int instr = 0;
    scanf("%x", &instr);
    int acc = 0xA937;
    int DR = 0;
    int PC;
    int AR = 0;
    int instr1 = instr;
    int mar = (instr & 0xFFF);
    int instrnum = (instr1 & 0xF000) >> 12;
    printf("The instruction is %x", instrnum);
    switch (instrnum)
    {
    case 4:
        printf("\n Store Accumulator(STA)");
        mar = acc;
        printf("\n Mar= %x", mar);
        break;
    case 5:
        printf("\n Branch Unconditionally(BUN)");
        PC=AR;
        break;
    case 6:
        printf("\n Branch and Save Return Address(BSA)");
        mar = PC;
        PC = AR + 1;
        break;
    case 7:
        printf("\n Increment and skip if zero(ISZ)");
        DR = mar;
        if (DR == 0)
        {
            PC=0x0022;
            PC = PC + 1;
        }
        else
            DR = DR + 1;
        mar = DR;
        printf("\nNow DR is %x", DR);
        printf("\n Mar= %x", mar);
        break;
    }
}
