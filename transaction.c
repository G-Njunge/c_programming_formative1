#include <stdio.h>

int main(void)
{
    int user_choice;
    int acc_balance = 0;
    int valid = 0;
    int deposit_amount;


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

                    if (scanf("%d", &deposit_amount) != 1)
                    {
                        int ch;
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        printf("invalid option, amount entered must be an integer i.e 1, 10000\n");
                        continue;
                    }
                    else if (deposit_amount <= 0)
                        printf("Deposit must be greater than zero.\n");
                    else
                    {
                        acc_balance += deposit_amount;
                        printf("Succesfully deposited %d kenyan shillings to your account\n", deposit_amount);
                        printf("Your account balance is %d Ksh\n", acc_balance);
                    }
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
                printf("\ninvalid option\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                break;
        }
    }
    while (user_choice != 5);
}
