#include "config.h"

#ifndef __SDISK2__
#define __SDISK2__


#define VER "5.4"
#define YEAR "(2018)"

// these are done during compilation
//#define _LCD_
//#define _LCD_NOKIA_


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "string.h"

#ifdef _LCD_
	#include "lcd.h"
#endif

#ifdef _LCD_NOKIA_
	#include "lcd_nokia.h"
#endif

#ifdef _OLED_
    #include "oled.h"
#endif

#include "SPI_routines.h"
#include "SD_routines.h"
#include "FAT32.h"

#define MAXNIC           4

#define enter_is_pressed() bit_is_clear(ENTER_PORT,ENTER_BIT)
#define down_is_pressed()  (bit_is_clear(DOWN_PORT,DOWN_BIT)*(flip_buttons==0) | bit_is_clear(UP_PORT,UP_BIT)*(flip_buttons==1))
#define up_is_pressed()    (bit_is_clear(UP_PORT,UP_BIT)*(flip_buttons==0) | bit_is_clear(DOWN_PORT,DOWN_BIT)*(flip_buttons==1))
#define diskII_disable()   bit_is_set(DISKII_PIN,DISKII_ENABLE)

#define CHECKSUM_CONFIG 0X01AB02CD

struct Sdisk_config_structure
{
	unsigned long checksum;
	unsigned char sd_card_speed;
	unsigned long directory_of_last_mounted_nic;
	unsigned int  id_of_last_mounted_nic;
	unsigned long directory_of_previous_mounted_nic;
	unsigned int  id_of_previous_mounted_nic;
	unsigned char lcd_contrast;
	unsigned char nic_mounted;
	unsigned char EMPTY[64]; // just leave empty for future features
	unsigned long nic_dir[MAXNIC];
	unsigned int  nic_id[MAXNIC];
};

void            init(char splash);
void            display_sd_ejected();
char            init_sd(char splash);
void            verify_status();
void            select_nic();
void            find_previous_nic();
void            swap_nic();
unsigned char   is_a_nic(struct dir_Structure *file);
unsigned char   is_a_dir(struct dir_Structure *file);
unsigned int    mount_nic_image(int file_id, struct dir_Structure* file);
void            create_config_file();
void            writeBackSub();
void            writeBackSub2(unsigned char bn, unsigned char sc, unsigned char track);
void            writeBack();
void            cancelRead();
void            buffClear();
void            set_speed();
void            configButtons();
int             main(void);

#if defined(_LCD_NOKIA_) || defined(_OLED_)
void            set_contrast();
void            setup();
void            icons(unsigned char i1, unsigned char i2, unsigned char i3);
#endif

#endif
