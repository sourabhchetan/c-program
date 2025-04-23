#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char ch;

    // Open the source file in read mode
    srcFile = fopen(source, "r");
    if (srcFile == NULL) {
        printf("Cannot open source file.\n");
        exit(EXIT_FAILURE);
    }

    // Open the destination file in write mode
    destFile = fopen(destination, "w");
    if (destFile == NULL) {
        fclose(srcFile);
        printf("Cannot open or create destination file.\n");
        exit(EXIT_FAILURE);
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(srcFile);
    fclose(destFile);
}

int main() {
    char sourceFile[100], destFile[100];

    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    printf("Enter the destination file name: ");
    scanf("%s", destFile);

    copyFile(sourceFile, destFile);

    return 0;
}
