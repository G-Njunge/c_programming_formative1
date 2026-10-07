#include <stdio.h>
#include <string.h>

int user_choice;
int acc_balance = 0;
int deposit_amount;
int withdraw_amount;
int dep_count = 0;
int withdraw_count = 0;

void calc(int,int);
int main(void)
{



    do
    {
        printf("\n\nMOBILE MONEY TRANSACTION SYSTEM\n\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n\n");
        printf("Enter choice: ");

        int menu_read = scanf("%d", &user_choice);

        if (menu_read == EOF)
        {
            printf("\nInput ended. System terminated.\n");
            break;
        }

        if (menu_read != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("\ninvalid option, please enter a number from 1 to 5\n");
            continue;
        }


        switch (user_choice){
            case 1:
                printf("Enter amount to deposit: ");
                calc(user_choice, deposit_amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                calc(user_choice, withdraw_amount);
                break;
            case 3:
                printf("Your account balance is: %d\n", acc_balance);
                break;
            case 4:
                printf("You have made %d deposits\n", dep_count);
                printf("You have made %d withdrawals\n", withdraw_count);
                break;
            case 5:
                printf("Thank you for using our services!\n");
                break;
            default:
                printf("\ninvalid option\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
        }
    }
    while (user_choice != 5);

    return 0;
}

void calc(int choice, int amount)
{
    char transaction[10];
    if (choice == 1)
        strcpy(transaction,"deposited");
    if (choice == 2)
        strcpy(transaction,"withdrawn");
    if (scanf("%d", &amount) != 1)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("invalid option, amount entered must be an integer i.e 1, 10000\n");
    }
    else if (amount <= 0)
        printf("Amount must be greater than zero.\n");
    else
    {
        if (choice == 1)
        {
            acc_balance += amount;
            dep_count++;
        }
        if (choice == 2)
        {
            if (acc_balance >= amount)
            {
                acc_balance -= amount;
                withdraw_count ++;
            }
            else
            {
                printf("Transaction rejected: insufficient balance to withdraw %d, your current balance is %d\n", amount, acc_balance);
                return;
            }
        }
        printf("Successfully %s %d RWF \n", transaction, amount);
        printf("Your account balance is %d RWF\n", acc_balance);
    }
}