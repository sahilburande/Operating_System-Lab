#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, capacity, page_faults = 0, front = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the page reference string (separated by space): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }


    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    int frames[capacity];
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("\nExecution Steps:\n");
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }


            frames[front] = pages[i];
            front = (front + 1) % capacity;
            page_faults++;

            printf("Page %d -> [", pages[i]);
            for (int j = 0; j < capacity; j++) {
                if (frames[j] != -1) printf(" %d ", frames[j]);
                else printf(" - ");
            }
            printf("] (Fault)\n");
        } else {
            printf("Page %d -> [ Hit ]\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}

