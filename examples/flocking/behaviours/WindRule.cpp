#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    // todo: add a wind force here
    // hint: use the windAngle variable
    Vector2 force = Vector2::zero();
    float boidVelocity = sqrt((boid->getVelocity().x, 2) + (boid->getVelocity().y, 2));
    force.x = boidVelocity * cos(windAngle);
    force.y = boidVelocity * sin(windAngle);
    return force;
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}