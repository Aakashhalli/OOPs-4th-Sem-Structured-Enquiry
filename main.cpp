#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <conio.h>
#include "ui.h"

using namespace std;

class Content {
protected:
    string title;
    string body;
    bool isPublished;
    string editorName;

public:
    Content(const string& t, const string& b) : title(t), body(b), isPublished(false), editorName("") {}

    virtual void create(const string& t, const string& b) {
        title = t;
        body = b;
    }

    virtual void edit(const string& b) {
        body = b;
    }

    virtual void publish(const string& editor) {
        isPublished = true;
        editorName = editor;
    }

    virtual void display() const {
        cout << "| Title: " << title << "\n| Body: " << body << "\n| Published: " << (isPublished ? "Yes" : "No") << endl;
        if (isPublished) {
            cout<<"| Editor: " << editorName << endl;
            cout<<"+-----------------------------"<<endl;
        }
    }

    virtual void display2() const {
        cout<<"+------------------------------------"<<endl;
        cout<<"| Title: " << title << "\n| Body: " << body << endl;
        if (isPublished) {
            cout<<"| Editor: " << editorName << endl;
            cout<<"+------------------------------------"<<endl;
        }
    }
    virtual void display3() const {
        cout << "| Title: " << title << "\n| Body: " << body << "\n| Published: "<<(isPublished ? "Yes" : "No")<< endl;
            cout<<"| Editor: " << editorName << endl;
            cout<<"+------------------------------------"<<endl;
    }

    bool published() const {
        return isPublished;
    }

    string getTitle() const {
        return title;
    }

    string getEditorName() const {
        return editorName;
    }

    virtual ~Content() = default;
};

class BlogPost : public Content {
public:
    BlogPost(const string& t, const string& b) : Content(t, b) {}
};

class Article : public Content {
public:
    Article(const string& t, const string& b) : Content(t, b) {}
};

class Multimedia : public Content {
public:
    Multimedia(const string& t, const string& b) : Content(t, b) {}
};

class User {
public:
    string username;
    string password;
    int role;

    User(const string& uname, const string& pass, const int r) : username(uname), password(pass), role(r) {}
};

void getPassword(string &password, int max_length)
{
    int i = 0;
    char ch;
    password.clear(); 

    while (true)
    {
        ch = getch(); 
        if (ch == 13 || ch == 10) 
        {
            break;
        }
        else if (ch == 8 && i > 0) 
        {
            i--;
            password.pop_back();
            printf("\b \b");
        }
        else if (i < max_length)
        {
            password.push_back(ch);
            i++;
            printf("*"); 
        }
    }

    printf("\n");
}
class CMS {
private:
    unordered_map<string, shared_ptr<User>> users;
    vector<shared_ptr<Content>> contents;

public:
    void signup() {
        string username, password;
        int role;
        signup_page();
        cin >> role;
        if(role>3) { 
            cout << "Invalid role!" << endl;
            Sleep(1000);
            system("cls");
            return;
        }
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        // cin >> password;
        getPassword(password, 50);
        Loading();
        auto user = make_shared<User>(username, password, role);
        users[username] = user;

        string filename;
        if (role == 1) {
            filename = "admins.txt";
        } else if (role == 2) {
            filename = "editors.txt";
        } else if (role == 3) {
            filename = "viewers.txt";
        } else {
            cout << "Invalid role!" << endl;
            return;
        }

        ofstream file(filename, ios::app);
        file << username << "\t" << password << endl;
        file.close();
        signedup();
    }

    shared_ptr<User> login() {
        string username, password;
        int role;
        login_page();
        cin >> role;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        // cin >> password;
        getPassword(password, 50);
        Loading();

        string filename;
        if (role == 1) {
            filename = "admins.txt";
        } else if (role == 2) {
            filename = "editors.txt";
        } else if (role == 3) {
            filename = "viewers.txt";
        } else {
            cout << "Invalid role!" << endl;
            return nullptr;
        }

        ifstream file(filename);
        string fileUsername, filePassword;
        while (file >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                logged_in(username);
                auto user = make_shared<User>(username, password, role);
                users[username] = user;
                return user;
            }
        }
        cout << "Login failed!" << endl;
        Sleep(2000);
        system("cls");
        return nullptr;
    }

    void performActions(const shared_ptr<User>& user) {
        if (!user) {
            cout << "Invalid user!" << endl;
            return;
        }
        if (user->role == 1) {
            adminActions();
        } else if (user->role == 2) {
            editorActions(user->username);
        } else if (user->role == 3) {
            viewerActions();
        } else {
            cout << "Unknown role!" << endl;
        }
    }

    void adminActions() {
        int choice;
        do {
            // system("cls");
            cout << "Admin Actions: \n1. View All Content\n2. Delete Content\n3. Logout\nChoose an option: ";
            cin >> choice;
            system("cls");
            switch (choice) {
                case 1:
                    viewAllContent();
                    break;
                case 2:
                    deleteContent();
                    break;
                case 3:
                    Logging_out();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 3);
    }

    void editorActions(const string& editorName) {
        int choice;
        do {
            system("cls");
            cout << "Editor Actions: \n1. Create Content\n2. Edit Content\n3. Publish Content\n4. Logout\nChoose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createContent();
                    break;
                case 2:
                    editContent();
                    break;
                case 3:
                    publishContent(editorName);
                    break;
                case 4:
                    Logging_out();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 4);
    }

    void viewerActions() {
        int choice;
        do {
            // system("cls");
            cout << "Viewer Actions: \n1. View Published Content\n2. Logout\nChoose an option: ";
            cin >> choice;
            system("cls");
            switch (choice) {
                case 1:
                    viewPublishedContent();
                    break;
                case 2:
                    Logging_out();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 2);
    }

    void createContent() {
        string title, body;
        int type;
        Content_type_page();
        cin >> type;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter body: ";
        getline(cin, body);

        shared_ptr<Content> content;
        if (type == 1) {
            content = make_shared<BlogPost>(title, body);
        } else if (type == 2) {
            content = make_shared<Article>(title, body);
        } else if (type == 3) {
            content = make_shared<Multimedia>(title, body);
        } else {
            cout<<endl<<"Invalid content type!" << endl;
            Sleep(2000);
            system("cls");
            return;
        }
        contents.push_back(content);
        cout << "Content created successfully!" << endl;
        Sleep(2000);
        system("cls");
    }

    void editContent() {
        string title, body;
        cout << "Enter title of content to edit: ";
        cin.ignore();
        getline(cin, title);

        for (auto& content : contents) {
            if (content->getTitle() == title) {
                cout<<"+-----------------------------------"<<endl;
                cout<<"| Current content:\n";
                cout<<"+-----------------------------------"<<endl;
                content->display();
                int editChoice;
                cout<<"------------------------------------"<<endl;
                cout << "Do you want to edit this content? (Yes 1, No 0): ";
                cin >> editChoice;
                if (editChoice == 1) {
                    cout << "Enter new body: ";
                    cin.ignore();
                    getline(cin, body);
                    content->edit(body);
                    cout << "Content edited successfully!" << endl;
                    Sleep(2000);
                    system("cls");
                } else {
                    cout << "Content not edited." << endl;
                    Sleep(2000);
                    system("cls");
                }
                return;
            }
        }
        cout << "Content not found!" << endl;
        Sleep(2000);
        system("cls");
    }

    void publishContent(const string& editorName) {
        bool hasUnpublished = false;
        cout << "+------------------------------------" << endl;
        cout << "| Unpublished content by you:\n";
        cout << "+------------------------------------" << endl;
        for (const auto& content : contents) {
            if (!content->published() && content->getEditorName().empty()) {
                content->display();
                cout << "-------------------------------------" << endl;
                hasUnpublished = true;
            }
        }
        if (!hasUnpublished) {
            cout << endl << "No unpublished content found." << endl;
            Sleep(2000);
            system("cls");
            return;
        }

        string title;
        cout << "Enter title of content to publish: ";
        cin.ignore();
        getline(cin, title);

        for (auto& content : contents) {
            if (content->getTitle() == title && !content->published()) {
                content->publish(editorName);
                cout << "Content published successfully!" << endl;
                Sleep(2000);
                system("cls");
                return;
            }
        }
        cout << "Content not found or already published!" << endl;
        Sleep(2000);
        system("cls");
    }

    void viewAllContent() const {
        bool hasPublished = false;
        for (const auto& content : contents) {
            // if (content->published()) {
                cout<<"+------------------------------------" << endl;
                content->display3();
                hasPublished = true;
            // }
        }
        if (!hasPublished) {
            cout << "No published content." << endl;
            Sleep(2000);
        }
    }

    void deleteContent() {
        string title;
        cout << "Enter title of content to delete: ";
        cin.ignore();
        getline(cin, title);

        auto it = remove_if(contents.begin(), contents.end(), [&](const shared_ptr<Content>& content) {
            return content->getTitle() == title;
        });

        if (it != contents.end()) {
            contents.erase(it, contents.end());
            cout << "Content deleted successfully!" << endl;
            Sleep(2000);
            system("cls");
        } else {
            cout << "Content not found!" << endl;
            Sleep(2000);
            system("cls");
        }
    }

    void viewPublishedContent() const {
        bool hasPublished = false;
        for (const auto& content : contents) {
            if (content->published()) {
                content->display2();
                // cout << "-------------------------" << endl;
                hasPublished = true;
            }
        }
        if (!hasPublished) {
            cout << "No published content." << endl;
            Sleep(2000);
        }
    }
};

int main() {
    system("cls");
    CMS cms;
    int choice;
    do {
        LOS();
        cin >> choice;

        if (choice == 1) {
            cms.signup();
        } else if (choice == 2) {
            auto user = cms.login();
            if (user) {
                cms.performActions(user);
            }
        } else
            cout << "Invalid choice!" << endl;
    } while (choice < 3);
    return 0;
}