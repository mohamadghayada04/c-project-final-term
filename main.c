#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// COLORS
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

// STRUCT (required)
struct Question {
    char text[100];
    char a[50];
    char b[50];
    char c[50];
    char d[50];
    int correct;
    int difficulty;
};

// FUNCTION: read questions from file
void readQuestions() {
    FILE *file = fopen("questions.txt", "r");

    if (file == NULL) {
        printf("Error opening questions file!\n");
        return;
    }

    char line[256];

    printf("==== QUESTIONS ====\n\n");

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    printf("\nPress ENTER...");
    getchar(); getchar();
}

// FUNCTION: save score to file
void saveScore(int score) {
    FILE *file = fopen("leaderboard.txt", "a");

    if (file == NULL) {
        printf("Error opening leaderboard file!\n");
        return;
    }

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    fprintf(file, "%s %d\n", name, score);

    fclose(file);
}

// FUNCTION: show leaderboard
void showLeaderboard() {
    FILE *file = fopen("leaderboard.txt", "r");

    if (file == NULL) {
        printf("No leaderboard found!\n");
        return;
    }

    char line[100];

    printf("==== LEADERBOARD ====\n\n");

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    printf("\nPress ENTER...");
    getchar(); getchar();
}

// FUNCTION: start simple game
void startGame() {
    int score = 0;
    int answer;

    printf("Simple Question: What is 2+2?\n");
    printf("1. 3\n2. 4\n3. 5\n");

    printf("Choose (1-3): ");
    scanf("%d", &answer);

    // VALIDATION
    if (answer < 1 || answer > 3) {
        printf(RED "Invalid choice!\n" RESET);
        return;
    }

    if (answer == 2) {
        score += 1;
        printf(GREEN "Correct!\n" RESET);
    } else {
        printf(RED "Wrong!\n" RESET);
    }

    printf("Your score: %d\n", score);

    saveScore(score);

    printf("\nPress ENTER...");
    getchar(); getchar();
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        system("clear");

        printf("==== TRIVIA APP ====\n");
        printf("1. Start Game\n");
        printf("2. View Questions (file)\n");
        printf("3. View Leaderboard\n");
        printf("4. Exit\n");

        printf("Choose option (1-4): ");
        scanf("%d", &choice);

        // VALIDATION
        if (choice < 1 || choice > 4) {
            printf(RED "Invalid option!\n" RESET);
            getchar(); getchar();
            continue;
        }

        switch (choice) {
            case 1:
                system("clear");
                startGame();
                break;
            case 2:
                system("clear");
                readQuestions();
                break;
            case 3:
                system("clear");
                showLeaderboard();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
        }
    }

    return 0;
}
