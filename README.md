# Content Management System
1.1	Problem Statement 
    You are designing a content management system in C++ that allows users to create, edit, and publish blog posts, articles, and multimedia content. 
    How would you design classes to represent different types of content, user roles and permissions, content creation workflows, and methods for managing and 
    displaying content within the CMS?

1.2	Features of Application
    User Authentication and Role Management:
        1.	User Signup:
            o	Allows users to register by creating a username and password.
            o	Users are assigned roles: Admin, Editor, or Viewer.
            o	Credentials are stored in separate files based on roles (admins.txt, editors.txt, viewers.txt).
        2.	User Login:
            o	Users can log in by providing their role, username, and password.
            o	Authentication checks the respective role file to validate credentials.
    Role-Based Functionalities:
        3.	Admin Actions:
            o	View All Published Content:
                  	Admins can view all published content by all editors.
                  	If no content is published, it displays "No published content."
            o	Delete Content:
                  	Admins can delete content based on the title.
        4.	Editor Actions:
            o	Create Content:
                  	Editors can create new content of type BlogPost, Article, or Multimedia.
            o	Edit Content:
                  	Editors can edit existing content based on the title.
                  	It displays the current content and asks if the editor wants to edit it.
            o	Publish Content:
                  	Editors can publish content.
                  	It shows all unpublished content by the editor, allowing selection for publishing.
        5.	Viewer Actions:
                  o	View Published Content:
                  	Viewers can view all published content.
                  	If no content is published, it displays "No published content."
    Content Management:
        6.	Content Creation:
            o	Content can be created with a title and body.
            o	Supports three types of content: BlogPost, Article, and Multimedia.
        7.	Content Editing:
            o	Editors can edit the body of existing content.
            o	Displays current content before allowing edits.
        8.	Content Publishing:
            o	Editors can publish content, marking it as published and associating it with the editor's name.
            o	Keeps track of which editor published the content.
        9.	Content Display:
            o	Published content shows the title, body, and editor's name.
            o	Unpublished content displays only title and body.
        10.	Content Deletion:
            o	Admins can delete content by providing the title.
    User Interface:
        11.	Interactive Menus:
            o	Provides text-based menus for different user roles (Admin, Editor, Viewer) to perform their respective actions.
    Data Storage:
        12.	File-Based Storage:
            o	User credentials are stored in text files based on roles.
            o	Ensures persistent storage of user data across sessions.
    Code Design:
        13.	Object-Oriented Design:
            o	Uses classes to encapsulate functionality: Content, BlogPost, Article, Multimedia, User, and CMS.
            o	Inherits from base classes to create specific content types.
    Additional Features:
        14.	Role-Based Access Control:
            o	Ensures that actions available to users are based on their roles, preventing unauthorized access to functionalities.
