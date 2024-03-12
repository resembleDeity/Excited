#include "Excitedpch.h"
#include "LayerStack.h"


namespace Excited
{
    KLayerStack::KLayerStack()
    {
        LayerInsert = Layers.begin();
    }

    KLayerStack::~KLayerStack()
    {
        for (KLayer* Layer : Layers)
        {
            delete Layer;
        }
    }

    void KLayerStack::PushLayer(KLayer* Layer)
    {
        LayerInsert = Layers.emplace(LayerInsert, Layer);
    }

    void KLayerStack::PushOverlay(KLayer* Overlay)
    {
        Layers.emplace_back(Overlay);
    }

    void KLayerStack::PopLayer(KLayer* Layer)
    {
        auto It = std::find(Layers.begin(), Layers.end(), Layer);
        if (It != Layers.end())
        {
            Layers.erase(It);
            LayerInsert--;
            
        }
    }

    void KLayerStack::PopOverlay(KLayer* Overlay)
    {
        auto It = std::find(Layers.begin(), Layers.end(), Overlay);
        if (It != Layers.end())
        {
            Layers.erase(It);
        }
    }
}
