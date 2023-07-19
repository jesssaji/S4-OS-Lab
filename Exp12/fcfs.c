#include<stdio.h>
#include<math.h>

int DiskScheduling_FCFS(int rq[], int n, int head)
{
    int trackMovement=0;
    trackMovement = abs(head - rq[0]);
    for(int i=0; i<n-1; i++)
    {
        trackMovement += abs(rq[i]-rq[i+1]);
    }
    return trackMovement;
}

void main()
{
    printf("\nDISK SCEDULING USING FCFS\n\n");
    int n, requestQueue[200], head;
    printf("Enter the number of tracks present in request queue: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter track number %d: ", i+1);
        scanf("%d", &requestQueue[i]);
    }
    printf("Enter the current position of R/W head: ");
    scanf("%d", &head);
    int trackMovement = DiskScheduling_FCFS(requestQueue, n, head);
    printf("The total number of track movement using FCFS is: %d", trackMovement);
}