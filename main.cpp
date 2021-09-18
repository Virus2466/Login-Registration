#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Enter Username : " << endl;
    cin >> username;
    cout << "Enter Password : " << endl;
    cin >> password;

    ifstream read("data.txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int options;
    cout << "1 : Register If You Are New" << endl;
    cout << "2 : Login to Your Exisiting Account" << endl;
    cout << "Your Choice" << endl;
    cin >> options;

    if (options == 1)
    {
        string username, password;

        cout << "Enter Username : \n";
        cin >> username;
        cout << "Enter Password : \n";
        cin >> password;

        ofstream file;
        file.open("data.txt");
        file << username << endl
             << password;
        file.close();

        main();
    }

    else if (options == 2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout << "Check Your Username Or password , Login Failed " << endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout << "Login Succesfull"<< endl;
            system("PAUSE");
            return 1;
        }
    }

    return 0;
}