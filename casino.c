#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int age;

    printf("WELCOME to the CASINO \n");
    printf("RULES : \n 1. ABOVE 20 Yrs of AGE \n 2. YOUR BALANCE MUST BE GREATER THAN YOUR BID \n 3.THE NUMBER ON THE SCREEN IS GENERATED RANDOMLY \n 4.EACH TOKEN IS VALUED AT RS.1\n 5.MAINTAIN CODE OF CONDUCT \n");
    printf("\nKindly please enter your age\n");
    scanf("%d", &age);

    if (age >= 21) // age confirmation
    {
        int hb, bid, ch, ch1, ch2;
        int a, b, c;
        hb = 10000;
        int pb = 0;

        printf("Do you want to go through the gaming conditions \n 1 for yes and 0 for no \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf(" THE CONDITIONS ARE");
            printf("\n 999 : JACKPOT \n 000 : LOST COMPLETELY \n XXX : THREE TIMES BID \n AXX : TWO TIMES BID \n ALL ODD : DRAW \n ALL EVEN : DRAW \n OTHERWISE LOST YOUR BID \n");
            break;
        case 2:
            printf("OK SURE NO ISSUES");
            break;
        }
        while (1) // infinte loop
        {
            if (hb == 0) // house balance is zero
            {
                printf("\n GAME ENDS");
                break;
            }

            if (pb == 0) // player balance is zero
            {
                printf("\nYour balance is zero \n You have two options \n 1.Buy tokens \t 2.Quit Game \n");
                scanf("%d", &ch);
                int tokens, price;
                switch (ch)
                {
                case 1:

                    printf(" Enter the amount of tokens you want to buy \n");
                    scanf("%d", &tokens);
                    printf("Enter the price \n");
                    scanf("%d", &price);
                    if (price == tokens)
                    {
                        pb = tokens;
                    }
                    if (price > tokens)
                    {
                        int b1 = price - tokens;
                        printf("\n Will we convert Rs. %d to tokens or will return the amount to you \n Enter 1 to convert to token and 0 to receive change \n ", b1);
                        scanf("%d", &ch2);
                        if (ch2 == 1)
                        {
                            pb = price;
                        }
                        else
                        {
                            pb = tokens;
                        }
                    }
                    if (price < tokens)
                    {
                        int b2 = tokens - price;
                        printf("\n Please pay Rs. %d more \n Enter the overall price again correctly \n", b2);
                        scanf("%d", &price);
                        if (price == tokens)
                        {
                            pb = tokens;
                        }
                        else
                        {
                            printf("YOU ARE BREACHING OUR CODE OF CONDUCT HENCE YOU ARE NOT ALLOWED");
                            exit(0);
                        }
                    }
                    break;
                case 2:
                    printf("I will not play \n");
                    pb = 0;
                    break;
                }
                if (ch == 2)
                    break;
            }

            else if (pb > 0) // player balance is not sero
            {

                printf("Enter '1' to confirm participation otherwise 0 \n");
                scanf("%d", &ch1);

                if (ch1) // participation confirmation
                {
                    printf("ENter bid value \n"); // bid value
                    scanf("%d", &bid);

                    if (pb >= bid) // gaming conditions
                    {
                        pb = pb - bid;
                        int n;
                        a = rand();
                        a = a % 10;
                        b = rand();
                        b = b % 10;
                        c = rand();
                        c = c % 10;
                        n = a * 100 + b * 10 + c; // provided that it is a 3digit number
                        printf("\n number : %d \n", n);
                        if (n == 999) // 999
                        {
                            printf("CONGRATULATIONs FOR JACKPOT \n");
                            pb = pb + bid + hb;
                            hb = 0;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                        else if (n == 0) // 000~0
                        {
                            printf("YOU LOST COMPLETELY \n");
                            hb = hb + pb + bid;
                            pb = 0;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                        else if ((a == b == c != 9) && (a == b == c != 0)) // XXX
                        {
                            printf("THREE TIMES BID \n");
                            pb = pb + 3 * bid;
                            hb = hb - 3 * bid;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                        else if ((a == b && b != c) || (b == c && c != a) || (a == c && c != b)) // Axx
                        {
                            printf("TWO TIMES BID\n");
                            pb = pb + 2 * bid;
                            hb = hb - 2 * bid;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                        else if ((a != b != c) && (((a % 2 == 0) && (a != 0)) && ((b % 2 == 0) && (b != 0)) && ((c % 2 == 0) && (c != 0)))) // ALL DISTINCT EVEN
                        {
                            printf("DRAW \n");
                            pb = pb + bid;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                        else if ((a != b != c) && (((a % 2 != 0) && (a != 9)) && ((b % 2 != 0) && (b != 9)) && ((c % 2 != 0) && (c != 9)))) // ALL DISTINCT ODD
                        {
                            printf("DRAW \n");
                            pb = pb + bid;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }
                        else // LOST
                        {
                            printf("YOU LOST YOUR BID");
                            hb = hb + bid;
                            printf("\n Your balance is Rs %d and house balance is Rs %d \n", pb, hb);
                        }

                    } // end of game if

                    else // gaming conditions
                    {
                        printf("Your balance cannot be less than bid value \n Please retry \n");
                    }
                } // end of if(participation confirmation)

                else // Donot want to play
                {

                    break;
                }

            } // end of outermost else(player balance)

        } // end of while loop

        printf("\n House balance is Rs %d and Player balance is Rs  %d", hb, pb);
        printf("\n Thank you for visiting");

    } // end of if(age verification)

    else // end of outermost else(age verification)
    {
        printf(" \n You must be 21 yrs and above to play");
    }

    return 0;
}
/*
WELCOME to the CASINO
RULES :
 1. ABOVE 20 Yrs of AGE
 2. YOUR BALANCE MUST BE GREATER THAN YOUR BID
 3.THE NUMBER ON THE SCREEN IS GENERATED RANDOMLY
 4.EACH TOKEN IS VALUED AT RS.1
 5.MAINTAIN CODE OF CONDUCT

Kindly please enter your age
23
Do you want to go through the gaming conditions
 1 for yes and 0 for no
1
 THE CONDITIONS ARE
 999 : JACKPOT
 000 : LOST COMPLETELY
 XXX : THREE TIMES BID
 AXX : TWO TIMES BID
 ALL ODD : DRAW
 ALL EVEN : DRAW
 OTHERWISE LOST YOUR BID

Your balance is zero
 You have two options
 1.Buy tokens    2.Quit Game
1
 Enter the amount of tokens you want to buy
1000
Enter the price
2000

 Will we convert Rs 1000 to tokens or will return the amount to you
 Enter 1 to convert to token and 0 to receive change
 1
Enter '1' to confirm participation otherwise 0
1
ENter bid value
200

 number : 23
YOU LOST YOUR BID
 Your balance is Rs 1800 and house balance is Rs 10200
Enter '1' to confirm participation otherwise 0
1
ENter bid value
400

 number : 424
TWO TIMES BID

 Your balance is Rs 2200 and house balance is Rs 9400
Enter '1' to confirm participation otherwise 0
0

 House balance is Rs 9400 and Player balance is Rs 2200
 Thank you for visiting
 */