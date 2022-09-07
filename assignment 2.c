/*Assignment 2
This program is a basic lottery game.
1. Enter any 6 numbers (1–42 inclusive) from the keyboard. Perform any necessary validation (error-checking) required (e.g., all numbers must be
different, range 1–42, etc.).
2. Display the contents of the 1-D array containing your lotto numbers that you entered.
3. Sort the contents of the array in increasing order (i.e., 1st element = smallest number, 2nd element = 2nd smallest number, etc.). You may use any sortingn algorithm of your choice.
4. Compare your chosen lotto numbers in the 1-D array with the following winning numbers: 1,3,5,7,9,11 (Winning numbers)
5.Display the frequency of the numbers entered each time the user enters a new set of numbers (without exiting the program) on the screen. For example, it might display:
number 1 has been selected x times, number 7 has been selected x times ,number 28 has been selected x times.
6. Exit program the program gracefully.
Author: Hadassah Joseph
Date: March 2021
*/

#include <stdio.h>

//Symbolic Names
#define SIZE 42// The size of the lotto game
#define LOTTO 6 // This while be used in the function to compare the lotto numbers
#define SELECTED 6 // This is for part 1, part 2,part 3

//Function Signatures
void option1(int* , int*);//{Function 1}To store the numbers into an array to be passed to option2 and option 3
void option2(int*);//{Function 2}To display the numbers stored in array SELECTED  
void option3(int*);//{Function 3}To sort the numbers stored in array SELECTED
void option4(int*,int*);//{Function 4} To compare the numbers stored in array SELECTED against 
void option5(int*);

int main()
{
   int menu_choice;
   char sure;
   int values[SELECTED]; // user input to be stored in this array
   int array [] = {1,3,5,7,9,11};//part4 function uses this array to compare against SELECTED
   int frequency[SIZE+1]={0};   // The frequency 
   int option_1=0;  //to check if option 2 was choosen first 
   int option_2=0;  //to check if option 2 was choosen first 
   int option_3=0;  //to check if option 3 was choosen first 
   int option_4=0;  //to check if option 4 was choosen first 
   int option_5=0;  //to check if option 5 was choosen first 
  
 
    do
    {
        
        //printf("-------------------------------------------------------------------------\n"); 
        printf("\n     ----------------------LOTTERY-----------------------------\n");
        printf("\n              Select an option from below\n");
        printf("\n1.Enter any 6 numbers (1-42 inclusive)\n");
        printf("\n2.To display the numbers entered\n");
        printf("\n3.To display the numbers entered in inreasing order\n");
        printf("\n4.Compare numbers entered with winning numbers\n");
        printf("\n5.Display frequency of numbers entered in current program run\n");
        printf("\n6.End Program\n");
        printf("-------------------------------------------------------------------------\n"); 
        printf("\n");
        //collecting the users data and choices 
        scanf("%1d", &menu_choice);
         
               
        //checking the users choice 
        //These are going to be calling the function
        switch(menu_choice)
        {
            //if user selects choice 1 from the main menu
            
            case 1:
            {
             //entered 6 number check yes or no are they sure they want to enter these numbers

              if (menu_choice == 1 )
              {
                        //The numbers are stored in a 1-D array
                    printf("\n1.) Enter six different numbers to play the Lotto\n");
                    printf("\nPlease enter six different numbers \n");
                    
                    option1(values,frequency);//the numbers will be stored in both values[SELECTED] 
                    // and frequency so that it can be counted to see how many time it is used in a running program

                    /*To make sure that user does not pick option2/option3/option4/option5 first 
                    it increments option2/option3/option4/option5 which have all been equaled to 0 
                    after option 1 has been excuted therefore if option1 is exucted option2 can be excuted
                    but if option1 has not been excuted option2 cannot be excuted aswell. */
                    option_2++;
                    option_3++;
                    option_4++;
                    option_5++;

                }//end if   

            }//end case 1
            break;

            //if user selects choice 2 from the main menu
            case 2:
            {
                //to display the numbers of the code

                if (menu_choice == 2 && option_2>0)
                //option 2 can not be excuted if it is less that zero as option 1 has not been exctecuted
                {
                    printf("\n The six numbers you have selected are \n");
                    option2(values);

                }//end if
                else
                {
                printf("\nERROR! you cannot pick option b in your first try\n");
                printf("\nPlease pick option a to input your 6 selected numbers\n");

                }//end else
           
            }//end case 2
            break;

            case 3:
            {
                //Displaying the numbers entered by the user from smallest to largest 
                // using a sorting algorithm 
                //I am using selection sort as taught in algothrim and desgin class

                if(menu_choice == 3 && option_3>0)
                {
                    printf("\nThe sorted numbers are:\n");
                    option3(values);
                    
                }//end if
                else
                {
                    printf("\nERROR! you cannot pick option 3 in your first try\n");
                    printf("\nPlease pick option a to input your 6 selected numbers\n");

                }//end else

            }//end case 3
            break;

            case 4:
            {
                //comparing the numbers entered againest the winning numbers
                 if(menu_choice == 4 && option_4>0)
                {
                     printf("\n");
                    printf("\n---------------------------------------------------\n");
                    printf("\n| Six matches = JACKPOT!                          |\n");
                    printf("\n| 5 matches = New Car                             |\n");
                    printf("\n| 4 matches = Weekend away                        |\n");
                    printf("\n| 3 matches  = a Cinema Pass                      |\n");
                    printf("\n| No matches = No prize                           |\n");
                    printf("\n---------------------------------------------------\n");
                    printf("\n");
                    option4(values,array);
                }//end if
                else
                {
                    printf("\nERROR! you cannot pick option 4 in your first try\n");
                    printf("\nPlease pick option a to input your 6 selected numbers\n");
                }
            }//end case 4
            break;

            case 5:
            {
                //Displaying the numbers entered by the users and the amount of times they have entered them
                 if(menu_choice == 5 && option_5>0)
                {
                    printf("\nYou have entered the same numbers:\n");
                    option5(frequency);
                    
                }//end if
                else
                {
                    printf("\nERROR! you cannot pick option 4 in your first try\n");
                    printf("\nPlease pick option a to input your 6 selected numbers\n");
                }
            }//end case 5
            break;

           case 6:
            {
                if (menu_choice == 6 )
                {
                //Ending the program gracefully asking (y/n)
                printf("\nAre you sure? (y/n)\n");
                scanf("%1s", &sure);
              
                menu_choice = sure;
                  getchar(); 
                }//end if
               
            }//end case 6
             break;

 //To handle any invalid inputs entered in the main menu
 /*But unfoutntaly i could not get it to work for charcters i know i should have changed my menu_choice to a char 
 and placed %1s to chatch these errors but unfortunatly every time i did so more errors would occur  therefore tihs 
 default only works with numbers. */

            default:
           {
                printf("\n An Invaild option was entered. Enter agian\n ");
            
           }//end default 
    
        } //end switch

    } //end do
    while ( menu_choice != 'y');
    printf("\nGoodbye Thanks for playing the game ");
  return 0;
  
}//end main


//FUNCTIONS 
/*
This is for part1 the function will reead the 6 lotto numbers that the user picks.
* figures are the numbers that the user have entered into the lotto
*freq pointer show how many times a particular number in the lotto has been entered in to the
 same runing quize until it has be terminated
*/

void option1(int* figures, int*freq)
{
    int i,j;
    int temp; // a temporary variable to hold each number inputted

    for(i=0; i<SELECTED; i++)
    {
        scanf("%d", & *(figures + i));
         // is the users input in the range of 1 - 42 
        if (*(figures + i) >= 1 && *(figures + i) <= 42)
        {
            //this checks if the user inputs the same number inside the array  as the user should enter different numbers
            for(j=0; j < i;j++)
            {
                if(*(figures +i) == *(figures +j))
                {
                    printf("You cannot enter the same number");
                    printf("The game will restart");
                    return; //it returns back to the menu if the user inputs the same number
                }//end inner if
            }//end inner for loop for checking
        }//end if

        // the else statement confirms that the  numbers are not outside the range of 1 - 42 
        else
        {
            printf("You must enter numbers within the range of 1-42\n");
            printf("The program will restart \n");
            printf("\n"); 
            break; /*allows the function to be executed again until user inputs correct numbers */
        }//end else

        temp= *(figures +i);//This transfers the number the user inputted  into its respective array
        *(freq +temp) = *(freq +temp) +1;//they are incremented to calculate how many times a user enteres a certain number during a round of a game
          
    }//end for

}//end part 1 function {6 lotto numbers}

/*
This function displays the lotto numbers inputted by the user
*/
void option2(int *display)
{
    int i;
    
    for(i=0; i<SELECTED; i++)
    {
        printf(" %d,\n", *(display + i));
        //this prints out the numbers stored in the array 
    }//end for
    
}//end function 2 {display}

/*This function sorts the 6 lotto numbers in ascending order using a selction sort taught in algorithm and design */
void option3(int*sorting)
{
    int min; //finds the smallest number in the array
    int temp; //it a tempoary variable to swap the numbers
    int i,j;

    for(i=0; i<SELECTED-1; i++)
    {
        min=i;
        for(j=i+1; j<SELECTED; j++)
        {
            if(sorting[j]<sorting[min])
            {
                min=j;
            }//end if
        }//end inner for
        temp = sorting[min];
        sorting[min]=sorting[i];
        sorting[i]=temp;
    }//end for
 
    for(i=0; i<SELECTED; i++)
    {
        printf("%d, ", *(sorting + i)); //it aranges the numbers in ascending ordwe
    }//end for
    
}//end function 3 {sorting}


//this is used to compare the numbers agianst the winning numbers of the game 
void option4 (int*compare,int*figures)
{
    int same=0
    int i,j;

 for(i=0; i<LOTTO; i++)
    {
        for(j=0;j<LOTTO;j++)
        {
            //to check if the users input matches with the winning numbers
            if(*(compare +j) == *(figures + i))
            {
                same++;
                printf("The matching numbers are: winning number %d and your number %d \n",*(compare + j),*(figures + i));
            }//end if
        }//end inner for 
        
    }//end for
    
    /*These determines if the user wins anything */
    
    if(same == 6)
    {
        printf("Jackpot!");
    }//end if
    else if(same == 5)
    {
        printf("You have won a new car :)");
    }//end else if
    else if(same == 4)
    {
        printf("You are going on a weekend away to ibiza!");
    }//end else if 
    else if (same == 3)
    {
        printf("You just won a cinema pass to see batman wnich is starring Zoé kraitz and Robbert Patterson");
    }//end else if
    else if(same == 2 || same == 1 )
    {
        printf("):You did not win anything ");
    }//end else if
    else if(same!=6 && same!=5 && same!=4 && same!=3)
    {
        printf("You did not get any of the match numbers so no prizes and no hints sorry ):");
    }//end else if 

}//end function 4 {comparing}


//This checks how many times the numbers the user inputs have occured in a current running game
void option5(int*frequency)
{

    int i;

    for(i=0; i<SIZE+1; i++)
        {
            //This shows how many times a certain number has been entered into a current running game
            if(*(frequency + i) != 0)
            {
                printf("Number %d has been selected %d times \n",i,*(frequency +i));
            }//end if

        }//end for
  
}// end function 5 {frequency}