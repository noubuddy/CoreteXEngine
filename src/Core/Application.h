#ifndef APPLICATION_CLASS_H
#define APPLICATION_CLASS_H

#include "Engine.h"
#include "Interfaces/IApplication.h"
#include <memory>

template <typename App>
class Application : public IApplication
{
public:
    Application();
    ~Application() override = default;

    static App GetInstance();
    
    bool Initialize() override;
    bool StartUp() override;
    bool ShutDown() override;

private:
    std::unique_ptr<App> m_application;
};

template <typename App>
Application<App>::Application() : m_application(std::make_unique<App>()) {}

template <typename App>
bool Application<App>::Initialize()
{
    return m_application->Initialize();
}

template <typename App>
bool Application<App>::StartUp()
{
    return m_application->StartUp();
}

template <typename App>
bool Application<App>::ShutDown()
{
    return m_application->ShutDown();
}

template <typename App>
App Application<App>::GetInstance()
{
    if (!m_application) {
        m_application = std::make_unique<App>();
        m_application->Initialize();
    }
    
    return m_application;
}

#endif