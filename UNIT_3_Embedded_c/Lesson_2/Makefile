#########################
# Unit_3 Lesson_3 Lab_2 #
#   Abdallah Abotaleb   #
#########################

# tool chain
CC = arm-none-eabi-

# microprocessor
CFLAGS =-mcpu=arm926ej-s -g

# includes
INCS = -I .

# liberaries
LIBS =

# any .c files get its .o	
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# any .s files get its .o
AS_SRC = $(wildcard *.s)
AS_OBJ = $(AS_SRC:.s=.o)

# project name#
project_name =Lab_2_cortex-m3


# $< : dependense 
# $@ : target     


all: $(project_name).bin
 	@echo "============= Build is Done ============="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(project_name).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AS_OBJ) -o $@ -Map=map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin
	