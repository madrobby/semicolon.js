#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s [-js|-cs] FILE\n", argv[0]);
    return 1;
  }

  unsigned char javascript = 0;
  if (strcmp(argv[1], "-js") == 0) {
    javascript = 1;
  }

  char *source_file = argv[2];

  FILE *file = fopen(source_file, "r");
  if (file != NULL) {
    unsigned char comment = 0;
    while (1) {
      char c = fgetc(file);
      if (c == EOF) {
        break;
      }
      switch (c) {
        // This is where the language translation magic happens.
        case ';':
          if (!comment) {
            if (javascript) {
              // JavaScript translation.
              putc(';', stdout);
            } else {
              // CoffeeScript translation.
            }
          }
          break;

        // Pass-through new-lines, unless in a comment.
        case '\n':
          if (!comment) {
            putc('\n', stdout);
          }
          comment = 0;
          break;

        // Comment, ignore the rest of the line.
        case '#':
          comment = 1;
          break;
      }
    }
    fclose(file);
  } else {
    printf("Unable to read semiscript source file `%s'.\n", source_file);
    return 1;
  }

  return 0;
}
