/* A program written to solve the problem presented at: 
http://www.reddit.com/r/dailyprogrammer/comments/1iambu/071513_challenge_133_easy_foottraffic_analysis/ 
The brief of the challenge was to write a program that could take a data file that described the foot-traffic at 
and art gallery and provide a summation of said data.
The file was presented in the format of:
<number of data lines> \n
<visitor ID> <room ID> <whether the visitor is exiting or entering the room> <at what time this event occured>

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXROOMS 100
#define MAXVISITORS 1024

typedef struct{
    int total_visitors;
    int average_visit;
} room_t;

typedef struct{
    int time;
    int prev_time;
} person_t;

int main(int argc, char *argv[])
{
    int data_lines, visitor_id, room_id,i, j, k, t;
    char in_out = 'b';
    room_t allrooms[MAXROOMS];
    person_t allpeople[MAXVISITORS];
    scanf("%d\n", &data_lines);
    
    for(k = 0; k < MAXROOMS; k++)
    {
        allrooms[k].total_visitors = 0;
        allrooms[k].average_visit = 0;
    } 
    
    for(i = 0; i < data_lines; i++)
    {
      
        scanf("%d %d %c %d\n", &visitor_id, &room_id, &in_out, 
            &t);
        allpeople[visitor_id].time = t;
	    
        if(in_out == 'O')
        {
            allrooms[room_id].average_visit += allpeople[visitor_id].time -
            allpeople[visitor_id].prev_time;
            allrooms[room_id].total_visitors += 1;
        }
	    
        allpeople[visitor_id].prev_time = allpeople[visitor_id].time;
	    
    }
    for(j = 0; j < MAXROOMS; j++)
    {
        if(allrooms[j].total_visitors != 0)
        {
            printf("Room %d, %.2f minute average visit, %d visitor(s) total\n",
                j, 1.0*allrooms[j].average_visit/allrooms[j].total_visitors,
                allrooms[j].total_visitors);
        }
    } 
    return 0;
}

