
#include <stdio.h>

#include "gpio.h"

gpio::gpio(char gpio_num) {

		FILE* fd;
		FILE* fd_dir;

		char gpio_name[100];
		char file_name[100];
		char file_name_gpio[100];

		sprintf(gpio_name, "/sys/class/gpio/gpio%d", gpio_num);

		fd = fopen("/sys/class/gpio/export", "w");
		if(fd == 0) {  
				printf("Unable to open interface for GPIO.\n");
		}
		fseek(fd, 0, SEEK_SET);
		fprintf(fd, "%d", gpio_num);
		fflush(fd);
		fclose(fd);


		sprintf(file_name, "%s/direction", gpio_name);
		fd_dir = fopen(file_name,"w");
		if(fd_dir == 0) {  
				printf("Unable to open direction interface for GPIO.\n");
		} else {
				fseek(fd_dir, 0, SEEK_SET);
				fprintf(fd_dir, "out");
				fflush(fd_dir);
				fclose(fd_dir);

				sprintf(file_name_gpio, "%s/value", gpio_name);
				fd_gpio =fopen(file_name_gpio, "w");
				fseek(fd_gpio, 0, SEEK_SET);
		}
}


void gpio::clearGPIO () {
		fprintf(fd_gpio, "%d", 0);
		fflush(fd_gpio);	
}

void gpio::setGPIO() {
		fprintf(fd_gpio, "%d", 1);
		fflush(fd_gpio);	
}

gpio::~gpio() {
		fclose(fd_gpio);

}
