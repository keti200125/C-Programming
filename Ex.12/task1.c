// Команден интерпретатор /КИ/ - реализация на канал между две команди / | /.

//NOT DONE, work on it

char buff[20];
char cmd1[20];
char cmd2[20];
int i = 0;
bool flag = false;
bool flag2 = false;

int main(int argc, char *argv[]) {

  while (1) {
    write(1, "007>", 4);

    // четем команда символ по символ и я записваме в cmd
    while (read(0, &buff[i], 1) > 0 && buff[i] != '\n' && buff[i] != '|') {
      if (buff[i] == ' ') {
        continue;
      } else {
        i++;
      }
    }

    if (buff[i] == '|') {
      buff[i] = '\0';
      strcpy(cmd2, buff);
      flag = true;
      i = 0;
    }

    if (buff[i] == '\n') {
      buff[i] = '\0';
      strcpy(cmd2, buff);
      flag2 = true;
      i = 0;
    }

    if (strcmp(buff, "quit") == 0) {
      exit(0);
    } else if (flag && flag2) {
      if (fork()) {
        wait(NULL);
        i = 0;
      } else {
        int fd[2];
        pipe(fd);

        if (fork()) {
          close(fd[1]);
          close(0);
          dup(fd[0]);
          close(fd[0]);
          if (execlp(cmd2, cmd2, 0) == -1) {
            exit(1);
          }
        } else {
          close(fd[0]);
          close(1);
          dup(fd[1]);
          close(fd[1]);
          if (execlp(cmd1, cmd1, 0) == -1) {
            exit(1);
          }
        }
      }
    } else if (flag == false && flag2 == true) {
      execvp(buff, &buff);
    }
  }
}
