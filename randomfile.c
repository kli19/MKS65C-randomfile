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

  printf("%d\n", rand_num());
  

  return 0;
}
 
