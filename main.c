#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int randNum(){
  int file2 =  open("/dev/random", O_RDONLY);
  int x;
  read(file2,&x, sizeof(int));
  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }
  close(file2);
  return x;
}

int main(){

  printf("Generating random numbers:\n");
  int x;
  int arr[10];
  for (x = 0; x < 10; x++){
    arr[x] = randNum();
    printf("random %d: %d\n", x, arr[x]);
  }

  printf("\nWriting numbers to file...\n\n");
  int file = open("random.txt", O_RDWR|O_CREAT, 0666);
  write(file, arr, sizeof(arr));
  close(file);
  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }

  close(file);

  // printf("\nReading numbers from file...\n\n");
  // int arr2[10];
  // int file1 = open("random.txt", O_RDONLY);
  // read("random.txt", &arr2, sizeof(arr2));

}
