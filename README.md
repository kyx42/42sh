# 42sh
42sh FINAL EPITECH Project

1 - 42SH DESCRIPTION

    42sh is a UNIX Shell like tcsh.

2 - FEATURES

    - CTRL^D : Exit the 42sh
    - Up and Down Arrows : history
    - Right and Left Arrows : Move into command line

3 - History

    You can search previous commands in the termcaps prompt with up and down arrows.
    
4 - Alias

    For example, "la" will be replaced by "ls -la" and "ls -la" will be execute.
    
5 - Echo

    The builtins echo with almost all his flags.

6 - Environment

    Environment variables can be used like variables with 3 functions:
    "setenv var value" to set
    "unsetenv var" to unset
    "env" to view.
7 - cd

    "cd my_directory" will moove you to the directory passed in parameter.
    Without parameter, cd will move you into the home directory.
    "cd -" will move you into the previous directory.

8 - Exit

    For exit the 42sh.
    We can use exit this way "exit 42" will exit 42sh with the return value of atoi("42");
