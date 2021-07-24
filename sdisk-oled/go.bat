avr-gcc -o "lcd.o" "lcd.c" -Wall -Os -Wno-deprecated-declarations -Wno-strict-aliasing -D__PROG_TYPES_COMPAT__ -D_SDISK_ORIGINAL_ -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=27000000UL -MMD -MP -c 
avr-gcc -o "SPI_routines.o" "SPI_routines.c" -Wall -Os -Wno-deprecated-declarations -Wno-strict-aliasing -D__PROG_TYPES_COMPAT__ -D_SDISK_ORIGINAL_  -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=27000000UL -MMD -MP -c 
avr-gcc -o "SD_routines.o" "SD_routines.c" -Wall -Os -Wno-deprecated-declarations -Wno-strict-aliasing -D__PROG_TYPES_COMPAT__ -D_SDISK_ORIGINAL_  -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=27000000UL -MMD -MP -c 
avr-gcc -o "FAT32.o" "FAT32.c" -Wall -Os -Wno-deprecated-declarations -Wno-strict-aliasing -D__PROG_TYPES_COMPAT__ -D_SDISK_ORIGINAL_  -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=27000000UL -MMD -MP -c 
avr-gcc -x assembler-with-cpp -mmcu=atmega328p -MMD -MP -D_SDISK_ORIGINAL_ -c -o "sub.o" "sub.S"
avr-gcc -o "main.o" "main.c" -Wall -Os -Wno-deprecated-declarations -Wno-strict-aliasing -D__PROG_TYPES_COMPAT__  -D_SDISK_ORIGINAL_  -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=27000000UL -MMD -MP -c 
avr-gcc -Wl,-Map,sdisk2_original.map -mmcu=atmega328p -D_SDISK_ORIGINAL_ -o "sdisk2_original.elf" "main.o" "lcd.o" "SPI_routines.o" "SD_routines.o" "FAT32.o" "sub.o"  
avr-objcopy -R .eeprom -O ihex "sdisk2_original.elf" "sdisk2_original.hex"
avr-size --format=avr --mcu=atmega328p "sdisk2_original.elf"
