#include <stdio.h>

// bayes calculator

// Sensitivity is the actual positive rate or the probability
// that a person tests positive for a disease when they do indeed have it.

// Specificity is the true negative rate or the probability that
// a person tests negative for a disease when they do not have the condition.

// Prevalence is the probability of having the disease.

// sensitivity 0.79
// specificity 0.95
// prevalence 0.04

// TODO explanation on how to calculate those values

// return bayes probabilty
double calculate_bayes(long double prior,
                       long double sensitivity,
                       long double specifity)
{
    long double bayes_prob = (prior * sensitivity) / ((prior * sensitivity) + ((1 - prior) * (1 - specifity)));
    return bayes_prob;
}

int main(void)
{
    long double prior = 0.04;
    long double sensitivity = 0.79;
    long double specifity = 0.95;

    printf("%f", calculate_bayes(prior, sensitivity, specifity));

    return 0;
}