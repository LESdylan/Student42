/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runoff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:16 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/25 17:09:38 by dyl-syzygy       ###   ########.fr       */
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
int voted_candidates[MAX_VOTERS][MAX_CANDIDATES] = {0};
int voters_count;
int candidates_count;

int min_value(int arr[], int n);
void tabulates(void);
int vote(int voter, int rank, char *name);
int print_winner(void);
int find_min(void);
void eliminate(int min);
int is_valid_vote(char *name);
int is_tie(int min);

/** 
     * lots of logical and syntax error implementation
     * ! check the style of implementation
     * !try to break the code
     * !check for performances if there are any better ways to do things
     *  
     * * we assume that the candidates doesn't have the same name 
     * to test the code
     * // An election with any number of candidate (up to the `max` of 9)
     * // Voting for a candidate by name
     * // Invalid votes for candidates who are not on the ballot
     * ? Printing the winner of the election if there is only one
     * ? Not eliminating anyone in the case of a tie betweeen all remaining candidates
     * ?the implementation doesn't check if input of users contain only alpha characters
     * ?need to implement a function that updates automatically the number of votes that a candidate have.
     * ?check if voters cannot vote several times for the same candidate
    */
   
int main(int argc, char *argv[])
{
    //variables declarations
    int i,rank;
    //initialization of variables
    candidates_count = argc - 1;
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./runoff [candidate1] [candidate2] ... [candidateN]\n");
        return 1;
    }

    

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
    
    i=0;
    puts("\ninputs of users: ");
    printf("\e[35mUser %d\n\e[0m", i++);
    
    printf("Please enter qty of voters : ");
    scanf("%d", &voters_count);
    getchar();
    
    i = -1;
    char vote_input[50];

    //!error of logic here, doesn't take into account if name is repeated
    while(++i < voters_count)
    {
        printf("\nVoter %d\n", i);
        rank = -1;
        while(++rank < candidates_count)
        {
            printf("rank %d: ", rank + 1);
            fgets(vote_input,sizeof(vote_input), stdin);
            vote_input[strcspn(vote_input, "\n")] = '\0';
            while(!is_valid_vote(vote_input))
            {
                fprintf(stderr, "\e[31m Not valid name, please enter a valid name :\e[0m ");
                fgets(vote_input, sizeof(vote_input), stdin);
                vote_input[strcspn(vote_input, "\n")] = '\0';   
            }
            
        }
    }
    return 0;
}


 /**
    * @brief The function should update the number of `votes` each candidates has at his stage in the runoff
    * @attention at each stage in the runoff, every voter effectively votes for their top-preferres candidate who has not already been eliminated
    * voters_count stores the number oof voters in the election and that, for each voter in our election, we want to count one ballot.
    */
    void tabulates(void)
    {
        // Remet les votes à zéro au début de chaque tour
        for (int i = 0; i < candidates_count; i++)
        {
            candidates[i].vote = 0;
        }
    
        // Parcourt tous les votants pour ajouter des votes à leurs choix préférés
        for (int i = 0; i < voters_count; i++)
        {
            // Trouver le premier candidat non éliminé pour ce votant
            for (int rank = 0; rank < candidates_count; rank++)
            {
                int candidate_index = vote(i, rank, "name");  // Cette fonction devra mettre à jour les préférences
                if (candidate_index != -1 && candidates[candidate_index].eliminated == 0)
                {
                    candidates[candidate_index].vote++;
                    break;  // Stoppe dès qu'on trouve un candidat valide
                }
            }
        }
    }



/**
 * @param voter id of the voter
 * @param rank  rank of vote
 * @param name  name of candidate
 * @return `0|1` 0 if preference is successfully recorded | 0 otherwise.
 * @note 
 * if `name` is a match for the name  of a valid candidate, then you should update the globale preferences array to indicate that the `voter`
 * has that `candidate` as their `rank` preference. 
 * `0` is the first preference, `1` is the second preference, etc..
 * @example
 * !if the name is not one of the candidate, vote can't be processed
 */
int voted_candidates[MAX_VOTERS][MAX_CANDIDATES] = {0}; // tableau pour chaque électeur et ses votes

int vote(int voter, int rank, char *name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0 && candidates[i].eliminated == 0)
        {
            if (voted_candidates[voter][i] == 0)  // Vérifier si ce candidat a déjà été voté par cet électeur
            {
                preferences[voter][rank] = i;  // Stocke le vote
                voted_candidates[voter][i] = 1;  // Marque ce candidat comme voté
                return 1;
            }
            else
            {
                printf("Vous ne pouvez pas voter deux fois pour le même candidat !\n");
                return 0;
            }
        }
    }
    return 0;  // Si le nom n'est pas valide ou le candidat est éliminé
}

//*print the min_values' index to manipulate the list and declare a loser

//? RETRIEVE INFORMATION ABOUT THE VOTE

/**
 * @param void
 * @return 1|0 print the winner if any candidate has at least more than half of the vote | if nobody has won the elections yet 
 */
int print_winner(void)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].vote > voters_count / 2)
        {
            printf("Le gagnant est %s avec %d votes !\n", candidates[i].name, candidates[i].vote);
            return 1;  // Un gagnant est trouvé
        }
    }
    return 0;  // Aucun gagnant
}


/**
 * @param void
 * @return the minimum vote total for any candidate who is still in the election
 */
int find_min(void)
{
    int min_votes = -1;  // Initialiser avec une valeur arbitraire, car les votes ne peuvent pas être négatifs.

    // Parcours de tous les candidats
    for (int i = 0; i < candidates_count; i++)
    {
        // On ignore les candidats éliminés
        if (candidates[i].eliminated == 0)
        {
            // Si c'est le premier candidat ou que ce candidat a moins de votes
            if (min_votes == -1 || candidates[i].vote < min_votes)
            {
                min_votes = candidates[i].vote;
            }
        }
    }
    
    return min_votes;
}


/**
 * The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
 * @return The function should return true if every candidate remaining in the election has the same number of votes, and should return false otherwise.
 * @note
 * Recall that a tie happens if every candidate still in the election has the same number of votes. 
 * Note, too, that the is_tie function takes an argument min, which is the smallest number of votes any candidate currently has.
 * How might you use min to determine if the election is a tie (or, conversely, not a tie)?
 */
int min_value(int arr[], int n)
{
    int min_value = arr[0];
    int min_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

//*return true if the election is tied between all candidates, false otherwise

//?MODIFY THE LISTS
/**
 * @note
 * @param min the minimm number of votes that anyone in the election currently has.
 * @return eliminate the candidate (or candidates) who have `min` number of votes
 */
void eliminate(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].vote == min)
        {
            candidates[i].eliminated = 1;  // Marque ce candidat comme éliminé
        }
    }
}
//*eliminate the candidate (or candidates) in last place



//? MY CHECKINGS
int is_valid_vote(char *name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            return 1; // Le vote est valide
        }
    }
    return 0; // Le vote est invalide
}

int is_tie(int min)
{
    // On parcourt tous les candidats
    for (int i = 0; i < candidates_count; i++)
    {
        // Si le candidat n'est pas éliminé et n'a pas exactement `min` votes
        if (candidates[i].eliminated == 0 && candidates[i].vote != min)
        {
            return 0;  // Ce n'est pas une égalité
        }
    }
    return 1;  // Tous les candidats restants ont le même nombre de votes
}
