#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    int numBoids = neighborhood.size();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood

    for (Boid* b : neighborhood)
    {
        averageVelocity += b->velocity;
    }

    averageVelocity /= numBoids;

    return Vector2::normalized(averageVelocity);
}