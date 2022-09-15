#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    if (!neighborhood.empty()) {
        int numBoids = neighborhood.size();
        Vector2 averagePosition = Vector2::zero();
        for (Boid *b: neighborhood) {
            averagePosition += b->transform.position;
        }
        averagePosition += boid->transform.position;
        averagePosition /= numBoids + 1;

        cohesionForce = averagePosition - boid->transform.position;
    }

    return Vector2::normalized(cohesionForce);
}