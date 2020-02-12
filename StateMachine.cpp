#include "StateMachine.hpp"

//StateMachine() {};
//~StateMachine() {};

void StateMachine::pushState(State* stateRef, bool isChanging)
{
    this->m_isAdding = true;
    this->m_isChanging = isChanging;

    this->m_newState = stateRef;
}

void StateMachine::popState()
{
    this->m_isDeleting = true;
}

void StateMachine::applyPendingChanges()
{
    if(this->m_isDeleting && !(this->m_stateStack.empty()))
    {
        this->m_stateStack.pop();

        if(!(this->m_stateStack.empty()))
        {
            //Resume previously stopped state
            this->m_stateStack.top()->resume();
        }

        this->m_isDeleting = false;
    }

    if(this->m_isAdding)
    {
        if(!(this-> m_stateStack.empty()))
        {
            if(this->m_isChanging)
            {
                this->m_stateStack.pop();
            }
            else
            {
                this->m_stateStack.top()->stop();
            }
        }
        this->m_stateStack.push(this->m_newState);
        this->m_stateStack.top()->init();
        this->m_isAdding = false;
    }
}

State* StateMachine::getTopState()
{
    return this->m_stateStack.top();
}
