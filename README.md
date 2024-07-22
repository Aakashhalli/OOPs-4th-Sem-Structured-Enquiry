# Content Management System
1.1	Problem Statement 
    You are designing a content management system in C++ that allows users to create, edit, and publish blog posts, articles, and multimedia content. 
    How would you design classes to represent different types of content, user roles and permissions, content creation workflows, and methods for managing and 
    displaying content within the CMS? <br />
<pre>
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
                  -	Admins can view all published content by all editors.
                  -	If no content is published, it displays "No published content."
            o	Delete Content:
                  -	Admins can delete content based on the title.
        4.	Editor Actions:
            o	Create Content:
                  -	Editors can create new content of type BlogPost, Article, or Multimedia.
            o	Edit Content:
                  -	Editors can edit existing content based on the title.
                  -	It displays the current content and asks if the editor wants to edit it.
            o	Publish Content:
                  -	Editors can publish content.
                  -	It shows all unpublished content by the editor, allowing selection for publishing.
        5.	Viewer Actions:
            o	View Published Content:
                  -	Viewers can view all published content.
                  -	If no content is published, it displays "No published content."
    
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
            o	Provides text-based menus for different user roles (Admin, Editor, Viewer) to perform their respective 
                actions.
    
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
            o	Ensures that actions available to users are based on their roles, preventing unauthorized access to 
                functionalities.
</pre>
<br />
2.1	Class Diagram <br />
![image](https://github.com/user-attachments/assets/92f917aa-9f49-407b-9777-e4e44e9b451b)
<br />

<pre>
2.2 Class Description
    Content Class:
        The Content class is like a blueprint for creating and managing content items in our CMS. Each piece of content, whether it's a blog post, article, or 
        multimedia item, will have a title and a body. It also keeps track of whether the content is published and, if so, who published it. You can create, edit,
        and publish content using methods provided by this class. When publishing, it records the name of the editor who published it. The class also has methods to
        display the content, with published content showing the editor’s name.
    
    BlogPost, Article, Multimedia Classes:
        These three classes (BlogPost, Article, and Multimedia) are specific types of content. They inherit from the Content class, which means they have all the same
        properties and methods as Content, but they represent different kinds of content. For instance, a BlogPost might be used for regular blog entries, an Article for
        longer, more detailed pieces, and Multimedia for content that includes images, videos, or other media types.

    User Class:
        The User class represents a person who uses the CMS. Each user has a username, a password, and a role. The role can be Admin, Editor, or Viewer, which determines  
        what actions the user can perform within the CMS. This class is straightforward, mainly used for storing user credentials and their role in the system.

    CMS Class:
        The CMS (Content Management System) class is the core of the application. It manages users and content. This class provides methods for users to sign up and log in.         Based on the user’s role, it directs them to different sets of actions. For instance, Admins can view all published content and delete content, Editors can create,
        edit, and publish content, and Viewers can view published content. The class also handles the storage of user credentials in files and ensures that the correct
        actions are taken based on the user's role.
</pre>
