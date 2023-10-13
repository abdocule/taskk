#include <stdio.h>
#include <string.h>

struct User
{
    char username[50];
    char password[50];
};

void registerUser(struct User users[], int *userCount)
{
    struct User newUser;
    printf(" username please: ");
    scanf("%s", newUser.username);
    printf(" password please: ");
    scanf("%s", newUser.password);

    users[*userCount] = newUser;
    (*userCount)++;
    printf("Your registeration  successfully\n");
}

int loginUser(struct User users[], int userCount, char username[], char password[])
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct User users[100];
    int userCount = 0;
    int loggedIn = 0;
    char currentUser[50];

    int choice;
    do
    {
        printf("\n1.Register-----2.Login------3.Exit---- \nEnter your num: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (userCount < 100)
            {
                registerUser(users, &userCount);
            }
            else
            {
                printf("Maximum number of users reached.\n");
            }
            break;
        case 2:
            if (loggedIn)
            {
                printf("You are already logged in as %s.\n", currentUser);
            }
            else
            {
                char username[50];
                char password[50];
                printf(" username please: ");
                scanf("%s", username);
                printf(" password please: ");
                scanf("%s", password);

                if (loginUser(users, userCount, username, password))
                {
                    loggedIn = 1;
                    strcpy(currentUser, username);
                    printf("Login successful!\n");
                }
                else
                {
                    printf("Login failed.\n");
                }
            }
            break;
        case 3:
            printf("Exiting the program.\n");
            break;

        default:
            printf("erorr. Please try again.\n");
        }
    }
    while (choice != 3);

    return 0;
}

  
  
  