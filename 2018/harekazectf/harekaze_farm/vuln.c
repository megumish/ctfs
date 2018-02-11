#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ANIMAL 3

char select_animals[MAX_ANIMAL][8] = {"", "", ""};

int main(void) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("Welcome to Harekaze farm");
	int animal_num = 0;
	for(animal_num = 0; animal_num < MAX_ANIMAL; animal_num++) {
		char animal_name[16] = {};
		printf("Input a name of your favorite animal: ");
		size_t name_len = __read_chk(0, animal_name, sizeof(animal_name), sizeof(animal_name));
		animal_name[name_len - 1] = '\x00';
		if (!strcmp(animal_name, "cow")) {
			memcpy(select_animals[animal_num], animal_name, 16);
		}
		if (!strcmp(animal_name, "sheep")) {
			memcpy(select_animals[animal_num], animal_name, 16);
		}
		if (!strcmp(animal_name, "goat")) {
			memcpy(select_animals[animal_num], animal_name, 16);
		}
		if (!strcmp(animal_name, "hen")) {
			memcpy(select_animals[animal_num], animal_name, 16);
		}
	}
	puts("Begin to parade!");
	for(animal_num = 0; animal_num < MAX_ANIMAL; animal_num++) {
		if (!strcmp(select_animals[animal_num], "cow")) {
			puts("cow: \"moo\" \"moo\"");
		}
		if (!strcmp(select_animals[animal_num], "sheep")) {
			puts("sheep: \"baa\" \"baa\"");
		}
		if (!strcmp(select_animals[animal_num], "goat")) {
			puts("goat: \"bleat\" \"bleat\"");
		}
		if (!strcmp(select_animals[animal_num], "hen")) {
			puts("hen: \"cluck\" \"cluck\"");
		}
		if (!strcmp(select_animals[animal_num], "isoroku")) {
			puts("isoroku: \"flag is here\" \"flag is here\"");
			char buf[256] = {};
			FILE* flag_file = fopen("/home/harekaze_farm/flag", "r");
			if (!flag_file) {
				puts("ERROR: FILE OPEN ERROR");
				exit(1);
			}
			fgets(buf, 255, flag_file);
			puts(buf);
		}
	}
	return 0;
}
