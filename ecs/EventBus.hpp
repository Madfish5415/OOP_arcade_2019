/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus.hpp
*/

#ifndef OOP_ARCADE_2019_EVENTBUS_HPP
#define OOP_ARCADE_2019_EVENTBUS_HPP

#include "Event.hpp"

typedef std::list<AFunctionHandler*> HandlerList;

namespace ecs {

class AFunctionHandler {
   private:
    virtual void call(Event* event) = 0;

   public:
    void exec(Event* event) {
        call(evnt);
    };
}

template <class T, class EventType>
class FunctionHandler : public AFunctionHandler {
   public:
    typedef void (T::*MemberFunction)(EventType*);

   private:
    T* _instance;
    MemberFunction _memberFunction;

   public:
    FunctionHandler(T * instance, MemberFunction memberFunction) : _instance{ instance }, _memberFunction{ memberFunction } {};

    void call(Event * event) override {
        (instance->*memberFunction)(static_cast<EventType*>(event));
    }
}

typedef std::list<AFunctionHandler*> HandlerList

class EventBus {
   private:
    std::map<std::type_index, HandlerList*> _subscribers;

   public:
    template<class T, class EventType>
    void subscribe(T * instance, void (T::*memberFunction)(EventType *)) {
        HandlerList * handlers = _subscribers[typeid(EventType)];

        if (handlers == nullptr) {
            handlers = new HandlerList();
            _subscribers[typeid(EventType)] = handlers;
        }

        handlers->push_back(new MemberFunctionHandler<T, EventType>(instance, memberFunction));
    }

    template<typename EventType>
    void publish(EventType *event) {
        HandlerList *handlers = _subscribers[typeid(EventType)];

        if (handlers == nullptr) {
            return;
        }

        for (auto& handler : *handlers) {
            if (handler != nullptr) {
                handler->exec(event);
            }
        }
    }
}

}  // namespace ecs

#endif  // OOP_ARCADE_2019_EVENTBUS_HPP
