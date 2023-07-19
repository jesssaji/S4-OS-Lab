#include<stdio.h>
#include<math.h>

int DiskScheduling_CSCAN(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0;
    int small=totalTrack;
    int difference = totalTrack;
    int nearest=0;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
        if(abs(head-rq[i]) < difference)
        {
            difference = abs(head-rq[i]);
            nearest = rq[i];
        }
            
    }
    trackMovement = abs(totalTrack-head) + abs(totalTrack-0) + abs(nearest - 0);
    return trackMovement;
}

int main()
{
    printf("\nDISK SCEDULING USING C-SCAN\n\n");
    int n, requestQueue[200], head, totalTrack;
    printf("Enter the number of tracks present in request queue: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter track number %d: ", i+1);
        scanf("%d", &requestQueue[i]);
    }
    printf("\nEnter the total number of tracks in the disk: ");
    scanf("%d", &totalTrack);
    printf("Enter the current position of R/W head: ");
    scanf("%d", &head);
    int trackMovement = DiskScheduling_CSCAN(requestQueue, n, head, totalTrack-1);
    printf("The total number of track movement using C-SCAN is: %d", trackMovement);
}