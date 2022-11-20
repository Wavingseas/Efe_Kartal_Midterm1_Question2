#define rccahblenR * ( (unsigned volatile int *)0x40023830)
#define gpiodmask 1<<3
#define gpiodModr *((unsigned volatile int* )0x40020c00)
#define gpiodP14mask 1<<28
#define gpiodP13mask 1<<26
#define gpiodP15mask 1<<30
#define gpiodP12mask 1<<24
#define gpiodOdr  *((unsigned volatile int *)0x40020c14)
#define gpiodp14onmask 1<<14
#define gpiodp14ofmask 0<<14
#define gpiodp13onmask 1<<13
#define gpiodp13ofmask ~(1<<13)
#define gpiodp15onmask 1<<15
#define gpiodp15ofmask 0<<15
#define gpiodp12onmask 1<<12
#define gpiodp12ofmask 0<<12

// LD12 = green LD13 = orange LD14 = red LD15 = blue

void init_leds ();   //functions are named as in the question description in YUlearn.
void turn_name_on();
void turn_surname_on();
void turn_name_off();
void turn_surname_off();
void delaythat(); //delaythat because i'm lazy :)

//My name is Efe Kartal
//e+f+e in ascii is = 101+102+101 = 304 , 304 mod 4 = 0 (red led)
//k+a+r+t+a+l is ascii is = 107 + 97 + 114 + 116 + 97 + 108 = 639 , 639 mod 4 = 3 (green led)
void init_leds(){

rccahblenR = gpiodmask;
gpiodModr=gpiodP14mask;  //clock and leds for red and green enabled
gpiodModr |=gpiodP12mask;

}

void turn_name_on(){

gpiodOdr=gpiodp14onmask; //red led turned on

}
void turn_name_off(){

gpiodOdr&=gpiodp14ofmask; //red led turned off

}
void turn_surname_on(){

gpiodOdr|=gpiodp12onmask; //green led turned on

}
void turn_surname_off(){

gpiodOdr&=gpiodp12ofmask;  //green led turned off

}

void delaythat(){
for(int i=0;i<0x00000FFF;i++){
//simple delay function we use in the laboratory sessions
}
}


int main() {

init_leds();
int i=0;
while(i<3){
	turn_name_on();
	delaythat();
	turn_name_off();
	i = i+1;
	//while loop that turns 3 times (efe has 3 characters)
}

int j=0;
while(j<6){
	turn_surname_on();
	delaythat();
	turn_surname_off();
	j = j+1;
	//while loop that turns 6 times (kartal has 6 letters)
}

return 0;
}


