#pragma once
#include "CoreExports.h"
#include "IObserver.h"
#include "CoreSession.h"

class CORE_API Observer : public IObserver 
{
   
    public:

        Observer(CoreSession& coreSesssion, EventTypes eventType) ;
        ~Observer() override;
        void Update(const std::string& message_from_subject) override;
        void Update(const std::string& message_from_subject, void * data) override;
        void RemoveMeFromTheList();
        void PrintInfo();
        void PrintInfo(void* data);
        bool UpdateOnEventType(EventTypes eventType);

    private:
        std::string message_from_subject_;
        CoreSession& coreSession_;
        static int static_number_;
        int number_;
        EventTypes m_eventType;
    
};

