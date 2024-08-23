#include<iostream>
#define SIZE 52
using namespace std;

class Queue{
    int q[SIZE];
    int front,rear;

    public:
        Queue(){
            front=-1;
            rear=-1;
        }

        void insert(int num)
        {
            if (rear == SIZE-1)
            {
                cout<<"Queue is Full";
            }
            else{
                rear++;
                q[rear] = num;
                if(front == -1){
                    front = 0;
                }
            }
        }
            //remove function will return -1 if queue is empty
            // remove deleted element if data is present
            int remove()
            {
                int num;
                if(front == -1)
                {
                    return -1; //when queue is empty
                }
                else
                {
                    num = q[front];
                    if(front == rear){
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front++;
                    }
                    return num;
                }
            }
            void display(){
                int i;
                for(i=front;i<=rear;i++){
                    cout<<" "<<q[i];
                }
            }
        
};

int main()
{
    Queue masterDeck;
    Queue playerADeck;
    Queue playerBDeck;
    Queue battle;
    int tmp,i;
    int decksize = 8;
    int playerAcard;
    int playerBcard;
    masterDeck.insert(10);
    masterDeck.insert(5);
    masterDeck.insert(25);
    masterDeck.insert(22);
    masterDeck.insert(63);
    masterDeck.insert(63);
    masterDeck.insert(22);
    masterDeck.insert(9);

    //Creation of master Deck
    cout<<"\nMASTER DECK \n";
    masterDeck.display();

    //Distribution of cards
    for(i=1;i<decksize/2;i++)
    {
        tmp = masterDeck.remove();
        playerADeck.insert(tmp);
        tmp = masterDeck.remove();
        playerBDeck.insert(tmp);
    }

    //Display of Cards of A
    cout<<"\nPlayerA DECK \n";
    playerADeck.display();

    //Display of cards of B
    cout<<"\nPlayerA DECK \n";
    playerBDeck.display();
    
    //Start of the battle round
    int x = 1;
    for(x=1;x<=1000;x++){
        cout<< "\n Battle Round : "<<x;
        playerAcard = playerADeck.remove();
        playerBcard = playerBDeck.remove();

    //Game end logic
        if(playerAcard == -1)
        {
            
            cout<<"\n PLAYER B IS THE WINNER FOR GAME";
            break;
        }
        if(playerBcard == -1)
        {
            cout<<"\n PLAYER A IS THE WINNER FOR GAME";
            break;
        }

        battle.insert(playerAcard);
        battle.insert(playerBcard);

        //Comparing two cards
        if(playerAcard > playerBcard){
            cout<< "\n Player A is Winner for this round";
            while(1)
            {
                tmp = battle.remove();
                if(tmp == -1)
                {
                    break;
                }
                playerADeck.insert(tmp);
            }
        }
        else if (playerBcard > playerAcard)
        {
             cout<< "\n Player B is Winner for this round";
            while(1)
            {
                tmp = battle.remove();
                if(tmp == -1)
                {
                    break;
                }
                playerBDeck.insert(tmp);
            }
        }
        else
        {
            cout<<"\n Tie in this round";
        }
        cout<<"\nAfter Round"<<x;
        cout << "\nplayer A DEC\n";
        playerADeck.display();

        cout << "\nplayer B DEC\n";
        playerBDeck.display();
    }
    cout<<"\n********* The End ******";
    return 0;
}