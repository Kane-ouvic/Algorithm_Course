#include <iostream>
using namespace std;

struct node
{
    int number;
    node *next;
};

struct stack
{
    node *top;
};

void printStack(stack *target_stack)
{
    cout << "Stack: ";
    for (node *tmp = target_stack->top; tmp != NULL; tmp = tmp->next)
    {
        cout << tmp->number << " ";
    }
    cout << endl;
}

node *pop(stack *target_stack)
{
    if (target_stack->top == NULL)
        return NULL;
    node *tmp = target_stack->top;
    target_stack->top = tmp->next;
    tmp->next = NULL;
    cout << "pop\n";
    return tmp;
}

void push(node *newNode, stack *target_stack)
{
    if (newNode == NULL)
        return;
    newNode->next = target_stack->top;
    target_stack->top = newNode;
    cout << "push\n";
}

stack *getAssemble(stack *target_stack)
{
    stack *tmp_ass = new stack;
    tmp_ass->top = NULL;
    int counter = 0;
    do
    {
        node *tmp = pop(target_stack);
        counter += tmp->number;
        tmp->number = -(tmp->number);
        push(tmp, tmp_ass);

    } while (counter != 0);
    return tmp_ass;
}

void putAssemble(stack *now_ass, stack *target_stack)
{
    while (1)
    {
        node *tmp = pop(now_ass);
        if (tmp == NULL)
            break;
        tmp->number = -(tmp->number);
        push(tmp, target_stack);
    }
}

int countElements(stack *now_ass)
{
    node *tmp = now_ass->top;
    int counter = 0;
    int count_elements = 0;
    while (1)
    {
        tmp = tmp->next;
        if(tmp->next == NULL)
            break;
        count_elements += tmp->number;
        if (count_elements == 0)
            counter++;
    }
    return counter;
}

stack *getNode(stack *now_ass, int index)
{
    return NULL;
}

void putNode(stack *node, stack *now_ass)
{
}

void push_ass(stack *target_stack)
{
    node *tmp1 = new node;
    node *tmp2 = new node;
    tmp1->number = -1;
    tmp1->next = NULL;
    tmp2->number = 1;
    tmp2->next = NULL;
    push(tmp1, target_stack);
    push(tmp2, target_stack);
}

void dup_ass(stack *target_stack)
{
    stack *tmp_stack = new stack;
    tmp_stack->top = NULL;

    node *copy_node = NULL;
    node *copy_first = new node;
    copy_first->number = -1;
    copy_first->next = NULL;
    push(copy_first, tmp_stack);
    int counter = 1;

    for (node *tmp = target_stack->top->next; counter != 0; tmp = tmp->next)
    {
        cout << "------------------1\n";
        node *copy_node = new node;
        copy_node->number = -tmp->number;
        copy_node->next = NULL;
        push(copy_node, tmp_stack);
        counter += tmp->number;
    }
    // cout << "----------------test\n";
    // printStack(tmp_stack);
    // cout << "----------------test\n";

    do
    {
        copy_node = pop(tmp_stack);
        if (copy_node == NULL)
            break;
        copy_node->number = -(copy_node->number);
        push(copy_node, target_stack);
        // cout << "test msg" << endl;
    } while (copy_node != NULL);

    printStack(target_stack);
}

void union_ass(stack *target_stack)
{
}

void intersect_ass(stack *target_stack)
{
}

void add_ass(stack *target_stack)
{
}

int main(void)
{
    int times;
    cin >> times;

    stack *save_stack = new stack;
    save_stack->top = NULL;

    for (int i = 0; i < times; i++)
    {
        string operand;
        cin >> operand;
        stack *timely_ass;
        timely_ass->top = NULL;
        if (operand == "PUSH")
        {
            push_ass(save_stack);
        }
        else if (operand == "DUP")
        {
            dup_ass(save_stack);
        }
        else if (operand == "UNION")
        {
            putAssemble(save_stack, timely_ass);
        }
        else if (operand == "INTERSECT")
        {
            int test = countElements(save_stack);
            cout << "count: " << test << endl;
        }
        else if (operand == "ADD")
        {
            timely_ass = getAssemble(save_stack);
        }
        printStack(save_stack);
        printStack(timely_ass);
    }
    return 0;
}