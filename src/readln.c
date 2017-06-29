///////////////// include preprocessor directive for importing libs ///////////
#include <string.h>
#include <stdio.h>

//////////////// macro definitions ////////////////
#define MAXLEN 5

///////////////////////////////////////////////////////////////////////////////
//////////////////// Internal functions and implementations ///////////////////
///////////////////////////////////////////////////////////////////////////////

/* readln implementation with fgets */
int readln_with_fgets(char str[], int maxlen) {
    int len_s;
    fgets(str, maxlen, stdin);
    len_s = strlen(str);
    if (str[len_s - 1] == '\n') {
        str[len_s - 1] = '\0'; // Mark the end of string
        len_s -= 1;
    }
    rewind(stdin); // This flushes the keyboard buffer
    return len_s;
}

/* readln implementation with getchar */
int readln_with_getchar(char str[], int maxlen) {
    char ch;
    int i = 0;
    int chars_remain = 1;
    while (chars_remain) {
        ch = getchar();
        if ((ch == '\n') || (ch == EOF) ) {
            chars_remain = 0;
        } else if (i < maxlen - 1) {
            str[i] = ch;
            i++;
        }
    }
    str[i] = '\0'; // Mark the end of string
    return i;
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////// Higher level wrapper functions ////////////////////////
///////////////////////////////////////////////////////////////////////////////
int readln(int impl_type, char str[], int maxlen) {
    int str_len = 0;

    switch(impl_type) {
        case 1:
            str_len = readln_with_fgets(str, maxlen);
            break;
        case 2:
            str_len = readln_with_getchar(str, maxlen);
            break;
        default:
            fprintf(stderr, "Error: Valid values for implementation options are 1 and 2 only.");
            exit(1);
            break;
    }

    return str_len;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////// Program implementation /////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    int impl_type;
    int result;
    char str[MAXLEN];

    const char *buffer =
        "There are 2 types of implementations available for this func.\n"
        "The first one reads the entire string and flushes the stdin buffer. [Option : 0]\n"
        "The second one reads terminates the string after %d chars. [Option : 1]\n";
    printf(buffer, MAXLEN);
    printf("Enter the type of implementation you want. Valid values 1 or 2:");
    impl_type = (int) getchar(); // Probably dangerous, but lets fix it later
    printf("Enter a new line of text:");
    result = readln(impl_type, str, MAXLEN);

    return result;
}
