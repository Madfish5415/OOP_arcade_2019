/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus.hpp
*/

#ifndef OOP_ARCADE_2019_EVENTBUS_HPP
#define OOP_ARCADE_2019_EVENTBUS_HPP

#include <typeindex>
#include <map>
#include <vector>

#include "AEvent.hpp"

namespace engine {

namespace eventbus {

template <typename T, typename E>
using Callback = void (T::*)(E&);

/** \brief The class used to manage all the events that may occur during the execution */
class EventBus {
   private:
    class ICallbackHandler {
       public:
        virtual ~ICallbackHandler() = default;

       public:
        virtual void call(AEvent& event) = 0;
    };

    template <typename T, typename E>
    class CallbackHandler : public ICallbackHandler {
       private:
        T& _subscriber;
        Callback<T, E> _callback;

       public:
        /** \brief Constructor of the CallbackHandler class
         * \param subscriber A reference to the entity that subscribe to the event
         *  \param callback A pointer to a method to call when the event is encountered
         */
        CallbackHandler(T& subscriber, Callback<T, E> callback) : _subscriber(subscriber), _callback(callback) {};
        ~CallbackHandler() override = default;

       public:
        /** \brief Method used to call the method linked to an event when the event is encountered
        * \param event The event encountered
        */
        void call(AEvent& event) override
        {
            (_subscriber.*_callback)(dynamic_cast<E&>(event));
        };
    };

   private:
    std::map<std::type_index, std::vector<ICallbackHandler*>*> _subscribers {};

   public:
    EventBus();
    ~EventBus();

   public:
    /** \brief Link the subscriber to the method to call for the event
    * \param subscriber A reference to the entity that subscribe to the event
    *  \param callback A pointer to a method to call when the event is encountered
    */
    template <typename T, typename E>
    void subscribe(T& subscriber, Callback<T, E> callback){
        std::vector<ICallbackHandler*> *handlers = _subscribers[typeid(E)];

        if (handlers == nullptr) {
            handlers = new std::vector<ICallbackHandler*>();
            _subscribers[typeid(E)] = handlers;
        }

        handlers->push_back(new CallbackHandler<T, E>(subscriber, callback));
    };

    /** \brief Remove every subscribers and callbacks */
    void unsubscribe();

    /** \brief Add the event to the eventbus when it's encountered during the execution of the program
    * \param event A reference to the event encountered
    */
    template <typename E>
    void publish(E& event) {
        std::vector<ICallbackHandler*> *handlers = _subscribers[typeid(E)];

        if (handlers == nullptr)
            return;

        for (auto& handler : *handlers) {
            if (handler != nullptr) {
                handler->call(event);
            }
        }
    }
};

}  // namespace eventbus

}  // namespace engine

#endif  // OOP_ARCADE_2019_EVENTBUS_HPP
