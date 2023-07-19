#include<stdio.h>
#include<math.h>

int DiskScheduling_SCAN(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0;
    int small=totalTrack;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
    }
    trackMovement = abs(totalTrack-head) + abs(totalTrack-small);
    return trackMovement;
}

int main()
{
    printf("\nDISK SCEDULING USING SCAN\n\n");
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
    printf("\nEnter the current position of R/W head: ");
    scanf("%d", &head);
    int trackMovement = DiskScheduling_SCAN(requestQueue, n, head, totalTrack-1);
    printf("\nThe total number of track movement using SCAN is: %d", trackMovement);
}