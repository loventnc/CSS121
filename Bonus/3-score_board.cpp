#include <iostream>

using namespace std;

struct student
    {
        string name;
        int score;
        student *next;
        student *prev;
    };

student *head = NULL;
student *tail = NULL;

void showStudent(string name,int score)
{
    student *temp = new student;
    temp->score = score;
    temp->name = name;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void sortStudents()
{
    student *current = head;

    while (current->next != NULL)
    {
        student *compare = current->next;
        while (compare != NULL)
        {
            if (current->score > compare->score)
            {
                swap(current->score, compare->score);
                swap(current->name, compare->name);
            }
            compare = compare->next;
        }
        current = current->next;
    }
}

void printscoreboard()
{
    student *temp = head;
    for (size_t i = 0; i < 10; i++)
    {
        cout << temp->name << ": " << temp->score << endl;
        temp = temp->next;
    }
}

int main()
{
    showStudent("Luffy", 70);          
    showStudent("Zoro", 85);
    showStudent("Sanji", 65);
    showStudent("Law", 50);
    showStudent("Ace", 45);
    showStudent("Franky", 25);
    showStudent("Brook", 75);
    showStudent("Nami", 60);
    showStudent("Usopp", 30);
    showStudent("Chopper", 80);
    showStudent("Robin", 90);
    showStudent("Jinbe", 95);

    sortStudents();
    printscoreboard();

    return 0;
}