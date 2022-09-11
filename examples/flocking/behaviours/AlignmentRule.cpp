#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    int numBoids = neighborhood.size();

    for (Boid* b : neighborhood)
    {
        averageVelocity += b->velocity;
    }

    averageVelocity += boid->velocity;

    averageVelocity /= numBoids + 1;

    return Vector2::normalized(averageVelocity);
}