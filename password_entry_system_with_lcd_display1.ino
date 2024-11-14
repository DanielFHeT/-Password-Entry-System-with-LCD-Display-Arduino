byte a = 255;

String password = String("1234");
String userPassword = String("0000");
int i;
int count=0;

ISR(PCINT0_vect)
{
  		byte b = 0, c = 0;
  		a = 0;
  		PCMSK0 = 0b00000000;
  		c = (PINB & 0b000001111) ^ 0b00001111;
  		while(c >>= 1)b++;
        DDRB = 0b00101111;
  		PORTB ^= 0b00001111;
        DDRD &= 0b00001111;
  		PORTD |= 0b11110000;
  		c = (PIND & 0b11110000) ^ 0b11110000;
  		while(c <<= 1)a++;  
  		a = a + b * 4;
  		while((PIND & 0b11110000) ^ 0b11110000);
}

void setup()
{
  		Serial.begin(9600);
		initKeypad();
  		initLCD();
        //writeMsg("Hello World!");
        
  
}
void loop()
{
   while(password != userPassword){
    userPassword[i]=getKey();
     Serial.println (userPassword[i]);
    i++;
    if(i>3){
      i=0;
      writeCmd(0x01);
      writeMsg("again Try");
      count++;
      Serial.println(count);
      if(count==3){
      break;
      }
      }
    }
     if (password == userPassword){
       writeCmd(0x01);
    writeMsg("The door is open.!");
  }
   else if (count==3){
     writeCmd(0x01);
    writeMsg(" Call admin");
    while(1);
   }
}

char getKey()
{		char key[] = {'*', '0', '#', 'D','7','8','9','C','4','5','6','B','1','2','3','A'};
 		char thisKey;
        while(a > 15);
		initKeypad();
 		thisKey = key[a];
 		a = 255;
        return thisKey;
}
String getPassword()
{
	String pass= "0000";
  	int i;
  	for(i = 0; i < 4; i++)
    {
            pass[i] = getKey();
			Serial.println(pass[i]);
     		writeCmd(0x01);
        	writeMsg(pass);
   }
  	return pass;
}

void initKeypad()
{
        DDRB = 0b00100000;
  		PORTB |= 0b00001111;
  		DDRD |= 0b11110000;
  		PORTD &= 0b00001111;
  		PCICR = 0b00000001;
  		PCMSK0 = 0b00001111;
  		SREG |= 0b10000000;
}


void initLCD()
{
        DDRD |= 0b00001100;
  		PORTD &= 0b11110011;
        DDRC = 0b00001111;
  		_delay_ms(500);
    	writeCmd(0x33);
  		writeCmd(0x32);
    	writeCmd(0x28);
    	writeCmd(0x01);
  		writeCmd(0x06);
      	writeCmd(0x0c);
}

void writeMsg(String s)
{
  		byte i, d;
  		PORTD |= 0b00000100;
  		for(i = 0; i < 16; i++)
        {
         	if(!s[i]) break;
          	d = s[i] & 0b11110000;
          	writeNibble(d);
          	d = s[i] << 4;
          	writeNibble(d);
        }
}

void writeCmd(byte c)
{
  		byte d;
  		PORTD &= 11110011;
        d = c & 0b11110000;
        writeNibble(d);
        d = c << 4;
        writeNibble(d);
}

void writeNibble(byte d)
{
  		PORTD &= 0b11110111;
  		PORTC &= 0;
  		PORTC |= (d>>4);
  		PORTD |= 0b00001000;
 		_delay_ms(5);
  		PORTD &= 0b11110111; 	
   		_delay_ms(5);

}
