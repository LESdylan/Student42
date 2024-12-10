/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preg_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:43:52 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:43:53 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <regex.h>
#include <string.h>

void preg_split(const char *pattern, const char *subject) {
    regex_t regex;
    regmatch_t match;
    int start = 0;
    int i = 0;
    char result[10][100];  // To store split parts

    // Compile the regular expression
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        printf("Could not compile regex\n");
        return;
    }

    while (regexec(&regex, subject + start, 1, &match, 0) == 0) {
        strncpy(result[i], subject + start, match.rm_so);
        result[i][match.rm_so] = '\0';  // Null terminate the string
        i++;
        start += match.rm_eo;  // Move the start position
    }

    // Print the split parts
    for (int j = 0; j < i; j++) {
        printf("Part %d: %s\n", j + 1, result[j]);
    }

    regfree(&regex);
}

int main() {
    const char *pattern = "\\s+";  // Match spaces
    const char *subject = "I have 100 apples and 200 oranges.";

    preg_split(pattern, subject);

    return 0;
}
