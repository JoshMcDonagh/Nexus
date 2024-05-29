//
// Created by Joshua McDonagh on 13/05/2024.
//

#include <utility>

#include "../include/Agent.h"

Agent::Agent(std::string name, AgentAttributes  physiology, AgentAttributes  behaviour, const AgentResults& agentResults): physiology_m(std::move(
    physiology)), behaviour_m(std::move(behaviour)), agentResults_m(agentResults) {
    name_m = std::move(name);
}

AgentAttributes Agent::getPhysiology() {
    return physiology_m;
}

AgentAttributes Agent::getBehaviour() {
    return behaviour_m;
}

void Agent::runTick(Agents& agents) {
    agentResults_m.runForEvents();
    physiology_m.runTick(this, agents);
    behaviour_m.runTick(this, agents);
    agentResults_m.runForProperties();
}

