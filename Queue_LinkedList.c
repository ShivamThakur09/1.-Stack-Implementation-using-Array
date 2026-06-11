    #include<stdio.h>
    #include<stdlib.h>

    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *front=0;
    struct Node *rear=0;

    int isEmpty(){
        if(front == 0 && rear == 0){
            return 1;
        }
        return 0;
    }

    int isFull(){
        return 0;
    }

    void enqueue(int x){
        struct Node *newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode == 0){
            printf("Queue is full.\n");
            return;
        }
        newnode -> data = x;
        newnode -> next = 0;

        if(isEmpty()){
            front = rear = newnode;
        }
        else{
            rear -> next = newnode;
            rear = newnode;
        }
    }

    void dequeue(){
        struct Node *temp;
        temp=front;

        if(isEmpty()){
            printf("Queue is empty.\n");
        }
        else{
            printf("Dequeue : %d\n", front -> data);
            front = front -> next;
            free(temp);
        }
    }

    void peek(){
        if(isEmpty()){
            printf("Queue is Empty.\n");
        }
        else{
            printf("Peek : %d\n", front -> data);
        }
    }

    void display(){
        struct Node *temp;
        temp=front;

        if(isEmpty()){
            printf("Queue is Empty.\n");
        }
        else{
            printf("Queue Elements :\n");
            while(temp != 0){
                printf("%d\n", temp -> data);
                temp = temp -> next;
            }
        }
    }

    int main(){
        int choice, x;
        while(1){
            printf("\n1. Enqueue  2. Dequeue  3. Peek  4. Display  5. Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("Enter the element to enqueue : ");
                    scanf("%d", &x);
                    enqueue(x);
                    break;  
                case 2:
                    dequeue();
                    break;
                case 3:
                    peek();
                    break;
                case 4:                
                    display();
                    break;
                case 5:                
                    exit(0);
                default:
                        printf("Invalid choice.\n");
            }   
        }
        return 0;
    }