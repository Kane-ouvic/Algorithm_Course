#include <iostream>
#include <cstdio>
using namespace std;
// void printResult(stack block_stack[], int amount);

struct block
{
    int number;
    int stack_location;
    block *next;

    // block *pre;
};

struct stack
{
    int number;
    // int stack_number;
    block *top;
};

block *pop(stack *blocks_stack)
{
    block *tmp = blocks_stack->top;
    blocks_stack->top = tmp->next;
    tmp->next = NULL;
    cout << blocks_stack->top << endl;
    return tmp;
}

void push(block *node, stack *block_stack)
{
    node->next = block_stack->top;
    node->stack_location = block_stack->number;
    block_stack->top = node;
}

void pull_all_up(block *node, stack *block_stack[])
{
    block *tmp = block_stack[node->stack_location]->top;

    for (; tmp->number != node->number; tmp = tmp->next)
    {
        cout << "pull up --" << endl;
        block *save = pop(block_stack[node->stack_location]);
        push(save, block_stack[save->number]);
    }
    cout << "pull up" << endl;
}

void move_all_up(block *node1, block *node2, stack *block_stack[])
{
    block *tmp = block_stack[node1->stack_location]->top;
    block *node1_stack_top = tmp;

    for (; tmp->number != node1->number; tmp = tmp->next)
    {
        cout << "move up --" << endl;
        tmp->stack_location = node2->stack_location;
    }
    cout << "move up" << endl;
    tmp->stack_location = node2->stack_location;
    tmp->next = block_stack[node2->stack_location]->top;
    block_stack[node2->stack_location]->top = node1_stack_top;
}

void move_onto(block *number1, block *number2, stack *blocks_stack[])
{
    // cout << "----------------------1\n";
    if (number1->stack_location == number2->stack_location)
        return;

    pull_all_up(number1, blocks_stack);
    pull_all_up(number2, blocks_stack);

    block *tmp = pop(blocks_stack[number1->stack_location]);
    push(tmp, blocks_stack[number2->stack_location]);
}

void move_over(block *number1, block *number2, stack *blocks_stack[])
{
    // cout << "----------------------2\n";
    if (number1->stack_location == number2->stack_location)
        return;

    pull_all_up(number1, blocks_stack);
    block *tmp = pop(blocks_stack[number1->stack_location]);
    push(tmp, blocks_stack[number2->stack_location]);
}

void pile_onto(block *number1, block *number2, stack *blocks_stack[])
{
    // cout << "----------------------3\n";
    if (number1->stack_location == number2->stack_location)
        return;

    pull_all_up(number2, blocks_stack);
    move_all_up(number1, number2, blocks_stack);
}

void pile_over(block *number1, block *number2, stack *blocks_stack[])
{
    // cout << "----------------------4\n";
    if (number1->stack_location == number2->stack_location)
        return;
    move_all_up(number1, number2, blocks_stack);
}

void printResult(stack *block_stack[], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << ": ";
        for (block *tmp = block_stack[i]->top; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->number + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{

    int amount;
    int times;

    scanf("%d %d", &amount, &times);

    stack *blocks_stack[amount];
    block *blocks[amount];

    //方塊初始化
    for (int i = 0; i < amount; i++)
    {
        block *tmp = new block;
        stack *tmp_stack = new stack;

        tmp->number = i;
        tmp->next = NULL;
        tmp->stack_location = i;
        tmp_stack->top = tmp;
        tmp_stack->number = i;

        blocks_stack[i] = tmp_stack;
        blocks[i] = tmp;
    }

    //指令操作
    for (int i = 0; i < times; i++)
    {
        string operand1, operand2;
        int number1, number2;

        cin >> operand1 >> number1 >> operand2 >> number2;
        number1--;
        number2--;
        // scanf("%s %d %s %d", operand1, &number1, operand2, &number2);
        // cout << "----------------------\n";
        // cout << operand1 << " " << number1 << " " << number2 << " " << operand2 << endl;

        if (operand1 == "move")
        {
            if (operand2 == "onto")
            {
                // cout << "test\n";
                move_onto(blocks[number1], blocks[number2], blocks_stack);
            }
            else if (operand2 == "over")
            {
                move_over(blocks[number1], blocks[number2], blocks_stack);
            }
        }
        else if (operand1 == "pile")
        {
            if (operand2 == "onto")
            {
                pile_onto(blocks[number1], blocks[number2], blocks_stack);
            }
            else if (operand2 == "over")
            {
                pile_over(blocks[number1], blocks[number2], blocks_stack);
            }
        }
        printResult(blocks_stack, amount);
    }

    return 0;
}