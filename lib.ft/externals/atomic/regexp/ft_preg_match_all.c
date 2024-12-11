/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preg_match_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:43:28 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:43:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <regex.h>

int preg_match(const char *pattern, const char *subject) {
    regex_t regex;
    int result;
    
    // Compile the regular expression
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        printf("Could not compile regex\n");
        return 0;
    }
    
    // Execute the regular expression match
    result = regexec(&regex, subject, 0, NULL, 0);
    regfree(&regex);
    
    if (result == 0) {
        return 1;  // Match found
    } else if (result == REG_NOMATCH) {
        return 0;  // No match
    } else {
        printf("Regex match failed\n");
        return -1;
    }
}

int main() {
    const char *pattern = "\\d+"; // Match digits
    const char *subject = "I have 100 apples.";

    int match = preg_match(pattern, subject);
    if (match) {
        printf("Match found\n");
    } else {
        printf("No match found\n");
    }

    return 0;
}
