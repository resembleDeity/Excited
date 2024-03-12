#pragma once

#include "Excited/Core.h"
#include "Excited/Events/Event.h"



namespace Excited
{
    class EXCITED_API KLayer
    {
    public:

        KLayer(const std::string& Name = "Layer");
        virtual ~KLayer();

        virtual void OnAttach() { }
        virtual void OnDetach() { }
        virtual void OnUpdate() { }
        virtual void OnEvent(KEvent& Event) { }

        inline const std::string& GetName() const { return DebugName; }

    protected:

        std::string DebugName;
    };
}

