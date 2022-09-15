#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 separatingForce = Vector2::zero();
    float separationMagnifier = 0;

    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;
        int countCloseFlockmates = 0;

        for (Boid* b : neighborhood)
        {
            float dist = Vector2::getDistance(b->transform.position, boid->transform.position);
            if (dist < desiredDistance)
            {
                separatingForce += b->transform.position -boid->transform.position;
                countCloseFlockmates++;
            }
        }
        if (countCloseFlockmates > 0)
        {
            separatingForce /= countCloseFlockmates;
        }

        /* Vector2 closestNeighbor = Vector2::zero();
        for (Boid* b : neighborhood)
        {
            if (closestNeighbor == Vector2::zero())
            {
                closestNeighbor = b->transform.position;
            } else
            {
                if (Vector2::getDistance(boid->transform.position, b->transform.position) <
                        Vector2::getDistance(boid->transform.position, closestNeighbor))
                {
                    closestNeighbor = b->transform.position;
                }
            }
        }
        separationMagnifier = Vector2::getDistance(boid->transform.position, closestNeighbor); */
    }

    //separationMagnifier = desiredDistance - separationMagnifier;

    separatingForce *= -1;
    separatingForce = Vector2::normalized(separatingForce);

    return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
