#ifndef GPIO_H
#define GPIO_H


//typedef uint8_t char;

class gpio {

private:
	FILE* fd_gpio;

public:

	gpio(char);
	~gpio();
	
	void setGPIO();
	void clearGPIO();
};




#endif // GPIO_H
