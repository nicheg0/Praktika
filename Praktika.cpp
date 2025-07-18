#include <iostream>
#include <vector>

using namespace std;

class task {
public:
    string text = "";
    bool completeOrNo = false;
    task(string q, bool w) {
        text = q;
        completeOrNo = w;
    }
};

int main()
{
    task task1 = { "",false };
    vector<task> spisok = {};
    //auto iter = spisok.cbegin();
    int i = 0;
    while (true)
    {
    cout << "\nMenu:\n1)Add; \n2)Delete; \n3)See all tasks;\n4)Otmetka\n5)Exit;\nEnter your choice: " << endl;
    int choice = 0;
    cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new task: ";
            cin >> task1.text;
            spisok.emplace_back(task1);
            break;
        case 2:
            if (spisok.empty()) {
                cout << "List empty!" << endl;
                break;
            }
            cout << "Enter number of task: ";
            cin >> i;
            spisok.erase(spisok.begin() + i - 1);
            break;
        case 3:
            if (spisok.empty()) {
                cout << "List empty!" << endl;
                break;
            }
            cout << "TASKS:" << endl;
            for (i = 0; i < spisok.size(); i++) {
                cout << i+1 << ") " << spisok[i].text << " -- Completed: " << spisok[i].completeOrNo << endl;
            }
            break;
        case 4:
            if (spisok.empty()) {
                cout << "List empty!" << endl;
                break;
            }
            cout << "Enter the number of the item you want to mark as completed: ";
            cin >> i;
            spisok[i - 1].completeOrNo = true;
            break;
        case 5:
            return 0;
        default:
            cout << "Try again" << endl;
        }
    }
}
