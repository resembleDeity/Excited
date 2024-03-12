#pragma once

#include "Excited/Core.h"
#include "Layer.h"

#include <vector>



namespace Excited
{
    class EXCITED_API KLayerStack
    {
    public:

        KLayerStack();
        ~KLayerStack();

        void PushLayer(KLayer* Layer);
        void PushOverlay(KLayer* Overlay);
        void PopLayer(KLayer* Layer);
        void PopOverlay(KLayer* Overlay);

        std::vector<KLayer*>::iterator begin() { return Layers.begin(); }
        std::vector<KLayer*>::iterator end() { return Layers.end(); }

    private:

        std::vector<KLayer*> Layers;
        std::vector<KLayer*>::iterator LayerInsert;
    };    
}
