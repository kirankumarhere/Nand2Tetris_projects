#include<stdio.h>
#include<string.h>


#define MAXLENGTH 20
#define MAXENTRIES 1024

struct SymbolTableEntry
{
char symbol[MAXLENGTH];
int address;
};


struct SymbolTableEntry SymbolTable[MAXENTRIES];

//to initialize all the predefined symbols and other entries to null..
void init_symbol_table()
{
int i=0;
strcpy(SymbolTable[0].symbol,"SP");
strcpy(SymbolTable[1].symbol,"LCL");
strcpy(SymbolTable[2].symbol,"ARG");
strcpy(SymbolTable[3].symbol,"THIS");
strcpy(SymbolTable[4].symbol,"THAT");
strcpy(SymbolTable[5].symbol,"R0");
strcpy(SymbolTable[6].symbol,"R1");
strcpy(SymbolTable[7].symbol,"R2");
strcpy(SymbolTable[8].symbol,"R3");
strcpy(SymbolTable[9].symbol,"R4");
strcpy(SymbolTable[10].symbol,"R5");
strcpy(SymbolTable[11].symbol,"R6");
strcpy(SymbolTable[12].symbol,"R7");
strcpy(SymbolTable[13].symbol,"R8");
strcpy(SymbolTable[14].symbol,"R9");
strcpy(SymbolTable[15].symbol,"R10");
strcpy(SymbolTable[16].symbol,"R11");
strcpy(SymbolTable[17].symbol,"R12");
strcpy(SymbolTable[18].symbol,"R13");
strcpy(SymbolTable[19].symbol,"R14");
strcpy(SymbolTable[20].symbol,"R15");
strcpy(SymbolTable[21].symbol,"SCREEN");
strcpy(SymbolTable[22].symbol,"KBD");

SymbolTable[0].address=0;
SymbolTable[1].address=1;
SymbolTable[2].address=2;
SymbolTable[3].address=3;
SymbolTable[4].address=4;
SymbolTable[5].address=0;
SymbolTable[6].address=1;
SymbolTable[7].address=2;
SymbolTable[8].address=3;
SymbolTable[9].address=4;
SymbolTable[10].address=5;
SymbolTable[11].address=6;
SymbolTable[12].address=7;
SymbolTable[13].address=8;
SymbolTable[14].address=9;
SymbolTable[15].address=10;
SymbolTable[16].address=11;
SymbolTable[17].address=12;
SymbolTable[18].address=13;
SymbolTable[19].address=14;
SymbolTable[20].address=15;
SymbolTable[21].address=16384;
SymbolTable[22].address=24576;

///for remaining entries...making it invalid...
for(i=23;i<MAXENTRIES;i++)
{
strcpy(SymbolTable[i].symbol,"\0");
SymbolTable[i].address=-1;
}

}


void addEntry(struct SymbolTableEntry item)
{
int i=0;
while((strcmp(SymbolTable[i].symbol,item.symbol)!=0) && (strcmp(SymbolTable[i].symbol,"\0")!=0) && (i<MAXENTRIES))
i++;

if((strcmp(SymbolTable[i].symbol,item.symbol)==0) && (SymbolTable[i].address==-1)) //already symbol name present..but address not there....
SymbolTable[i].address = item.address;

if(strcmp(SymbolTable[i].symbol,"\0")==0) //symbol not there...fresh entry to table...
{
strcpy(SymbolTable[i].symbol,item.symbol);
SymbolTable[i].address = item.address;
}

if(i>=MAXENTRIES)
printf("Number of entries has reached the limit...increase MAXENTRIES and recompile the assembler..\n");

}


//This is invoked only in pass 2 after all addresses are assigned...
int getaddress(char* symbol)
{

int i=0;

while(i<MAXENTRIES && (strcmp(SymbolTable[i].symbol,symbol)!=0))
i++;

if(strcmp(SymbolTable[i].symbol,symbol)==0)
return (SymbolTable[i].address);
else
return -1;

}


int main()
{

init_symbol_table(); //initialize the table...

struct SymbolTableEntry item;

strcpy(item.symbol,"new");
item.address = 16;
addEntry(item);


strcpy(item.symbol,"new1");
item.address = 17;
addEntry(item);


printf("address of new is %d\n",getaddress("new"));
printf("address of new1 is %d\n",getaddress("new1"));




return 0;
}























