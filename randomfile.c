#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int rand_num(){
  int random_data = open("/dev/random", O_RDONLY);
  int * p = (int *)malloc(sizeof(int));
  read(random_data, p, sizeof(p));
  int num = *p;
  free(p);
  if (close(random_data) < 0){
    printf("ERROR CLOSING FILE");
  };
  return num;
}

int main(){
  //==============CREATING ARRAYS==============
  int * arr = (int *)calloc(10, sizeof(int));
  int * arr2 = (int *)calloc(10, (sizeof(int)));

  //==============POPULATING ARRAY WITH RANDOM INTS==============
  printf("==========CONTENT OF FIRST ARRAY==========\n");
  for(int i = 0; i < 10; i++){
    arr[i] = rand_num();
    printf("arr[%d]:  %d\n", i, arr[i]);
  }
  printf("==========================================\n\n");
  
  //==============OPENING FILE==============
  int a_file = open("a_file.txt", O_RDWR | O_CREAT, 0777);

  if(a_file > 0){
    printf("file has been opened\n");
  }
  else{
    printf("error opening file\n");
  }

  //==============WRITING TO FILE==============
  int bytes_written = write(a_file, arr, 10 * sizeof(int));
  
  if(bytes_written >= 0){
    printf("file has been written\n");
    printf("bytes written: %d\n", bytes_written);
  }
  else{
    printf("error writing file\n");
  }

  //==============CLOSING FILE==============
  if(close(a_file) == 0){
    printf("file has been closed\n");
  }
  else{
    printf("error closing file\n");
  }

  
  //==============READING FROM FILE==============
  int a_file2 = open("a_file.txt", O_RDWR | O_CREAT, 0777);
  if(a_file2 > 0){
    printf("file has been opened\n");
  }
  else{
    printf("error opening file\n");
  }
  int bytes_read = read(a_file2, arr2, 10* sizeof(int));
  if(bytes_read >= 0){
    printf("file has been read\n");
    printf("bytes read: %d\n", bytes_read);
  }
  else{
    printf("error reading file\n");
  }

  //==============CLOSING FILE==============
  if(close(a_file2) == 0){
    printf("file has been closed\n");
  }
  else{
    printf("error closing file\n");
  }

  //==============VERIFY CONTENT==============
  printf("\n==========CONTENT OF ARRAYS==========\n");
  for(int i = 0; i < 10; i++){
    printf("arr[%d]:  %d\n", i, arr[i]);
    printf("arr2[%d]: %d\n\n", i, arr2[i]);
  }
  
  
  return 0;
}
 
