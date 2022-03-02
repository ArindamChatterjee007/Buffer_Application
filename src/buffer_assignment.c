#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static char usr_manged_ram_buffer[5][1024]={
			"One",
			"Two",
			"Three",
			"Four",
			"Five",
};

void test_buffer_manager(){
	
	
	printf("Size of the buffer : %d\n ",sizeof(usr_manged_ram_buffer));
	
	format_buffer(usr_manged_ram_buffer);
	
	
	buffer_compaction(usr_manged_ram_buffer);
	printf("\n--------Resizing complete--------\n");
	
	
	printf("\nEnter the String : ");
	scanf("%s",&usr_manged_ram_buffer);
	
	
	
	printf("\n%s",malloc(usr_manged_ram_buffer));
	
	printf("\nAllocated buffer : ");
	char* ptr = malloc((5 * 1024) * sizeof(char));
	
	printf("%d",ptr);
	printf("\nBuffer location is : %d\n",*ptr);
	printf("\n -------Free the buffer-------- \n");
	
	free(usr_manged_ram_buffer);
	printf("buffer free");
	
	
}


void format_buffer(void){
	printf("\nFormating the Buffer...\nPlease type enter...\n");
	while(getchar() !='\n');
	printf("\n-------Format complete-------\n");
}

void buffer_compaction(char **buffer)
{
	printf("\n\nResizing The buffer...\nPlease type enter...\n");
	
	char *newBuffer;
unsigned char i = 0;
unsigned char size = 1;
*buffer = malloc(16);
(*buffer)[0] = 0;
while (1) {
    (*buffer)[i] = getchar();
    if ((*buffer)[i] == '\n') {
        (*buffer)[i] = 0;
        return;
    }
    if (i >= (size * 16)) {
        size++;
        newBuffer = realloc(*buffer, size * 16);
        *buffer = newBuffer;
    }
    i++;
}

//printf("now size of the buffer is %d",sizeof(buffer));
}
int main(){
	printf("%c",usr_manged_ram_buffer[5][1024]);
	test_buffer_manager();
	return 0;
}
