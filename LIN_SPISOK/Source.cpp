#include "stdio.h"
#include "stdlib.h"

struct Node {
	int Data;
	Node* next;
};

Node* add(Node *head, int Value)
{
	Node *New = (Node*)malloc(sizeof(Node));
	New->Data = Value;
	New->next = head;
	return New;
}

void Show(Node* head)
{
	while (head)
	{
		printf("%d\n", head->Data);
		head = head->next;
	}
}

Node* Find(Node *head, int Value)
{
	while (head)
	{
		if (head->Data == Value)
			return head;
		head = head->next;
	}
	return NULL;
}

Node* Delete(Node* head, Node* removable)
{
	if (head == removable)
	{
		head = head->next;
		free(removable);
	}
	else
	{
		Node *prev = head;
		while (prev->next != removable)
		{
			prev = prev->next;
		}

		prev->next = removable->next;
		free(removable);
	}
	return head;
}

int main()
{
	Node *a = NULL;

	for (int i = 0; i < 5; i++)
		a = add(a, i);

	Show(a);
	putchar('\n');
	Node *del = Find(a, 2);

	a = Delete(a, del);

	Show(a);

	system("PAUSE");
	return 0;
}