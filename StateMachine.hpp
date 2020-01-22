#ifndef STATEMACHINE_HPP_INCLUDED
#define STATEMACHINE_HPP_INCLUDED

#include <stack>

#include "State.hpp"

class StateMachine
{
    public:

    StateMachine(){};
    ~StateMachine(){};

    void pushState(State* stateRef, bool isChanging = true);
    void popState();
    void applyPendingChanges();

    State* getTopState();

    private:
    std::stack<State*> m_stateStack;

    //may break for simultaneous pending changes? //TODO changes vector
    State* m_newState;
    bool m_isChanging;
    bool m_isDeleting;
    bool m_isAdding;
};

#endif // STATEMACHINE_HPP_INCLUDED
