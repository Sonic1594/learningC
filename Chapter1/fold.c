#include <stdio.h>
#include <string.h>

/* This code takes a line of input and folds it into multiple
lines after the last non blank character before the n-th column */

int isWhitespace(char c) {
    return c == ' ' || c == '\t';
}

int isNewline(char c) {
    return c == '\n';
}

int getWidth(char c, int currentLength, int tabstop) {
    int width = 1;
    if (c == '\t') {
        width = tabstop - currentLength % tabstop;
    }
    return width;
}

int main(){
    /* n is the max length a string can be before being folded
    char[] is the holder for the string to be printed before folding to next
    places keeps track of how long the string to know when to fold it
    isBlank lets us know if we are looking at a space so we dont cut words
    */

    // read the character
    // find the width
    // fold if the width > 31
    // find last whitespace to break on the word
    // repeat

    int tabstop = 8; // how wide a tab is
    int maxWidth = 32; // how wide our output can be

    int c; // current character
    char line[maxWidth + 2]; // main line buffer
    char tmp[maxWidth + 2]; // tmp buffer for word breaks
    int index = 0; // current line index
    int length = 0; // current line length (for tabs)
    int lastWhitespaceIndex = -1; // last index for a whitespace so we know where to word break
    int lastWhitespaceLength = -1; // and length
    memset(&line, '\0', sizeof(line));
    while ((c = getchar()) != EOF) {
        length += getWidth(c, length, tabstop);
        if (isWhitespace(c)) {
            lastWhitespaceIndex = index;
            lastWhitespaceLength = length;
        }
        if (isNewline(c) || length >= maxWidth) {
            int tmpIndex = -1; // save word boundary index
            int tmpLength = -1; // and length
            if (lastWhitespaceIndex > 0 && length > maxWidth) {
                // break on word boundaries only when we didn't break for newline
                // save and copy the remaining buffer to a tmp and back

                // lorem ipsum
                //            ^ index
                //      ^ lastWhitespaceIndex
                //      [.....] copy this section to our tmp array
                ++lastWhitespaceIndex;
                tmpIndex = index - lastWhitespaceIndex;
                if (tmpIndex > 0) {
                    tmpLength = length - lastWhitespaceLength;
                    memcpy(&tmp, &line[lastWhitespaceIndex], tmpIndex);
                    index = lastWhitespaceIndex;
                }
            }
            line[index] = '\n'; // add newline
            line[index + 1] = '\0'; // add c-string null terminator
            printf("%s", line);
            index = 0; // reset index
            length = 0; // and length
            memset(&line, '\0', sizeof(line));
            if (tmpIndex > 0) {
                // copy tmp buffer back
                memcpy(&line, &tmp, tmpIndex);
                index = tmpIndex;
                length = tmpLength;
            }
            lastWhitespaceIndex = -1; // restore index after copy
            lastWhitespaceLength = -1; // and length

            if (isNewline(c)) {
                // consume newline characters because we already printed them
                c = getchar();
                if (c == EOF) {
                    return 0; // nothing left
                }
            }
            while (isWhitespace(c)) {
                // consume spaces on the start of a new line
                c = getchar();
                if (c == EOF) {
                    return 0; // nothing left
                }
            }
        }
        line[index++] = c;
    }
    // print whatever's in the buffer after the input has ended (EOF)
    printf("%s", line);
    return 0;
}
