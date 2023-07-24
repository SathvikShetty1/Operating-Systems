#include <stdio.h>

int main() {
    int i, j, a[50], frame[10], no, k, avail, fault = 0;

    printf("\n Enter the number of pages:\n");
    scanf("%d", &no);

    printf("\n Enter the page numbers:\n");
    for (i = 0; i < no; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n Enter the number of frames:\n");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        frame[i] = -1;
    }

    j = 0;
    printf("\nPage\t  Frames\n");

    for (i = 0; i < no; i++) {
        printf("%d\t", a[i]);
        avail = 0;
        for (j = 0; j < k; j++) {
            if (frame[j] == a[i]) {
                avail = 1;
                break;
            }
        }

        if (avail == 0) {
            frame[fault % k] = a[i];
            fault++;
            for (j = 0; j < k; j++) {
                printf("%d\t", frame[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", fault);
    return 0;
}
/*
 Enter the number of pages:
7

 Enter the page numbers:
1
3
0
3
5
6
3

 Enter the number of frames:
3

Page      Frames
1       1       -1      -1
3       1       3       -1
0       1       3       0
3       5       5       3       0
6       5       6       0
3       5       6       3
Total Page Faults: 6
    */
