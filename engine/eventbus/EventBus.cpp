/*
** EPITECH PROJECT, 2020
** engine
** File description:
** EventBus.cpp
*/

#include "EventBus.hpp"

using namespace engine;
using namespace eventbus;

EventBus::EventBus() = default;

EventBus::~EventBus() { this->unsubscribe(); }

void EventBus::unsubscribe() {
    for (auto& i : _subscribers) {
        if (i.second != nullptr)
            i.second->clear();
    }
    _subscribers.clear();
}