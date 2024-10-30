#ifndef UTILS_H
#define UTILS_H

// Due date validation functions
bool str_to_tm(const char *date_str, struct tm *date);
bool is_valid_date(const char *date_str, struct tm *date);
bool is_valid_due_date(const char *date_str);

// Help functions
void print_info();
void print_help();

#endif