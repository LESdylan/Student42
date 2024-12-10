/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preg_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:43:38 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:43:42 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <regex.h>

void preg_replace(const char *pattern, const char *replacement, const char *subject) {
    regex_t regex;
    regmatch_t match;
    char result[1024];  // To store the result
    int start = 0;
    int replaced = 0;

    // Compile the regular expression
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        printf("Could not compile regex\n");
        return;
    }

    // Perform the replacement
    while (regexec(&regex, subject + start, 1, &match, 0) == 0) {
        // Copy the part before the match
        strncat(result, subject + start, match.rm_so);
        // Append the replacement string
        strcat(result, replacement);
        // Move the start position to the end of the match
        start += match.rm_eo;
        replaced = 1;
    }

    // Append the remainder of the string after the last match
    strcat(result, subject + start);

    if (replaced) {
        printf("Replaced string: %s\n", result);
    } else {
        printf("No replacements made.\n");
    }

    regfree(&regex);
}

int main() {
    const char *pattern = "\\d+"; // Match digits
    const char *replacement = "X"; // Replace with 'X'
    const char *subject = "I have 100 apples and 200 oranges.";

    preg_replace(pattern, replacement, subject);

    return 0;
}
