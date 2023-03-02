#pragma once
#include "CoreExports.h"
#include "ISubject.h"
#include <list>
#include <iostream>

class Observer;

class CORE_API CoreSession : ISubject
{
	public:
        static CoreSession& GetInstance();

        CoreSession(CoreSession const&) = delete;
        void operator=(CoreSession const&) = delete;


        ~CoreSession() override;

        /**
         * The subscription management methods.
         */
        void Attach(IObserver* observer) override;
        void Detach(IObserver* observer) override;
        void NotifyAll() override;
        void Notify(IObserver::EventTypes eventType) override;
        void Notify(IObserver::EventTypes eventType, void* data) override;

        void CreateMessage(IObserver::EventTypes eventType);
        void CreateMessage(IObserver::EventTypes eventType, void * data);
        void CreateMessage(std::string message = "Empty");
        void HowManyObserver();

        void ClearObservers();

        void SetupDefaultObservers();

private:
    std::list<IObserver*> m_listObserver;
    std::string m_message;
    CoreSession();
    Observer* m_observerForSavePart; 
    Observer* m_observerForClosePart;
    Observer* m_observerForOpenPart;

};

