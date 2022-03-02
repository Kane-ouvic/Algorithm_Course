#include <iostream>
#include <cstdio>
using namespace std;

struct block
{
    int number;
    int stack_location;
    block *next;
};
struct stack
{
    int number;
    block *top;
};
block *pop(stack *blocks_stack)
{
    block *tmp = blocks_stack->top;
    blocks_stack->top = tmp->next;
    tmp->next = NULL;
    return tmp;
}
void push(block *node, stack *block_stack)
{
    if (node == NULL)
        return;
    node->next = block_stack->top;
    node->stack_location = block_stack->number;
    block_stack->top = node;
}
void pull_all_up(block *node, stack *block_stack[])
{
    block *tmp = block_stack[node->stack_location]->top;
    while (tmp != node)
    {
        tmp = tmp->next;
        block *save = pop(block_stack[node->stack_location]);
        push(save, block_stack[save->number]);
    }
}
void move_all_up(block *node1, block *node2, stack *block_stack[])
{
    block *tmp = block_stack[node1->stack_location]->top;
    block *node1_stack_top = tmp;
    stack *pre_stack = block_stack[node1->stack_location];
    while (tmp != node1)
    {
        tmp->stack_location = node2->stack_location;
        tmp = tmp->next;
    }
    block_stack[node1->stack_location]->top = node1->next;
    tmp->stack_location = node2->stack_location;
    tmp->next = block_stack[node2->stack_location]->top;
    block_stack[node2->stack_location]->top = node1_stack_top;
}
void move_onto(block *number1, block *number2, stack *blocks_stack[])
{
    if (number1->stack_location == number2->stack_location)
        return;
    pull_all_up(number1, blocks_stack);
    pull_all_up(number2, blocks_stack);

    block *tmp = pop(blocks_stack[number1->stack_location]);
    push(tmp, blocks_stack[number2->stack_location]);
}
void move_over(block *number1, block *number2, stack *blocks_stack[])
{
    if (number1->stack_location == number2->stack_location)
        return;

    pull_all_up(number1, blocks_stack);
    block *tmp = pop(blocks_stack[number1->stack_location]);
    push(tmp, blocks_stack[number2->stack_location]);
}
void pile_onto(block *number1, block *number2, stack *blocks_stack[])
{
    if (number1->stack_location == number2->stack_location)
        return;

    pull_all_up(number2, blocks_stack);
    move_all_up(number1, number2, blocks_stack);
}
void pile_over(block *number1, block *number2, stack *blocks_stack[])
{
    if (number1->stack_location == number2->stack_location)
        return;
    move_all_up(number1, number2, blocks_stack);
}
void printResult(stack *block_stack[], int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << ":";
        stack *result = new stack;
        result->number = -1;
        result->top = NULL;
        for (block *tmp = block_stack[i]->top; tmp != NULL; tmp = tmp->next)
        {
            block *generate = new block;
            generate->number = tmp->number;
            push(generate, result);
        }
        for (block *tmp = result->top; tmp != NULL; tmp = tmp->next)
        {
            cout <<  " " << tmp->number + 1;
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int amount;
    int times;
    cin >> amount >> times;
    stack *blocks_stack[amount];
    block *blocks[amount];

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
    for (int i = 0; i < times; i++)
    {
        string operand1, operand2;
        int number1, number2;
        cin >> operand1 >> number1 >> operand2 >> number2;
        number1--;
        number2--;
        if(number1 < 0 || number1 >= amount || number2 < 0 || number2 >= amount)
            continue;
        if (operand1 == "move")
        {
            if (operand2 == "onto")
            {
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
    }
    printResult(blocks_stack, amount);
    return 0;
}