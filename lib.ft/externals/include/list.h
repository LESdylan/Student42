#ifndef FT_LIST_H
#define FT_LIST_H

// Define the linked list structure
typedef struct s_list
{
    void            *content;   // The data contained in the link. void* enables holding any type of data.
    struct s_list   *next;      // The address of the next link, or NULL if it's the last element.
}                   t_list;

// Linked list functions
t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **alst, t_list *new);
t_list  *ft_lstlast(t_list *lst);
int     ft_lstsize(t_list *lst);
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));

#endif