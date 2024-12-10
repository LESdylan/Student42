/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bill_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:30:12 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 01:37:15 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

float split_bill(float bill, float tax, int tip)
{
    float whole_bill = bill + bill * (tax / 100); // Convert tax percentage to decimal
    float result = (whole_bill + whole_bill * ((float)tip / 100)) / 2; // Convert tip percentage to decimal
    return result;   
}

int main(void)
{
    int tip;
    float bill, tax;

    printf("Bill before tax and tip: ");
    scanf("%f", &bill);
    printf("Sale Tax Percent: ");
    scanf("%f", &tax);
    printf("Tip Percent: ");
    scanf("%d", &tip);

    printf("You will owe %.2f each\n", split_bill(bill, tax, tip));
    return 0;
}
