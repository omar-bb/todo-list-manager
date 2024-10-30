#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

bool str_to_tm(const char *date_str, struct tm *date)
{
    int day, month, year;

    if (sscanf(date_str, "%4d-%2d-%2d", &year, &month, &day) == 3)
    {
        date->tm_year = year - 1900;
        date->tm_mon = month - 1;
        date->tm_mday = day;
        date->tm_isdst = -1;

        return true;
    }

    return false;
}

bool is_valid_date(const char *date_str, struct tm *date)
{
    int vday, vmonth, vyear;

    if (str_to_tm(date_str, date))
    {
        vday = date->tm_mday;
        vmonth = date->tm_mon;
        vyear = date->tm_year;

        time_t r = mktime(date); 

        if (!(r == -1 || (vday != date->tm_mday) || (vmonth != date->tm_mon) || (vyear != date->tm_year))) 
            return true;
    }

    return false;
}

bool is_valid_due_date(const char *date_str) 
{
    struct tm date = {0};

    if (is_valid_date(date_str, &date))
    {
        time_t input_time = mktime(&date);
        time_t current_time = time(NULL);

        if (input_time > current_time) 
            return true;
    }

    return false;
}

void print_info()
{
    printf("Type ./todo -h or ./todo --help for more information.");
}

void print_help()
{
    printf("To-Do List Manager CLI\n");
    printf("======================\n");
    printf("Manage your tasks efficiently from the command line.\n\n");
    printf("USAGE:\n");
    printf("  ./todo [OPTIONS] [COMMAND]\n\n");
    printf("OPTIONS:\n");
    printf("  -h, --help             Show this help message and exit.\n");
    printf("  -v, --version          Show the application's version and exit.\n\n");
    printf("COMMANDS:\n");
    printf("  add <task> [-p PRIORITY] [-d DUE_DATE] \n");
    printf("                      Add a new task with optional priority and due date.\n");
    printf("                      Example: ./todo add \"Finish C project\" -p high -d 2024-10-30\n\n");
    printf("  list [--all | --completed | --pending] [--sort PRIORITY | DUE_DATE]\n");
    printf("                      List tasks. Options:\n");
    printf("                        --all        Show all tasks (default).\n");
    printf("                        --completed  Show only completed tasks.\n");
    printf("                        --pending    Show only pending tasks.\n");
    printf("                        --sort       Sort tasks by priority or due date.\n\n");
    printf("  delete <task_id>     Delete a task by ID.\n");
    printf("                      Example: ./todo delete 3\n\n");
    printf("  edit <task_id> [-t NEW_TASK] [-p PRIORITY] [-d DUE_DATE] \n");
    printf("                      Edit a task. You can change the task, priority, or due date.\n");
    printf("                      Example: ./todo edit 3 -t \"Update C project README\" -p medium\n\n");
    printf("  complete <task_id>   Mark a task as completed.\n");
    printf("                      Example: ./todo complete 2\n\n");
    printf("EXAMPLES:\n");
    printf("  ./todo add \"Study for exams\" -p high -d 2024-10-29\n");
    printf("  ./todo list --sort PRIORITY\n");
    printf("  ./todo complete 2\n");
    printf("  ./todo delete 4\n\n");
    printf("Task priorities:\n");
    printf("  low, medium, high   Default is \"medium\" if not specified.\n\n");
    printf("Date format:\n");
    printf("  YYYY-MM-DD          Example: 2024-10-30\n\n");
    printf("Enjoy managing your tasks!\n");
}

