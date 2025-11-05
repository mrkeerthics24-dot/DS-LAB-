#include <stdio.h>
#define max 50

int queue_array[max];
int rear = -1;
int front = -1;

void display() {
int i;
if (front == -1) {
printf("Queue is empty\n");
} else {
i = front;
while (1) {
printf("%d ", queue_array[i]);
if (i == rear)
break;
i = (i + 1) % max;
}
printf("\n");
}
}

void insert() {
int item;
if ((rear + 1) % max == front) {
printf("Queue overflow\n");
return;
} else {
printf("Insert the element in queue: ");
scanf("%d", &item);
if (front == -1) {
front = 0;
rear = 0;
} else {
rear = (rear + 1) % max;
}
queue_array[rear] = item;
}
}

void delete() {
if (front == -1) {
printf("Queue underflow\n");
return;
} else {
printf("Deleted element is: %d\n", queue_array[front]);
if (front == rear) {
front = -1;
rear = -1;
} else {
front = (front + 1) % max;
}
}
}

int main() {
int choice;
while (1) {
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice\n");
}
}
}
