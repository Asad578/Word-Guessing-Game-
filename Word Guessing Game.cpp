#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	char data;
	Node* next;

	Node()
	{
		data = ' ';
		next = NULL;
	}

};


class Stack
{
	Node* top;

public:
	Stack()
	{
		top = NULL;
	}

	void push(char c)
	{
		Node* temp = ( Node*)malloc(sizeof( Node));		/////....Allocating Memory Dynamically......
		temp->data = c;
		temp->next = top;
		top = temp;
	}
	void pop()
	{
		if (isempty())
		{
			cout << "\n\tStack Underflow\n";
		}
		else
		{
			top = top->next;
		}
	}

	bool isempty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
			return false;
	}

	char tos()
	{
		return top->data;
	}

	void Display_stack()
	{
		Node* ptr;
		ptr = top;
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}

	Stack Copy_Reverse(Stack& Comp_S)
	{
		Stack temp_S;
		Node* ptr;
		ptr = Comp_S.top;
		while (ptr != NULL)
		{
			temp_S.push(ptr->data);
			ptr = ptr->next;
		}

		return temp_S;
	}

};



class Queue
{
private:
	Node* Front;
	Node* Rear;

public:
	Queue()
	{
		Front = NULL;
		Rear = NULL;
	}

	void EnQueue(char c)
	{
		if (Rear == NULL)
		{
			Rear = ( Node*)malloc(sizeof( Node));
			Rear->data = c;
			Rear->next = NULL;
			Front = Rear;
		}
		else
		{
			 Node* temp = ( Node*)malloc(sizeof( Node));
			Rear->next = temp;
			temp->data = c;
			temp->next = NULL;
			Rear = temp;
		}
	}

	void DeQueue()
	{
		Node* temp = Front;
		if (Front == NULL)
		{
			cout << "\n\n\t\tQueue is Empty\n";
		}
		else
		{
			if (temp->next != NULL)
			{
				Front = Front->next;
				temp = NULL;
				delete temp;
			}
			else
			{
				Front = NULL;
				Rear = NULL;
			}
		}
	}

	int size_of_Queue()
	{
		int s = 0;
		Node* temp = Front;
		while (temp != NULL)
		{
			s++;
			temp = temp->next;
		}
		return s;
	}

	void Display_Queue()
	{
		Node* temp = Front;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}



};



bool Main_Function(Stack& S, int n, int Stage)
{
	Queue Q_attempts;

	Stack Rec_S;
	Stack temp_S;
	Stack Dis_S;
	Stack Comp_S;

	for (int i = 0; i < n; i++)
	{
		Comp_S.push('_');
		Dis_S.push('_');
	}

	int Win = 0, Lose = 0;
	while (Win != n && Lose != 7)
	{
		system("cls");

		cout << "\n\t\t\t\t------------------------------------"
			<< "\n\t\t\t\t    Hollywood Word Guessing Game"
			<< "\n\t\t\t\t------------------------------------";

		cout << "\n\t\t\t\t\t\t\t\t\t--------  -----"
			<< "\n\t\t\t\t\t\t\t\t\t Stage:   | " << Stage << " |"
			<< "\n\t\t\t\t\t\t\t\t\t--------  -----";

		cout << "\n\t\t\t\t-----------------"
			<< "\n\t\t\t\t Wrong Attempts:   ";
		Q_attempts.Display_Queue();
		cout << "\n\t\t\t\t-----------------";

		if (Q_attempts.size_of_Queue() == 6)
		{
			cout << "\n\n\t\t\t\t--------------"
				<< "\n\t\t\t\t Last Attempt  "
				<< "\n\t\t\t\t--------------";
		}
		else
		{
			cout << "\n\n\t\t---------------------   -----"
				<< "\n\t\t Remaining Attempts:    | " << (7 - (Q_attempts.size_of_Queue())) << " |"
				<< "\n\t\t---------------------   -----";
		}

		cout << "\n\n\t\t\t\t\t-------"
			<< "\n\t\t\t\t\t Word:    ";
		while (!Dis_S.isempty())
		{
			cout << Dis_S.tos() << " ";
			Dis_S.pop();
		}
		cout << "\n\t\t\t\t\t-------";

		char c;
		cout << "\n\n\n\t\tEnter the Alphabet:\t";
		cin >> c;
		c = toupper(c);

		bool h = true;
		for (int i = 0; i < n; i++)
		{
			if (c == S.tos())
			{
				if (c != Comp_S.tos())
				{
					++Win;
				}
				temp_S.push(c);
				h = false;
			}
			else if (Comp_S.tos() != '_')
			{
				temp_S.push(Comp_S.tos());
			}
			else
			{
				temp_S.push('_');
			}

			Rec_S.push(S.tos());
			S.pop();
			Comp_S.pop();

		}

		while (!Rec_S.isempty())
		{
			S.push(Rec_S.tos());
			Rec_S.pop();
		}

		while (!temp_S.isempty())
		{
			Comp_S.push(temp_S.tos());
			temp_S.pop();
		}

		Dis_S = Dis_S.Copy_Reverse(Comp_S);				////....Copy Comp_S into Dis_S but in reverse order......

		if (h == true)
		{
			Q_attempts.EnQueue(c);
			++Lose;
		}

	}

	if (Lose == 7)
	{
		system("cls");

		cout << "\n\t\t\t\t------------------------------------"
			<< "\n\t\t\t\t    Hollywood Word Guessing Game"
			<< "\n\t\t\t\t------------------------------------";

		cout << "\n\t\t\t\t\t\t\t\t\t--------  -----"
			<< "\n\t\t\t\t\t\t\t\t\t Stage:   | " << Stage << " |"
			<< "\n\t\t\t\t\t\t\t\t\t--------  -----";

		cout << "\n\t\t\t\t-----------------"
			<< "\n\t\t\t\t Wrong Attempts:   ";
		Q_attempts.Display_Queue();
		cout << "\n\t\t\t\t-----------------";

		cout << "\n\n\n\t\t\t\t\t---------------"
			<< "\n\t\t\t\t\t|  You Lost!  |\t  BETTER LUCK NEXT TIME!"
			<< "\n\t\t\t\t\t---------------";
		return false;
	}
	else
	{
		system("cls");

		cout << "\n\t\t\t\t------------------------------------"
			<< "\n\t\t\t\t    Hollywood Word Guessing Game"
			<< "\n\t\t\t\t------------------------------------";

		cout << "\n\t\t\t\t\t\t\t\t\t--------  -----"
			<< "\n\t\t\t\t\t\t\t\t\t Stage:   | " << Stage << " |"
			<< "\n\t\t\t\t\t\t\t\t\t--------  -----";

		cout << "\n\t\t\t\t-----------------"
			<< "\n\t\t\t\t Wrong Attempts:   ";
		Q_attempts.Display_Queue();
		cout << "\n\t\t\t\t-----------------";

		cout << "\n\n\t\t\t\t\t-------"
			<< "\n\t\t\t\t\t Word:    ";
		Dis_S.Display_stack();
		cout << "\n\t\t\t\t\t-------";

		cout << "\n\n\t\t\t\t  --------------"
			<< "\n\t\t\t\t  |  You Won!  |   CONGRATULATIONS!"
			<< "\n\t\t\t\t  --------------"
			<< "\n\n\t\t\t\t\t --------------------"
			<< "\n\t\t\t\t\t |  Stage Cleared!  |"
			<< "\n\t\t\t\t\t --------------------";

		return true;
	}


}


int Stages(int Stage)
{
	switch (Stage)
	{
	case 1:
	{
		char word[5] = { 'A','H','M','A','D' };

		Stack* S = new Stack();
		for (int i = 0; i < 5; i++)
		{
			S->push(word[i]);
		}

		bool Next = Main_Function(*S, 5, Stage);
		if (Next == true)
		{
			++Stage;
		}

		delete S;
		break;
	}
	case 2:
	{
		char word[6] = { 'H','A','N','Z','L','A' };

		Stack* S = new Stack();
		for (int i = 0; i < 6; i++)
		{
			S->push(word[i]);
		}

		bool Next = Main_Function(*S, 6, Stage);
		if (Next == true)
		{
			++Stage;
		}

		delete S;
		break;
	}
	case 3:
	{
		char word[6] = { 'R','E','H','M','A','N' };

		Stack* S = new Stack();
		for (int i = 0; i < 6; i++)
		{
			S->push(word[i]);
		}

		bool Next = Main_Function(*S, 6, Stage);
		if (Next == true)
		{
			++Stage;
		}

		delete S;
		break;
	}
	case 4:
	{
		char word[11] = { 'S','A','L','L','A','H','U','D','D','I','N' };

		Stack* S = new Stack();
		for (int i = 0; i < 11; i++)
		{
			S->push(word[i]);
		}

		bool Next = Main_Function(*S, 11, Stage);
		if (Next == true)
		{
			++Stage;
		}

		delete S;
		break;
	}
	case 5:
	{
		char word[9] = { 'Z','A','B','I','U','L','L','A','H' };

		Stack* S = new Stack();
		for (int i = 0; i < 9; i++)
		{
			S->push(word[i]);
		}

		bool Next = Main_Function(*S, 9, Stage);
		if (Next == true)
		{
			++Stage;
		}

		delete S;
		break;
	}
	}
	return Stage;
}


int main()
{
	int choice, Stage = 1, X;
	bool c = true;
	do
	{
		system("cls");
		cout << "\n\t\t\t\t------------------------------------"
			<< "\n\t\t\t\t    Hollywood Word Guessing Game"
			<< "\n\t\t\t\t------------------------------------\n";

		cout << "\n\n\t----------------"
			<< "\n\t  Enter Choice"
			<< "\n\t----------------\n"
			<< "\n\t1. Start"
			<< "\n\t2. Exit\t";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int A = 1;
			do
			{
				X = Stages(Stage);

				if (X > 5)
				{
					system("cls");
					cout << "\n\t\t\t\t------------------------------------"
						<< "\n\t\t\t\t    Hollywood Word Guessing Game"
						<< "\n\t\t\t\t------------------------------------\n";

					cout << "\n\n\t\t\t\t------------------------"
						<< "\n\t\t\t\t|  All Stages Cleard!  |   CONGRATULATIONS!"
						<< "\n\t\t\t\t------------------------\n\n\n\t\t";
					system("pause");
					Stage = 1;
					A = 0;
				}
				else
				{
					if (Stage == X)
					{
						cout << "\n\n\t\tPress 1 to Try Agian!\t";
						cin >> A;
					}
					else
					{
						++Stage;
						cout << "\n\n\t\tPress 1 for next Stage!\t";
						cin >> A;
					}
				}


			} while (A == 1);

			break;
		}
		case 2:
		{
			c = false;
			break;
		}
		default:
			cout << "\n\n\t\tInvalid Choice!";
		}

	} while (c == true);



	cout << "\n\n";
	return 1;
}