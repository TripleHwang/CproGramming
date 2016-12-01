#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENT 100
#define BUF 100

struct student {
	char *name;
	char *id;
	char grade;
};

struct student *read_student();
void add_student(struct student array[], struct student *std);
void print_student(struct student students[]);
float class_average(struct student students[]);

char *get_word();

int meetEOF = 0;

int main(void) {
	struct student students[MAX_STUDENT] = {{0}};
	struct student *std;

	while ((std = read_student()) != NULL) {
		add_student(students,std);
	}
	print_student(students);
	printf("\nClass AVG.:\t%f\n", class_average(students));
}

struct student *read_student() {
	struct student *std;
	char *name = get_word();
	char *id = get_word();
	char *grade = get_word();

	if(name == NULL || id == NULL || grade == NULL) return NULL;
//
	std = (struct student *)(malloc(sizeof(struct student)));
	std->name = name;
	std->id = id;
	std->grade = *grade;
//
	return std;
}

void add_student(struct student students[], struct student *std) {
	int inserted = 0;
	struct student tmp, swap;
	int index;
//
	for(index = 0; students[index].id != 0 && index < MAX_STUDENT ; index++){
		if(students[index].grade > (*std).grade || students[index].grade == (*std).grade && strcmp(students[index].name,(*std).name) > 0){
			swap = students[index];
			students[index] = *std;
			*std = swap;
		}
	}
	students[index] = *std;
//	
}

void print_student(struct student students[]) {
	printf("%10s\t%10s\tGrade\n","Name","Student ID");
	for (int index=0; students[index].grade != 0 && index < MAX_STUDENT; ++index) {
		printf("%10s\t%10s\t%c\n", 
			   students[index].name, 
			   students[index].id, 
			   students[index].grade);
	}
}

float class_average(struct student students[]) {
	float avg;
	float sum = 0, count = 0;

	for(int i = 0; students[i].id != 0 && i < MAX_STUDENT; i++){
		if (students[i].grade == 'A'){
			sum += 4;
		}
		else if(students[i].grade == 'B'){
			sum += 3;
		}
		else if(students[i].grade == 'C'){
			sum += 2;
		}
		else if(students[i].grade == 'D'){
			sum += 1;
		}
		else{
			sum += 0;
		}
		count++;
	}
	return (count == 0) ? 0.0 : sum/count;;
}

char *get_word() {
	char *word = (char *) malloc(sizeof(char)*BUF);
	char c;
	int index;

	if (meetEOF) return NULL;

	while (isspace(c = getchar())) ;

	for (index=0; index < BUF; ++index) {
		if (c == EOF) {
			meetEOF = 1;
			break;
      // free(word);
      // return NULL;
		}
		if (isalnum(c))
			word[index] = c;
		else
			break;
		c = getchar();
	}
	word[index] = '\0';
	return word;
}