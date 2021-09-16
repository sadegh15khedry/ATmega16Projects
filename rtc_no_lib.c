/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11/21/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <i2c.h>
#include <alcd.h>
#include <twi.h>
#include <stdio.h>
#include <delay.h>
#include <bcd.h>

unsigned char dev_adr=0xD0;
unsigned char dev_adr1=0b11010001;
unsigned char sec_adr=0x00;
unsigned char min_adr=0x01;
unsigned char hour_adr=0x02;

unsigned char bcd , bin=0 , s1=0 , m1=0 , h1=0;
unsigned char day1=0 , month1=0 , year1=0;
unsigned char day_adr=0x04;
unsigned char month_adr=0x05;
unsigned char year_adr=0x06;
char str[16];




unsigned char bcd_to_bin(unsigned char b){
    bin = ((b & 0xf0)>>4)*10 + (b & 0x0f);
    return bin;
        
}
        
unsigned char bin_to_bcd(unsigned char b){
    bcd = (b/10)<<4;
    bcd = bcd | (b%10);
    return bcd;        
}

//date faunctions--------------------------------------------------------------------------------------
void set_date(unsigned char day,unsigned char month,unsigned char year){
    day=bin_to_bcd(day);
    month=bin_to_bcd(month);
    year=bin_to_bcd(year);
     
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(year_adr);
    i2c_write(year);
    i2c_stop();
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(month_adr);
    i2c_write(month);
    i2c_stop();
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(day_adr);
    i2c_write(day);
    i2c_stop();
     
}

void get_date(){
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(4);
    i2c_stop();

    i2c_start();
    i2c_write(dev_adr1);
    day1=i2c_read(1);
    month1=i2c_read(1);
    year1=i2c_read(0); 
    i2c_stop();
    
    day1=bcd_to_bin(day1);
    month1=bcd_to_bin(month1);
    year1=bcd_to_bin(year1);



}


//time functions--------------------------------------------------------------------------------------
void set_time(unsigned char h,unsigned char m,unsigned char s){
    h=bin_to_bcd(h);
    m=bin_to_bcd(m);
    s=bin_to_bcd(s);
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(sec_adr);
    i2c_write(s);
    i2c_stop();
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(min_adr);
    i2c_write(m);
    i2c_stop();
    
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(hour_adr);
    i2c_write(h);
    i2c_stop();
}


void get_time(){
    i2c_start();
    i2c_write(dev_adr);
    i2c_write(0);
    i2c_stop();

    i2c_start();
    i2c_write(dev_adr1);
    s1=i2c_read(1);
    m1=i2c_read(1);
    h1=i2c_read(0); 
    i2c_stop();
    
    s1=bcd_to_bin(s1);
    m1=bcd_to_bin(m1);
    h1=bcd_to_bin(h1);



}



void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// Mode: TWI Master
// Bit Rate: 100 kHz
twi_master_init(100);

// Bit-Banged I2C Bus initialization
// I2C Port: PORTB
// I2C SDA bit: 1
// I2C SCL bit: 0
// Bit Rate: 100 kHz
// Note: I2C settings are specified in the
// Project|Configure|C Compiler|Libraries|I2C menu.
i2c_init();

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")
set_time(9,30,30);   //h-m-s
set_date(15,2,77);   //day-month-year
while (1)
      {
        get_time();
        get_date();
        lcd_gotoxy(0,0);
        sprintf(str,"%d : %d : %d",h1,m1,s1);
        lcd_puts(str);
        lcd_gotoxy(0,1);
        sprintf(str,"%d : %d : %d",day1,month1,year1);
        lcd_puts(str);
        //delay_ms(1000);

      }
      
                
      
      
      
      
      
}