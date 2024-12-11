/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_runoff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:41 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 02:06:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_VOTERS 100

typedef struct runoff
{
    char *name;     // Name of the candidate
    int vote;       // Number of votes
    int eliminated; // Boolean: 0 = not eliminated, 1 = eliminated
} candidate;

candidate candidates[MAX_CANDIDATES];
int voters_count;
int candidates_count;
int voted_candidates[MAX_VOTERS][MAX_CANDIDATES] = {0}; // Tracks votes per voter

// Function prototypes
int is_valid_vote(char *name);
void tabulate(void);
int vote(int voter, int rank, char *name);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./runoff [candidate1] [candidate2] ... [candidateN]\n");
        return 1;
    }

    candidates_count = argc - 1;
    if (candidates_count > MAX_CANDIDATES)
    {
        fprintf(stderr, "Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].name = malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        if (candidates[i].name == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 3;
        }
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].vote = 0;
        candidates[i].eliminated = 0;
    }

    // Getting number of voters
    printf("Please enter number of voters: ");
    scanf("%d", &voters_count);
    getchar();  // Clear the newline left by scanf

    char vote_input[50];

    // Input votes for each voter
    for (int i = 0; i < voters_count; i++)
    {
        printf("\nVoter %d\n", i + 1);
        for (int rank = 0; rank < candidates_count; rank++)
        {
            int valid_vote = 0;
            while (!valid_vote)
            {
                printf("Rank %d: ", rank + 1);
                fgets(vote_input, sizeof(vote_input), stdin);
                vote_input[strcspn(vote_input, "\n")] = '\0'; // Remove trailing newline

                // Check if the vote is valid
                if (is_valid_vote(vote_input))
                {
                    valid_vote = 1;
                    vote(i, rank, vote_input); // Record the vote
                }
                else
                {
                    printf("\e[31mInvalid vote. Please enter a valid candidate name.\e[0m\n");
                }
            }
        }
    }

    // Now we can count votes and determine a winner
    tabulate();

    // Check if there is a winner
    if (print_winner())
        printf("We have a winner!\n");
    else
    {
        // Continue elimination process
        int min = find_min();
        if (is_tie(min))
        {
            printf("There is a tie!\n");
        }
        else
        {
            eliminate(min);
        }
    }

    // Clean up allocated memory for candidates
    for (int i = 0; i < candidates_count; i++)
        free(candidates[i].name);

    return 0;
}

// Function to check if the vote is valid (candidate exists)
int is_valid_vote(char *name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
            return 1; // Valid vote
    }
    return 0; // Invalid vote
}

// Record a vote for a candidate
int vote(int voter, int rank, char *name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            voted_candidates[voter][rank] = i; // Store the candidate index in the voter’s rank
            return 1;
        }
    }
    return 0; // Vote could not be recorded
}

// Function to count the votes
void tabulate(void)
{
    // Reset vote count before tabulation
    for (int i = 0; i < candidates_count; i++)
        candidates[i].vote = 0;

    // Tabulate votes for each voter
    for (int i = 0; i < voters_count; i++)
    {
        for (int rank = 0; rank < candidates_count; rank++)
        {
            int candidate_index = voted_candidates[i][rank];
            if (candidates[candidate_index].eliminated == 0) // If the candidate is not eliminated
            {
                candidates[candidate_index].vote++;
                break; // Only count the first valid vote (highest preference)
            }
        }
    }
}

// Print the winner if there's one
int print_winner(void)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].vote > voters_count / 2) // Majority
            printf("Winner: %s\n", candidates[i].name);
            return 1; // Winner found
    }
    return 0; // No winner yet
}

// Find the minimum vote count among candidates
int find_min(void)
{
    int min = candidates[0].vote;
    for (int i = 1; i < candidates_count; i++)
    {
        if (candidates[i].vote < min && candidates[i].eliminated == 0)
            min = candidates[i].vote;
    }
    return min;
}

// Check if all remaining candidates have the same number of votes
int is_tie(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].eliminated == 0 && candidates[i].vote != min)
            return 0; // Not a tie
    }
    return 1; // It's a tie
}

// Eliminate the candidates with the minimum number of votes
void eliminate(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].vote == min)
        {
            candidates[i].eliminated = 1;
            printf("%s has been eliminated.\n", candidates[i].name);
        }
    }
}
\