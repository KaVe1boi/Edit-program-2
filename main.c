#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

// ANSI-escape-koder for farver
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Deklaration af funktioner
void editFileContents(const char *filename);
void displayFileContents(const char *filename);
int createFile(const char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Velkommen til filhåndteringsprogrammet.\n");

    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf(ANSI_COLOR_BLUE "1. Vis fil\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "2. Rediger fil\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "3. Opret fil\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "4. Afslut\n" ANSI_COLOR_RESET);
        printf("Valg: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFileContents(filename);
                break;
            case 2:
                editFileContents(filename);
                break;
            case 3:
                printf("Indtast filnavn: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 4:
                printf("Afslutter...\n");
                return 0;
            default:
                printf("Ugyldigt valg. Prøv igen.\n");
        }
    }
    return 0;
}
