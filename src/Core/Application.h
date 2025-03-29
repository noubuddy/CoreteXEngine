#ifndef APPLICATION_CLASS_H
#define APPLICATION_CLASS_H

#include "Engine.h"
#include "Interfaces/IApplication.h"

template <typename App>
class Application : public IApplication
{
public:
    Application() : m_application(std::make_unique<App>()) {}
    
    ~Application() override = default;

    static App GetInstance()
    {
        if (!m_application) {
            m_application = std::make_unique<App>();
            m_application->Initialize();
        }
    
        return m_application;
    }
    
    bool Initialize() override
    {
        return m_application->Initialize();
    }
    
    bool StartUp() override
    {
        return m_application->StartUp();
    }
    
    bool ShutDown() override
    {
        return m_application->ShutDown();
    }

private:
    std::unique_ptr<App> m_application;
};
#endif