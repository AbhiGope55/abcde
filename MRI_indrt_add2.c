//4. Create a machine for memory reference instructions STA, BUN, BSA and ISZ for indirect addressing ie. I=1
#include <stdio.h>
#include <conio.h>
void main()
{
    printf("\n Program for indirect addressing, I=1");
    printf("\n Enter Bxxx for STA");
    printf("\n Enter Cxxx for BUN");
    printf("\n Enter Dxxx for BSA");
    printf("\n Enter Exxx for ISZ");
    int instr = 0;
    scanf("%x", &instr);
    int operand[] = {0x78A9, 0xBE24, 0x4DCA, 0x56C7};
    int acc = 0xA937;
    int dr = 0;
    int ar = 0;
    int pc = 0x222;
    int mar;
    int instr1 = instr;
    int ar = (instr & 0xFFF);
    int instrnum = (instr1 & 0xF000) >> 12;
    printf("The instruction is %x", instrnum);
    switch (instrnum)
    {
    case 11:
        printf("\n Store Accumulator(STA)");
        ar = (instr & 0xFFF);
        mar = operand[0];
        mar = acc;
        printf("\n Mar=", mar);
        break;
    case 12:
        printf("\n Branch Unconditionally(BUN)");
        ar = (instr & 0xFFF);
        mar = operand[1];
        pc = ar;
        break;
    case 13:
        printf("\n Branch and Save Return Address(BSA)");
        ar = (instr & 0xFFF);
        mar = operand[2];
        mar = pc;
        pc = ar + 1;
        break;
    case 14:
        printf("\n Increment and skip if zero(ISZ)");
        ar = (instr & 0xFFF);
        mar = operand[2];
        dr = mar;
        if (dr == 0)
        {
            pc = pc + 1;
        }
        else
            dr = dr + 1;
        mar = dr;
        printf("\nNow DR is %x", dr);
        printf("\n Mar= %x", mar);
        break;
    }
}