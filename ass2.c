
/*Experiment No. 2 :*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


struct symboltable

  {
	char Symbol[8];
	int  Address;

  }ST[2];


struct literaltable

  {
	int  Literal;
	int  Address;

  }LT[2];


struct symboltable ST[2]={{"A",204},{"NEXT",202}};

struct literaltable LT[2]={{1,205},{5,206}};

char s1[8],s2[8],s3[8],s4[8],s5[8],s6[8],s7[8],label[8];

 int main()
 {
	char nextline[80];
	int i;
	FILE *ptr1;
	ptr1=fopen("input.txt","r");

	while(!feof(ptr1))
	  {
		//Read a line of assembly program and remove special characters
		i=0;
		nextline[i]=fgetc(ptr1);
		while(nextline[i]!='\n'&& nextline[i]!=EOF )
		    {
				if(!isalnum(nextline[i]))
					nextline[i]='  ';
				else
					nextline[i]=toupper(nextline[i]);
				i++;
				nextline[i]=fgetc(ptr1);
		    }
		nextline[i]='\0';

		sscanf(nextline,"%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7); //read from the nextline
		//printf("%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7);

		if(strcmp(s2,"AD")==0)
		      printf("\nAssembler Directive");
		else if(strcmp(s2,"IS")==0)
		{
			if(strcmp(s6,"S")==0)
				printf("\n%s\t%s\t%d",s3,s5,ST[atoi(s7)].Address);
			else if(strcmp(s6,"L")==0)
				printf("\n%s\t%s\t%d",s3,s5,LT[atoi(s7)].Address);
		}
		else if(strcmp(s2,"DL")==0)
			printf("\n00\t00\t00%s",s5);
	  }
  return (0);
 }

/* Assembler Directive 
 04 	 01 	 205 
 03 	 02 	 206 
 00	00	005
 Assembler Directive 
 00	00	001 
 00	00	005 
 00	00	005*/

