/* Following on from the traffic_analyse program, this program has been written for the next challenge as presented at:
http://www.reddit.com/r/dailyprogrammer/comments/1ihm0q/071713_challenge_130_intermediate_foottraffic/
The brief of the challenge was to write a program that, given relevent data, could generate a file detailing
the foot traffic through the art gallery with the intention of this file being able to be read by the traffic_analyse 
program.
The inputted data is of the following form:
<number of events> <number of people> <number of rooms> <earliest possible event> <last possible event>

#include <stdio.h>
#include <stdlib.h>

#define SEED 1234567

typedef struct{
    int roomnum;
    int time;
    char roomstate;
} person_t;

void clearrooms(person_t allpeople[], int people, int end);



int main(int argc, char *argv[])
{
    
    srand(SEED);
    int events, visitors, rooms, start, end, i, j, current_person;
    int time_diff, add_time, in_room = 0;
  scanf("%d %d %d %d %d", &events, &visitors, &rooms, &start, &end);
	events = events * 2;
	printf("%d\n", events );
	person_t allpeople[events];
	for(i = 0; i < events; i++)
	{
	    allpeople[i].roomnum = 0;
	    allpeople[i].roomstate = 'O';
	    allpeople[i].time = start;
	}
	
	for(j = 0; j < events; j++)
	{
	    current_person = rand()%visitors;
	    if(allpeople[current_person].roomstate == 'I')
	    {
	        in_room -= 1;
	        allpeople[current_person].roomstate = 'O';
	        time_diff = end - allpeople[current_person].time;
	        add_time = rand()%time_diff;
	        allpeople[current_person].time += add_time;
	        printf("%.2d    | %.2d    | %.2c    | %.2d\n", current_person, 
	            allpeople[current_person].roomnum, 
	            allpeople[current_person].roomstate, 
	            allpeople[current_person].time);
	        continue;
	    }
	    
	    if(allpeople[current_person].roomstate == 'O')
	    {
	        in_room += 1;
	        allpeople[current_person].roomnum = rand()%rooms;
	        allpeople[current_person].roomstate = 'I';
	        time_diff = end - allpeople[current_person].time;
	        add_time = rand()%time_diff;
	        allpeople[current_person].time += add_time;
	        printf("%.2d    | %.2d    | %.2c    | %.2d\n", current_person, 
	            allpeople[current_person].roomnum,
	            allpeople[current_person].roomstate, 
	            allpeople[current_person].time);
	        continue;
	    }
	    
	    if(in_room == events - j)
	    {
	        clearrooms(allpeople, visitors, end);
	        return 0;
	    }
	}
	
	
	return 0;
}

void clearrooms(person_t allpeople[], int visitors, int end)
{
    int k, time_diff, add_time;
    for(k = 0; k < visitors; k++)
    {
        if(allpeople[k].roomstate == 'I')
        {
            allpeople[k].roomstate = 'O';
	        time_diff = end - allpeople[k].time;
	        add_time = rand()%time_diff;
	        allpeople[k].time += add_time;
	        printf("%.2d    | %.2d    | %.2c    | %.2d\n", k, 
	            allpeople[k].roomnum,
	            allpeople[k].roomstate, 
	            allpeople[k].time);
	    }
	}
}
