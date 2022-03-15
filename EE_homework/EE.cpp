#include <iostream>
using namespace std;

struct player
{
    int ID;
    int time;
    int coin;
    player *next;
};

struct queue
{
    player *top;
    player *back;
};

void treversal(queue *mainQueue)
{
    player *tmp = mainQueue->top;
    if (tmp == NULL)
        return;
    for (; tmp->next != NULL; tmp = tmp->next)
    {
        cout << tmp->ID << " ";
    }

    cout << endl;
}

player *generatePlayer(int ID, int time, int coin)
{
    player *tmp = new player;
    tmp->ID = ID;
    tmp->time = time;
    tmp->coin = coin;
    tmp->next = NULL;
    return tmp;
}

player *pop_top(queue *target)
{
    if (target->top == NULL)
        return NULL;
    player *tmp = target->top;
    target->top = target->top->next;
    if (target->top == NULL)
        target->back = NULL;
    tmp->next = NULL;
    return tmp;
}

void push_back(queue *target, player *select)
{
    if (select == NULL)
        return;
    if (target->top == NULL && target->back == NULL)
    {
        target->top = select;
        target->back = select;
        return;
    }
    target->back->next = select;
    // cout << "Player:  before" << target->back->ID << endl;
    target->back = select;
    // cout << "Player:  " << target->back->ID << endl;
}

player *find(player *players[], int time)
{
    for (int i = 0; i < 5; i++)
    {
        if (players[i]->time == time)
        {
            // cout << "find: " << players[i]->ID << endl;
            return players[i];
        }
    }
    return NULL;
}

void solve(queue *target, player *players[])
{
    player *player1 = NULL;
    player *player2 = NULL;
    int total_coins = 0;
    int pre_ID = -1;
    int counter = 0;
    for (int i = 0; i < 5; i++)
        total_coins += players[i]->coin;
    //

    while (total_coins > 0)
    {
        player *tmp = find(players, counter);
        player1 = tmp;

        if (player1 != NULL && player2 != NULL && player1->coin > 0 && player2->coin > 0)
        {
            if (player1->ID < player2->ID)
            {
                push_back(target, player1);
                push_back(target, player2);
                player2 = NULL;
            }
            else
            {
                push_back(target, player2);
                push_back(target, player1);
                player2 = NULL;
            }
        }
        else
        {
            if (player1 != NULL && player1->coin > 0)
            {
                push_back(target, player1);
            }

            if (player2 != NULL && player2->coin > 0)
            {
                push_back(target, player2);
                player2 = NULL;
            }
        }

        cout << "time : " << counter << "       player : ";
        if (target->top != NULL)
        {

            cout << target->top->ID << endl;
            int save = target->top->ID;
            (target->top->coin)--;
            // cout << "player" << target->top->ID << " coin: " << target->top->coin << endl;
            total_coins--;
            if (target->top->ID == pre_ID || target->top->coin <= 0)
            {
                player2 = pop_top(target);
            }

            pre_ID = save;
            // treversal(target);
        }
        else
        {
            cout << "x" << endl;
            pre_ID = -1;
        }
        counter++;
    }
}

int main()
{
    queue *mainQueue = new queue;
    mainQueue->top = NULL;
    mainQueue->back = NULL;
    player *players[5];
    int time, coin;

    cout << "輸入五人到達時間" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> time;
        players[i] = generatePlayer(i, time, 0);
    }
    cout << "輸入五人持有硬幣" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> coin;
        players[i]->coin = coin;
    }
    solve(mainQueue, players);

    return 0;
}