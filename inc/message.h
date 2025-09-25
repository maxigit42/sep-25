#ifndef MESSAGE_H
#define MESSAGE_H

# define MALLOC_ERR "Memory allocation error"
# define QUOTES_ERR "Quotes not closed"
# define PARSE_ERR "Error at input parsing"
# define NOT_CMD ": command not found"

#define CMD 1
#define TEXT 2
#define PIPE 3
#define INFILE 4
#define OUTFILE 5
#define HEREDOC 6
#define APPEND 7
#define SINGLE_QUOTE 8
#define DOUBLE_QUOTE 9
#define BUILTIN 10

#endif