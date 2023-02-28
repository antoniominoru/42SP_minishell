# Minishell

## About

> As beautiful as a shell

> This project is about creating a simple shell. Yes, your little bash or zsh. You will learn a lot about processes and file descriptors.

## Developed commands

- Redirections: < > << >>
- Pipes | The output of each command in the pipeline is connected to the input of the next command via a pipe
- Environment variables ($ followed by a sequence of characters)
- $? which should expand to the exit status of the most recently executed foreground pipeline
- ctrl-C, ctrl-D and ctrl-\ which should behave like in bash
- Builtins
    ◦ echo with option -n
    ◦ cd with only a relative or absolute path
    ◦ pwd with no options
    ◦ export with no options
    ◦ unset with no options
    ◦ env with no options or arguments
    ◦ exit with no options
