#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>
using namespace std;
int ID;
struct todo {
    int id;
    string task;
};

//this method is used to add a new task to the list of tasks
void addtodo() {
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    todo todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task); //get user input
    ID++; //increment id for the current task

    //now write this task to the todo.txt file
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    //write the id to a new file so that we can use this id later to add new task
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"Do you want to add more task? y/n"<<endl;
    cin>> ch;

    //if user wants to add a new task again then call the same function else return
    if(ch == 'y'){
        addtodo();
    }
    else{
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// this method is used to print the task on the screen
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//This method is used to read data from the todo.txt file and print it on screen
void readData() {
    system("cls");
     cout<<"\t\t\t***********************************************************************"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t------------------Your current Tasks in the list--------------------";
    // while we dont reach the end of file keep on printing the data on screen
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

int searchData() {
    system("cls");
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    //while we dont reach end of file keep or searching for the id to match to the user input id
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

void markTaskCompleted() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
    int id = searchData();
    cout << "\n\tDo you want to mark this task as completed (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id == id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << "[X] " << todo.task; // Mark task as completed
            } else {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask marked as completed successfully";
    } else {
        cout << "\n\tTask not marked as completed";
    }
}

void deleteData() {
    system("cls");
    cout<<"\t\t\t***********************************************************************"<<endl;
	cout<<"\t\t\t                       WELCOME TO Your ToDo List                       "<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl;
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        //while we dont reach the end of file keep on searching for the id to delete the task
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


int main()
{
    system("cls");
	system("Color E0"); // "Color XY", X - backgroung color, Y - text color
    cout<<"\t\t\t***********************************************************************"<<endl;
    cout<<"\t\t\t*                                                                     *"<<endl;
	cout<<"\t\t\t*                      WELCOME TO Your ToDo List                      *"<<endl;
	cout<<"\t\t\t*                                                                     *"<<endl;
    cout<<"\t\t\t***********************************************************************"<<endl<<endl<<endl<<endl;
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.Add Task";
        cout << "\n\t2.View Task";
        cout << "\n\t3.Task mark as completed";
        cout << "\n\t4.Remove Task";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
            case 2:
            readData();
            break;
            case 3:
            markTaskCompleted();
            break;
               case 4:
            deleteData();
            break;
}
}
}
