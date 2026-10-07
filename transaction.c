#include <stdio.h>

int main(void)
{
    int user_choice;
    int acc_balance = 0;
    do
    {
        printf("\n\nMOBILE MONEY TRANSACTION SYSTEM\n\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &user_choice);


        switch (user_choice){
            case 1:
                printf("Enter amount to deposit: ");
                int deposit_amount;
                scanf("%d", &deposit_amount);
                acc_balance += deposit_amount;
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                int withdraw_amount;
                scanf("%d", &withdraw_amount);
                if (withdraw_amount <= acc_balance)
                    acc_balance -= withdraw_amount;
                // else
                //     continue;
                break;
            case 3:
                printf("Your account balance is: %d\n", acc_balance);
                break;
            case 4:
                printf("You have made transactions");
                break;
            case 5:
                printf("Thank you for using our services!\n");
                break;
            default:
                printf("invalid option\n");
                break;
        }
    }
    while (user_choice != 5);
}
