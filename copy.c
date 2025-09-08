#include <stdio.h>

int main(void) {
    FILE *input_file, *output_file;
    int c;
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {

        fprintf(stderr, "Can't open %s.\n", input_filename);
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {

        fprintf(stderr, "Can't open %s.\n", output_filename);
        fclose(input_file);
        return 1;
    }

    while ((c = fgetc(input_file)) != EOF)
        fputc(c, output_file);

    if (!feof(input_file)) {

        fprintf(stderr, "An error occurred reading %s.\n", input_filename);
        fclose(input_file);
        fclose(output_file);
        
        return 1;
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
