/* A simple program is used to run simulations of projected returns
for a casino game in which a card is drawn and two dice are rolled. 
If the total is 21 the user wins $20 if the total is 20 and the card is a heart
the user wins $10
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DRAND 6
#define CRAND 14
#define SRAND 4
#define RVAL 11
#define SEED 1234567
#define MAXCASES 100000

int main(int argc, char *argv[])
{
    int dice1,dice2, cardval, suitval,i;
    int tenwin =0, twentywin= 0;
    double avret = 0;
    srand(SEED);
    for(i = 0; i < MAXCASES; i++)
    {
      dice1 = rand()%DRAND+ 1;
      dice2 = rand()%DRAND + 1;
      cardval = rand()%CRAND +1;
      suitval = rand()%SRAND + 1;
      /*Accomodating for what will happen if the drawn card is a royal or ace */
      if(11<= cardval)
      {
        cardval = RVAL;
      }    
     
      /*first calculating the outcome */
	    if(dice1+dice2+cardval == 21)
	    {
	        twentywin++;
	    }

      if(dice1+dice2+cardval == 20 && suitval == 1)
      {
        tenwin++;
      }
    }   
    avret = (2*MAXCASES - (10.0*tenwin + 20.0*twentywin))/MAXCASES;
    printf("The average return is $%.2f per $2 bet\n", avret);
	return 0;
}
