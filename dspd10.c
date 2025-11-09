#include <stdio.h>

int main() {
    char inputFile[100], outputFile[100];
    FILE *source, *destination;
    char ch;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    source = fopen(inputFile, "r");
    if (source == NULL) {
        printf("Error: Cannot open input file %s\n", inputFile);
        return 1;
    }

    destination = fopen(outputFile, "w");
    if (destination == NULL) {
        printf("Error: Cannot create output file %s\n", outputFile);
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully from %s to %s.\n", inputFile, outputFile);

    fclose(source);
    fclose(destination);

    return 0;
}
