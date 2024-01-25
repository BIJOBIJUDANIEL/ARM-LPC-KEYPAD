#include<lpc21xx.h>	  atmel
int i;
void cmd(char a);
void data(char a);
void delay();
void display(const char *p);
void display(const char *p){
	while(*p!='\0'){
		data(*p);
		p++;
	}
}
void command(char a)
{
    IOCLR0=0xFF<<16|1<<14|1<<15;
    IOSET0=a<<16;
    IOCLR0=1<14;
    IOSET0=1<<15;
    delay();
    IOCLR0=1<<15;
}
void data(char a)
{
    IOCLR0=0xFF<<16|1<<14|1<<15;
    IOSET0=a<<16;
    IOSET0=1<<14;
    IOSET0=1<<15;
    delay();
    IOCLR0=1<<15;
}
void delay()
{
   for(i=0;i<150000;i++);
}
int main()
{
   char string[] = "12345";
   char pass[20];
   int count = 0;
   PINSEL1=0;
   PINSEL0=0;
   IODIR0=0xFFFFFFFF;
   IODIR1=0x000F0000;
   command(0x01);
   command(0x0E);
   command(0x80);
   command(0x06);
   command(0x38);
   while(1)
   {
  
     IOCLR1 = 1<<16;
     if((IOPIN1&(1<<20))==0)
     {
        data('0');
	    pass[count++] = '0';
	    while((IOPIN1&(1<<20))==0);
     }
     if((IOPIN1&(1<<21))==0)
     {
        data('1');
	    pass[count++] = '1';
	    while((IOPIN1&(1<<21))==0);
     }
     if((IOPIN1&(1<<22))==0)
     {
        data('2');
	    pass[count++] = '2';
	    while((IOPIN1&(1<<22))==0);
     }
     if((IOPIN1&(1<<23))==0)
     {
        data('3');
	    pass[count++] = '3';
	    while((IOPIN1&(1<<23))==0);
     }
     IOSET1 = 1<<16;



	  IOCLR1 = 1<<17;
     if((IOPIN1&(1<<20))==0)
     {
        data('4');
	    pass[count++] = '4';
	    while((IOPIN1&(1<<20))==0);
     }
     if((IOPIN1&(1<<21))==0)
     {
        data('5');
	    pass[count++] = '5';
	    while((IOPIN1&(1<<21))==0);
     }
     if((IOPIN1&(1<<22))==0)
     {
        data('6');
	    pass[count++] = '6';
	    while((IOPIN1&(1<<22))==0);
     }
     if((IOPIN1&(1<<23))==0)
     {
        data('7');
	    pass[count++] = '7';
	    while((IOPIN1&(1<<23))==0);
     }
     IOSET1 = 1<<17;




	  IOCLR1 = 1<<18;
     if((IOPIN1&(1<<20))==0)
     {
        data('8');
	    pass[count++] = '8';
	    while((IOPIN1&(1<<20))==0);
     }
     if((IOPIN1&(1<<21))==0)
     {
        data('9');
	    pass[count++] = '9';
	    while((IOPIN1&(1<<21))==0);
     }
     if((IOPIN1&(1<<22))==0)
     {
        data('A');
	    pass[count++] = 'A';
	    while((IOPIN1&(1<<22))==0);
     }
     if((IOPIN1&(1<<23))==0)
     {
        data('B');
	    pass[count++] = 'B';
	    while((IOPIN1&(1<<23))==0);
     }
     IOSET1 = 1<<18;








	  IOCLR1 = 1<<19;
     if((IOPIN1&(1<<20))==0)
     {
       command(0x01);
	   display("CHECKING");
	   delay();
	   if(strcmp(pass,string)==0)
	   {
	      command(0x01);
		  display("PASSWORD MATCHED");
		  delay();
		  command(0x01);
		  display("MOTOR ON");
		  delay();
		  command(0x01);
		  IOSET0 = 0x00000001;
		  display("CLOCK WISE");


	   }
	   else
	   {
	       command(0x01);
	       display("WRONG PASSWORD");
		   IOCLR0 = 0xFFFFFFFF;
	   }
     }
     if((IOPIN1&(1<<21))==0)
     {

	    command(0x01);
        pass[20] = 0;
		count = 0;
     }
     if((IOPIN1&(1<<22))==0)
     {
        data('.');
	    pass[count++] = '.';
	    while((IOPIN1&(1<<22))==0);
     }
     if((IOPIN1&(1<<23))==0)
     {
        data('#');
	    pass[count++] = '#';
	    while((IOPIN1&(1<<23))==0);
     }
     IOSET1 = 1<<19;
	
}

}
