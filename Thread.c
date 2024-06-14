#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void tugas(int id, int durasi) {
  printf("Tugas %d dimulai, akan memakan waktu %d detik.\n", id, durasi);
  sleep(durasi);
  printf("Tugas %d selesai.\n", id);
}

int main() {
  pid_t pid1, pid2, pid3;

  // Jalankan tugas secara paralel
  pid1 = fork();
  if (pid1 == 0) {
    tugas(1, 3);
    exit(0);
  }

  pid2 = fork();
  if (pid2 == 0) {
    tugas(2, 5);
    exit(0);
  }

  pid3 = fork();
  if (pid3 == 0) {
    tugas(3, 2);
    exit(0);
  }

  // Tunggu semua tugas selesai
  wait(NULL);
  wait(NULL);
  wait(NULL);

  printf("Semua tugas selesai.\n");

  return 0;
}